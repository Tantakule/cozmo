
//bluetooth
char data;

/*connecter les broches du contrôleur de moteur aux broches numériques Arduino
// moteur droit*/
int enA = 10;
int in1 = 8;
int in2 = 9;

/* moteur gauche*/
int enB = 11;
int in3 = 7;
int in4 = 6; 


const unsigned long MEASURE_TIMEOUT = 25000UL; // 25ms = ~8m à 340m/s

/*/ Vitesse du son dans l'air en mm/us 
const float SOUND_SPEED = 340.0 / 1000;
const byte TRIGGER_PIN = 15; // Broche TRIGGER
const byte ECHO_PIN = 16;    // Broche ECHO

const byte TRIGGER_PIN2 = 12; // Broche TRIGGER
const byte ECHO_PIN2 = 13;    // Broche ECHO  */





void setup() {
   Serial.begin(9600);
    delay(500);
 
// régler toutes les broches de contrôle du moteur sur sorties
pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT);


  }

void loop() {
 while (Serial.available())
    data = Serial.read();

  

 //cas tout droit 
  if (data=='e'){  
  digitalWrite(in2, HIGH);
  digitalWrite(in1, LOW);
  analogWrite(enA, 0);
  
  digitalWrite(in4, HIGH);
  digitalWrite(in3, LOW);
  analogWrite(enB, 0);
  delay(100);
  }

 // cas tourne fort à droite
  if(data=='g'){  
    digitalWrite(in2, HIGH);
    digitalWrite(in1, LOW);
    analogWrite(enA, 255);
    
    digitalWrite(in4, HIGH);
    digitalWrite(in3, LOW);
    analogWrite(enB, 0);}

 //cas tourne fort à gauche 
  if(data=='d'){  
    digitalWrite(in2, HIGH);
    digitalWrite(in1, LOW);
    analogWrite(enA, 0);
    
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, 255);}


//recule
    if(data=='a'){  
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(enA, 255);
      
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(enB, 255);}
   if (data == 'r') {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      analogWrite(enA, 255);
      
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(enB, 255);
      }
}
