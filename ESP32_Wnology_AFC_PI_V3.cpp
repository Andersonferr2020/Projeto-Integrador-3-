#include "DHT.h"
#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <WebServer.h>  // Biblioteca para a página HTML

// Configurações da rede Wi-Fi
const char* ssid = "AFC";
const char* password = "Andersonferr";

// Configuração do MQTT Broker (Wegnology)
const char* mqtt_server = "broker.app.wnology.io";
const char* deviceID = "67bf1a3709beb43d0fda5";
const char* accesskey = "2460b96e-2415-452f-aba1-59e38d9c0";
const char* secretkey = "37c16eae4146fe9b5be55ed3f3d125857b9569ff24672b7318429db0664";
const char* state_topic = "wnology/67bf1a3709beb43d0fda5/state";
const char* command_topic = "wnology/67bf1a3709b43d0fda5/command";
//*****************************************************************************************
const char* comando;

// Definição de pinos
#define AnalogPin 34
#define botaoLigado 4
#define botaoDesliga 5
#define FeedBack 2
#define LigaMotor 26
#define saida1 25 // LED indica Motor Ligado
#define saida2 26 // LED indica Motor Desligado
#define saida3 27 // LED indica FALHA
#define DHTPIN 13
#define DHTTYPE DHT22

// Instâncias
DHT dht(DHTPIN, DHTTYPE);
WiFiClient espClient;
PubSubClient client(espClient);
DynamicJsonDocument doc(1024);
LiquidCrystal_I2C lcd(0x27, 16, 2);
WebServer server(80);  // Servidor web local

// Variáveis globais
bool Motor = 0;
char json[170];

float temp,hum,oldtemp;//Variáveis para armazenam o valor da humidade como um número float
int intHum, old_intHum;//Variáveis para armazenam o valor da humidade como um número inteiro

//Variável para monitorar o estado da Câmara de resfriamento
int EstadoCamara = 0;

// Função para conectar ao Wi-Fi
void setup_wifi() {
  Serial.print("Conectando ao Wi-Fi: ");
  Serial.println(ssid);

  lcd.setCursor(0, 0);
  lcd.print("Conectando WiFi");
  lcd.setCursor(2, 1);
  lcd.print( ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");

    lcd.setCursor(0, 7);
    lcd.print(".");
  }

  Serial.println("\nWiFi conectado!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WiFi conectado");
  delay(1000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(WiFi.localIP());

  lcd.setCursor(0, 1);
  lcd.print(WiFi.macAddress());
  delay(1000);
}

// Callback para receber comandos via MQTT
void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Mensagem recebida no tópico: ");
  Serial.println(topic);

  String messageTemp;
  for (int i = 0; i < length; i++) {
    messageTemp += (char)message[i];
  }

  Serial.print("Conteúdo: ");
  Serial.println(messageTemp);

  deserializeJson(doc, messageTemp);
  comando=doc["name"];
  Motor = doc["payload"]["liga"];

  //Motor=doc["payload"];
  Serial.print("Comando recebido:");
  Serial.println(comando);
  Serial.print("Pacote recebido:");
  //Serial.println(setMotor);
  Serial.println(Motor);

//----------------------------------------------------INICIO: LOGICA DE ACIONAMENTO REMOTO ---------------------------------------------------------------------------------------
  if (String(topic) == command_topic) 
  {
    Serial.print("Changing output to ");
  
      // EstadoCamara = 1;// Varíável de envio de dados de estado para a plataforma IoT
     
  }
      //-----------------------------------Fim da Logica de Acionamento Remoto ----------------------------------------------------------------------------------------------
  
}

