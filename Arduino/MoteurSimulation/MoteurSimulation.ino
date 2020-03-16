
//bluetooth

#include <SoftwareSerial.h>


char data;
const int LED_droite = A1;
const int LED_gauche = A0;




void setup() {
   Serial.begin(9600);
    delay(500);
    pinMode(LED_droite, OUTPUT);
    pinMode(LED_gauche, OUTPUT);
  }

void loop() {
 while (Serial.available())
 
  data=Serial.read();

  if (data == 'a') { 
    digitalWrite(LED_droite, 0);
    digitalWrite(LED_gauche, 0);
  }

  else if (data == 'r') {
    digitalWrite(LED_droite, 1);
    digitalWrite(LED_gauche, 1);
  }

  else if (data == 'g') {
    digitalWrite(LED_droite, 1);
    digitalWrite(LED_gauche, 0);
  }
  else if (data == 'd') {
    digitalWrite(LED_droite, 0);
    digitalWrite(LED_gauche, 1);
  } 
  else if (data == 'e') {
    digitalWrite(LED_droite, 0);
    digitalWrite(LED_gauche, 0);
  }
}
