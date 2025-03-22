#Importando bibliotecas
import pandas as pd

# Caminho do arquivo no diretório de trabalho atual
df = pd.read_csv('monitoramento-tabela_de_dados (1).csv') #se mudar o arquivo, indicar o caminho aqui.

# Exibir as primeiras linhas do DataFrame
print(df.head())



# Caminho do arquivo no diretório de trabalho atual
df = pd.read_csv('monitoramento-tabela_de_dados (1).csv')

# Análise 'Temp_Interna' para os valores menores que -18°C
temp_interna_valores_menores = df[df['Temp_Interna'] < -18]

# Exibir  'Temp_Interna' menores que -18°C
print(temp_interna_valores_menores)

# Calcular o número de ocorrências menores que -18°C
numero_ocorrencia = len(temp_interna_valores_menores)
print(f"\nNúmero de ocorrências em que Temp_Interna está abaixo -18°C: {numero_ocorrencia}")



#Exemplo de histrograma
plt.figure(figsize=(10,6))
plt.hist(df['Temp_Interna'], bins=20)
plt.xlabel('Temperatura Interna (°C)')
plt.ylabel('Frequência')
plt.title('Histograma da Temperatura Interna')
plt.axvline(x = -18, color='red', linestyle='--', label='-18°C') 
plt.legend()
plt.show()
