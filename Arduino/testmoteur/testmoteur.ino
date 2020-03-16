//bluetooth

#include <SoftwareSerial.h>


char data;

/*connecter les broches du contrôleur de moteur aux broches numériques Arduino
// moteur droit*/
int enA = 10;
int in1 = 9;
int in2 = 8;

/* moteur gauche*/
int enB = 11;
int in3 = 7;
int in4 = 6; 


const unsigned long MEASURE_TIMEOUT = 25000UL; // 25ms = ~8m à 340m/s

// Vitesse du son dans l'air en mm/us 
const float SOUND_SPEED = 340.0 / 1000;
const byte TRIGGER_PIN = 15; // Broche TRIGGER
const byte ECHO_PIN = 16;    // Broche ECHO

const byte TRIGGER_PIN2 = 12; // Broche TRIGGER
const byte ECHO_PIN2 = 13;    // Broche ECHO  





void setup() {
   
 

pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
pinMode(TRIGGER_PIN, OUTPUT);
digitalWrite(TRIGGER_PIN, LOW); // La broche TRIGGER doit être à LOW au repos
pinMode(ECHO_PIN, INPUT);
pinMode(TRIGGER_PIN2, OUTPUT);
digitalWrite(TRIGGER_PIN2, LOW); // La broche TRIGGER doit être à LOW au repos
pinMode(ECHO_PIN2, INPUT);
pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT);


  }

void loop() {




  


digitalWrite(in2, HIGH);
digitalWrite(in1, LOW);
analogWrite(enA, 100);

digitalWrite(in4, HIGH);
digitalWrite(in3, LOW);
analogWrite(enB, 100);
delay(1000);}

 
