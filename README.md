# Projeto-Integrador-3-
Sistema de Monitoramento IoT para Câmaras de Refrigeração

📌 Descrição do Projeto
Este projeto visa desenvolver um sistema de monitoramento IoT para câmaras de refrigeração de uma empresa. 
O sistema tem como objetivo monitorar a temperatura e a umidade em tempo real, garantindo a conservação adequada dos alimentos e prevenindo prejuízos financeiros decorrentes de falhas na refrigeração.

Além disso, o sistema enviará alertas automáticos via WhatsApp, SMS ou e-mail em caso de variações críticas de temperatura, permitindo uma ação rápida para evitar danos aos produtos armazenados.

🎯 Objetivo
Desenvolver um sistema de monitoramento IoT para acompanhar temperatura e umidade das câmaras de refrigeração da empresa.
Notificar automaticamente a proprietária e equipe responsável sobre anomalias na temperatura e possíveis falhas nos equipamentos.
Armazenar dados históricos para análise e conformidade com regulamentações sanitárias.
Melhorar a gestão da cadeia de frio e reduzir desperdícios de alimentos.

🚀 Funcionalidades:
✅ Monitoramento em tempo real de temperatura e umidade.

✅ Envio de alertas automáticos via WhatsApp, SMS ou e-mail.

✅ Armazenamento de dados históricos para auditoria e análise. 

✅ Interface acessível via web e mobile. 

✅ Relatórios sobre a variação de temperatura ao longo do tempo. 


🛠 Tecnologias Utilizadas:
Hardware: ESP32, sensores de temperatura e umidade (DHT22).
Back-end: Python, banco de dados PostgreSQL.
Front-end: React.js.
Comunicação: MQTT para integração IoT.
Notificações: Twilio API /SMTP para envio de e-mails.
Hospedagem: Azure.

🏢 Contexto e Justificativa
A empresa armazena diversos produtos congelados e refrigerados, sendo essencial o controle rigoroso da temperatura para evitar perdas e atender às normas sanitárias.

A empresa já enfrentou falhas na refrigeração que causaram prejuízos financeiros e desperdício de alimentos. A implementação deste sistema ajudará a prevenir esses problemas, garantindo a segurança alimentar e a conformidade legal.

📅 Cronograma de Desenvolvimento
Fase	Descrição	Período
Planejamento	Levantamento de requisitos e definição de escopo	Quinzena 1 e 2
Desenvolvimento	Implementação do hardware e software inicial	Quinzena 3 e 4
Testes e ajustes	Testes no ambiente real e otimizações	Quinzena 5 e 6
Documentação e entrega	Finalização do relatório e apresentação	Quinzena 7
👥 Equipe de Desenvolvimento
Cyntia
Anderson
Taila
Vinícius

📌 Como Executar o Projeto
🔧 Pré-requisitos
Antes de começar, você precisará ter instalado em sua máquina:

Python 3.x
Node.js
Docker (opcional)
🔥 Passos para execução
Clone o repositório:

sh
Copiar
Editar
git clone https://github.com/seu-usuario/seu-repositorio.git
cd seu-repositorio
Instale as dependências:

sh
Copiar
Editar
pip install -r backend/requirements.txt
cd frontend
npm install
Inicie o servidor backend:

sh
Copiar
Editar
python backend/app.py
Inicie o frontend:

sh
Copiar
Editar
cd frontend
npm run dev

Acesse no navegador:

arduino
Copiar
Editar
http://localhost:3000
📌 Contribuição
Ficamos felizes com contribuições para melhorias no projeto! Para contribuir:

Faça um fork do repositório.
Crie uma branch para sua feature (git checkout -b minha-feature).
Faça um commit das suas alterações (git commit -m 'Adicionando minha feature').
Envie para o repositório (git push origin minha-feature).
Abra um Pull Request.
📜 Licença
Este projeto está sob a licença MIT.