// Função para publicar estado do ESP32 na Wegnology
void publish_state() {
  temp = dht.readTemperature();
  hum = dht.readHumidity();

  intHum = (int) hum;//Operador de conversão cast, para converter de floast para inteiro

  //Atualiza o valor da temperatura e da humidade no display, apenas se houver mudança em algum deles
  //A lógica empregada evita a atualização do display sem que haja mudança na leitura do sensor
    if((temp != oldtemp) or (intHum != old_intHum))
    {
      lcd.clear();//Limpa os dados do display
      
      if(isnan(temp) || isnan(hum))
      {
        lcd.setCursor(0,0);//posiciona o cursor
        lcd.print("FALHA NO SENSOR");//Envia mensagem de Falha
                
        lcd.setCursor(0,1);
        lcd.print("ERRO NUMERO: 111");//Texto que antecede a informação no display
        
        temp = 111;
        intHum = 111;
        hum = 111;      
      }

      else
      { 
        lcd.setCursor(0,0);//posiciona o cursor
        lcd.print("TEMPERAT. ");//Texto que antecede a informação no display
        lcd.setCursor(10,0);
        lcd.print(temp,1);//Envia um float(valor da temperatura) para o display com uma casa decimal
        lcd.setCursor(15,0);//Posiciona o cursor
        lcd.print("C");
        lcd.setCursor(2,1);
        lcd.print("UMIDADE");//Texto que antecede a informação no display
        lcd.setCursor(11,1);
        lcd.print(intHum);//Envia para o display o valor da humidade
        lcd.setCursor(13,1);
        lcd.print("%");          
      }
      
      delay(100);
      oldtemp=temp;//Atualiza o valor da leitura anterior
      old_intHum=intHum;//Atualiza o valor da leitura anterior

    }

    // Ler o valor analógico do pino
    int analogValue = (analogRead(AnalogPin)*100)/4095;
  
    // Imprimir o valor lido no monitor serial
    Serial.print("Valor analógico lido no pino ");
    Serial.print(AnalogPin);
    Serial.print(": ");
    Serial.println(analogValue);

    // Convert the value to a char array
    char tempString[8];
    dtostrf(temp, 1, 2, tempString);
    Serial.print("Temperature: ");
    Serial.println(tempString);
    
     
    // Convert the value to a char array
    char humString[8];
    dtostrf(hum, 1, 2, humString);
    Serial.print("Humidity: " );
    Serial.println(humString);
    

    char EstadoCamaraString[8];
    dtostrf(EstadoCamara, 1, 2, EstadoCamaraString);
    Serial.print("EstadoCamara: ");
    Serial.println(EstadoCamaraString);
    Serial.println(comando);
    
    Serial.println(Motor);


  StaticJsonDocument<200> state;
  state["Temp_Interna"] = temp;
  state["Temp_Externa"] = temp;
  state["Umidade_Interna"] = hum;
  state["Umidade_Externa"] = hum;
  state["Estado_Camara"] = EstadoCamara;
  state["Analog_State"] = 0;
  
  serializeJson(state, json);
  client.publish(state_topic, json);
}

// Página HTML para monitoramento remoto
void handleRoot() {
  String html = "<html>\
  <head><title>Monitor ESP32</title></head>\
  <body>\
  <h2>Status do ESP32</h2>\
  <p>Temperatura: " + String(temp) + "°C</p>\
  <p>Umidade: " + String(hum) + "%</p>\
  <p>Motor: " + String((Motor) ? "Ligado" : "Desligado") + "</p>\
  <form action='/reset' method='POST'>\
    <button type='submit'>Reset ESP32</button>\
  </form>\
  </body>\
  </html>";
  server.send(200, "text/html", html);
}

// Função para reset remoto
void handleReset() {
  server.send(200, "text/plain", "ESP32 será reiniciado!");
  delay(1000);
  ESP.restart();
}

// Setup inicial do ESP32
void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();
  lcd.clear();

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  pinMode(botaoLigado, INPUT);
  pinMode(botaoDesliga, INPUT);
  pinMode(FeedBack, INPUT);
  pinMode(saida1, OUTPUT);
  pinMode(saida2, OUTPUT);
  pinMode(saida3, OUTPUT);
  pinMode(LigaMotor, OUTPUT);
  pinMode(AnalogPin, INPUT);
  dht.begin();

  // Configuração do servidor web
  server.on("/", handleRoot);
  server.on("/reset", HTTP_POST, handleReset);
  server.begin();
}

// Loop principal
void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  server.handleClient();

  long now = millis();
  static long lastMsg = 0;
  if (now - lastMsg > 5000) {
    lastMsg = now;
    publish_state();
  }
}

// Função para reconectar ao MQTT
void reconnect() {
  while (!client.connected()) {
    Serial.print("Tentando conexão MQTT...");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("CONECTANDO MQTT ...");

    if (client.connect(deviceID, accesskey, secretkey)) {
      Serial.println("Conectado!");
      client.subscribe(command_topic);

      lcd.clear();
      lcd.setCursor(2, 1);
      lcd.print("CONECTADO");

    } else {
      Serial.print("Falha (rc=");
      Serial.print(client.state());
      Serial.println("), tentando novamente em 3s...");

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("CONECÇÃO FALHOU");

      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("NOVA TENTATIVA...");
      lcd.setCursor(1, 1);
      lcd.print("EM 3 SEGUNDOS...");
      
      delay(3000);


    }
  }
}
