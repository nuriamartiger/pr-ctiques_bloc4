/*
CONTROL D'ARDUINO A TRAVÉS DE BLUETOOTH
*/

#include <Servo.h>
Servo servomotor;

int led_1=5;    //pin PWM on va conectat el LED

//Variables de control i/o lectura
char valor;
String estado;

void setup() {
    servomotor.attach(6);   //pin PWM 6 de l'arduinoper al servo
    servomotor.write(90);   //inicia el servo en una posició de 90 graus
    pinMode(led_1,OUTPUT);
    Serial.begin(9600);
}

void loop() {
    if (Serial.available())     //si el port serie buetooth está disponible
    {
      valor = Serial.read();    //Llegeix la dada entrant via bluetooth
      if(valor=='A')            //Si la dada entrant es una A
      {
        servo();                //Crida la funció que controla el gir del servo
      }
     if(valor=='5')             //Si la dada entrant es una B
     {
       led();                   //Crida la funció que controla la brillantor del LED
     }
     
    }
}


void led()
{
  delay(30);
  while (Serial.available())
  {
    char c=Serial.read();     //llegeix la dadda entrant i ho emmagatzema en una variable tipo char
    estado +=c;               //Crea una cadena tipo String con los datos entrantes
  }
  if (estado.length()>0)      //Es verifica que la cadena tipo String tingui un llarg major a zero
  {
    analogWrite(led_1, estado.toInt());   //Li envia al LED la dada en forma de enter (int)
    estado="";                //Neteja la variable per a poder llegir posteriorment noves dades
  }
}

void servo ()
{
  delay(30);
  while (Serial.available())
  {
    char c=Serial.read();       //Llegeix la dada entrant i la emmagatzema en una variable tipo char
    estado +=c;                 //crea una cadena tipo String amb les dades entrants
  }
    if (estado.length()>0)      //Es verifiva que la cadena tipo String tingui un llarg major a zero
  {
    servomotor.write(estado.toInt());     //Envia al servo la dada en forma d'enter (int)
    estado="";                  //Neteja la variable per a poder llegir posteriorment noves dades
  }
}
