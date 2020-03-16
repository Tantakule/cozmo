#include <LiquidCrystal.h>




LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
// initialise les commandes avec les n° de broches




byte debutoeilferme[8]={
  B00000,
  B00000,
  B00000,
  B00111,
  B00111,
  B00000,
  B00000,
  B00000
};

byte finoeilferme[8]={
  B00000,
  B00000,
  B00000,
  B11100,
  B11100,
  B00000,
  B00000,
  B00000
};


byte debutsourciletonne[8]={
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00111,
  B01000,
  B10000
};


byte milieusourciletonne[8]={
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B00000,
  B00000
};

byte finsourciletonne[8]={
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11100,
  B00010,
  B00001
};







byte debutoeil[8]={
  B00000,
  B00011,
  B00100,
  B00100,
  B00100,
  B00100,
  B00011,
  B00000
};

byte milieuoeil[8]={
  B00000,
  B11111,
  B00000,
  B00100,
  B00100,
  B00000,
  B11111,
  B00000
};

byte finoeil[8]={
  B00000,
  B11000,
  B00100,
  B00100,
  B00100,
  B00100,
  B11000,
  B00000
};

byte milieuoeilferme[8]={
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000
};



void setup() {
  lcd.begin(16, 2); 
  
/*lcd.createChar(8, debutsourcilferme); 
   
    
     lcd.createChar(1, debutoeil); 
     
    lcd.createChar(2, milieuoeil);
    lcd.createChar(3, finoeil);
     lcd.createChar(4, debutsourciletonne); 
    lcd.createChar(5, milieusourciletonne);
    lcd.createChar(6, finsourciletonne);
    
     lcd.createChar(7, debutoeilferme); */
   
  }


void loop() { 
  lcd.display();

   lcd.createChar(1, debutoeil); 
     
    lcd.createChar(2, milieuoeil);
    lcd.createChar(3, finoeil);
     lcd.createChar(4, debutsourciletonne); 
    lcd.createChar(5, milieusourciletonne);
    lcd.createChar(6, finsourciletonne);
 
    lcd.setCursor(4,0);
    lcd.write(4);
    lcd.setCursor(5,0);
    lcd.write(5);
    lcd.setCursor(6,0); 
    lcd.write(6);
  
    lcd.setCursor(8,0);
    lcd.write(4);
    lcd.setCursor(9,0);
    lcd.write(5);
    lcd.setCursor(10,0); 
    lcd.write(6);
    
      lcd.setCursor(4,1);
    lcd.write(1);
    lcd.setCursor(5,1);
    lcd.write(2);
    lcd.setCursor(6,1); 
    lcd.write(3);
    
    lcd.setCursor(8,1);
    lcd.write(1);
    lcd.setCursor(9,1);
    lcd.write(2);
    lcd.setCursor(10,1); 
    lcd.write(3);


delay(3000);


lcd.clear();

lcd.createChar(7, milieuoeilferme);
 lcd.setCursor(4,0);
    lcd.write(4);
    lcd.setCursor(5,0);
    lcd.write(5);
    lcd.setCursor(6,0); 
    lcd.write(6);
  
    lcd.setCursor(8,0);
    lcd.write(4);
    lcd.setCursor(9,0);
    lcd.write(5);
    lcd.setCursor(10,0); 
    lcd.write(6);

    lcd.createChar(1, debutoeilferme);
    lcd.createChar(2, finoeilferme);
      lcd.setCursor(4,1);
    lcd.write(1);
    lcd.setCursor(5,1);
    lcd.write(7);
    lcd.setCursor(6,1); 
    lcd.write(2);


    


    
 
    lcd.setCursor(8,1);
    lcd.write(1);
    lcd.setCursor(9,1);
    lcd.write(7);
    lcd.setCursor(10,1); 
    lcd.write(2);



    delay(400);

    lcd.clear();

    
 lcd.createChar(8, debutoeil); 
     
  
    lcd.createChar(3, finoeil);
lcd.createChar(7, milieuoeilferme);

 lcd.setCursor(4,0);
    lcd.write(4);
    lcd.setCursor(5,0);
    lcd.write(5);
    lcd.setCursor(6,0); 
    lcd.write(6);
  
    lcd.setCursor(8,0);
    lcd.write(4);
    lcd.setCursor(9,0);
    lcd.write(5);
    lcd.setCursor(10,0); 
    lcd.write(6);

    lcd.createChar(1, debutoeilferme);
    lcd.createChar(2, finoeilferme);
      lcd.setCursor(4,1);
    lcd.write(7);
    lcd.setCursor(5,1);
    lcd.write(7);
    lcd.setCursor(6,1); 
    lcd.write(7);

 lcd.createChar(2, milieuoeil);
    lcd.setCursor(8,1);
    lcd.write(8);
    lcd.setCursor(9,1);
    lcd.write(2);
    lcd.setCursor(10,1); 
    lcd.write(3);

    


    
    delay(400);

    lcd.clear();
    
    }
