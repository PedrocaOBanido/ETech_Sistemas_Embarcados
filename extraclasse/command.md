Olá. Tudo bem? Seguem as infomações da atividade extraclasse.

Aviso: 

    Assim como combinamos essa atividade valerá como presença para o dia 14/11/24;
    A entrega deverá ser feita até o dia 25/11/24;
    Em caso de dúvidas, entrem em contato comigo;
    Etapas da atividade:
    Acesse o simulador online Wokwi (https://wokwi.com/) e crie um projeto utilizando ESP32-C3. Você deve criar o circuito (imagem em anexo) utilizando o LED RGB, com o pino comum sendo do tipo cátodo, o DIP Switch de 8 chaves e resistores de 220 Ohms. 
    No editor de código online, monte a seguinte lógica para cada acionamento das chaves:
        /Se a chave 1 estiver acionada e as demais desligadas, o ESP32 deverá ligar o LED na cor vermelho;
        /Se a chave 2 estiver acionada e as demais desligadas,
        o ESP32 deverá ligar o LED na cor azul;
        Se a chave 3 estiver acionada e as demais desligadas, o ESP32 deverá ligar o LED na cor verde;
        Se a chave 4 estiver  acionada e as demais desligadas, o ESP32 deverá ligar o LED na cor vermelho e azul;
        Se a chave 5 estiver acionada e as demais desligadas, o ESP32 deverá ligar o LED na cor azul e verde;
        Se a chave 6  estiver acionada e as demais desligadas, o ESP32 deverá ligar o LED na cor verde e vermelho;
        Se a chave 7  estiver acionada e as demais desligadas, o ESP32 deverá ligar o LED na cor vermelho, verde e azul;
        Se a chave 8 estiver acionada, o ESP32 deverá bloquear o acionamento do LED (manter o LED desligado);

Observações e dicas: 

    Utilize o modo INPUT_PULLUP para os pinos os quais servirão de entrada para as chaves do DIP Switch;
    Não se esqueça de declarar todos os pinos de entrada e saída;
    Não precisa usar a serial;
    Em alguns casos o simulador online apresenta lentidão para compilar o código. Eu aconselho parar e rodar novamente a compilação caso esteja demorando (tempo maior que 3 minutos);

A entrega deverá ser o projeto em formato .zip. Basta fazer o download do projeto (Download Project ZIP) e o upload aqui na zona de entrega da atividade.

Para quaisquer dúvidas, fico à disposição.