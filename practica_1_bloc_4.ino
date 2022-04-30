/* 
CONTROL D'ARDUINO A TRAVÉS DEL PORT SERIAL D'UN DISPOSITIU ANDROID.
*/

void setup() {
    Serial.begin(9600);
    pinMode(13, OUTPUT);            //pin 13 com a pin de sortida
}

void loop() {
    char dada=Serial.read();        //creem variable char que llegira la informació que li arribi al port serie
    if(dada=='1')
    {
      if (digitalRead(13)==HIGH)    //si el LED està encès 
      digitalWrite(13,LOW);         //l'apaguem
      else
      digitalWrite (13,HIGH);       //en cas contrari l'encenem.
    }
    delay(1000);
}
