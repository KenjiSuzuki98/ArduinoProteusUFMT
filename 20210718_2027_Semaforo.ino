/*  Proj.:  Semáforo
 *  Autor:  Kenji Marcos Suzuki
 *  Data:   18/07/2021 20:27
 */

//Definição de Pinos
#define ledR 7                //led definida como pino 7
#define ledY 6                //led definida como pino 6
#define ledG 5                //led definida como pino 5

//Variáveis Temporais
unsigned long int tR=0;       //variável que armazena a contagem da função millis()
unsigned long int tY=0;       //variável que armazena a contagem da função millis()
unsigned long int tG=0;       //variável que armazena a contagem da função millis()
int delayR=3000;              //delay do ledR
int delayY=1000;              //delay do ledY
int delayG=2000;              //delay do ledG


//Variáveis
bool ledRState=HIGH;     //variável que armazena estado do ledR(on/off)
bool ledYState=LOW;     //variável que armazena estado do ledY(on/off)
bool ledGState=LOW;     //variável que armazena estado do ledG(on/off)

void setup() {
  //Mapeamento de Pinos
  pinMode(ledR, OUTPUT);            //ledR iniciado como atuador
  pinMode(ledY, OUTPUT);            //ledY iniciado como atuador
  pinMode(ledG, OUTPUT);            //ledG iniciado como atuador

  //Inicialização
  millis();                         //inicialização da função millis
  digitalWrite(ledR, ledRState);    //liga/desliga ledR
  digitalWrite(ledY, ledYState);    //liga/desliga ledY
  digitalWrite(ledG, ledGState);    //liga/desliga ledG
}

void loop() {
  //liga led verde
  while((millis()-tR) >= delayR && ledRState){      //caso ledR ligado, aguarda 3s de ledR ligado
    ledRState=!ledRState;                           //inverte o estado do led vermelho(on/off)
    digitalWrite(ledR, ledRState);                  //desliga ledR
    ledGState=!ledGState;                           //inverte o estado do led verde (on/off)
    digitalWrite(ledG, ledGState);                  //liga ledG
  }
  
  //liga led amarelo
  while((millis()-tG) >= (delayR+delayG) && ledGState){      //caso ledG ligado, aguarda 2s de ledG ligado
    ledGState=!ledGState;                           //inverte o estado do led verde (on/off)
    digitalWrite(ledG, ledGState);                  //liga ledG
    ledYState=!ledYState;                           //inverte o estado do led amarelo (on/off)
    digitalWrite(ledY, ledYState);                  //desliga ledY
  }
  
  //liga led vermelho
  while((millis()-tY) >= (delayR+delayG+delayY) && ledYState){      //caso ledY ligado, aguarda 1s de ledY ligado
    ledYState=!ledYState;                           //inverte o estado do led (on/off)
    digitalWrite(ledY, ledYState);                  //desliga ledY
    ledRState=!ledRState;                           //inverte o estado do led vermelho(on/off)
    digitalWrite(ledR, ledRState);                  //liga ledR
    tR=millis();                                    //atualiza tR com o novo valor temporal
    tG=millis();                                    //atualiza tG com o novo valor temporal
    tY=millis();                                    //atualiza tY com o novo valor temporal
  }
}
