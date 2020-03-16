#include <LiquidCrystal.h>




LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
// initialise les commandes avec les n° de broches

byte hautbouche[8]={

 B00000,
 B00000,
 B00000,
 B00000,
 B00000,
 B00000,
 B11111,
 B00000
};
byte coteboucheetonne[8]={

 B11111,
 B11111,
 B11111,
 B11111,
 B00000,
 B00000,
 B00000,
 B00000
};

byte hautbouche[8]={

 B00000,
 B00000,
 B00000,
 B00000,
 B00000,
 B00000,
 B11111,
 B11111
};

byte cotebouche[8]={

 B11111,
 B11111,
 B00000,
 B00000,
 B00000,
 B00000,
 B00000,
 B00000
};

byte basbouche[8]={

 B00000,
 B00000,
 B11111,
 B11111,
 B00000,
 B00000,
 B00000,
 B00000
};

void setup() {
  lcd.begin(16, 2); }

void loop() { 
  lcd.display();

   lcd.createChar(1, hautbouche); 
     
    lcd.createChar(2, cotebouche);
    lcd.createChar(3, basbouche);
     lcd.createChar(4, coteboucheetonne);
    lcd.setCursor(3,0);
    lcd.write(1);
    lcd.setCursor(4,0);
    lcd.write(1);
    lcd.setCursor(5,0);
    lcd.write(1);
    lcd.setCursor(6,0);
    lcd.write(1);
    lcd.setCursor(7,0);
    lcd.setCursor(8,0);
    lcd.write(1);
    lcd.setCursor(9,0);
    lcd.write(1);
    lcd.setCursor(10,0);
    lcd.write(1);
    lcd.setCursor(11,0);
    lcd.write(1);
    lcd.setCursor(12,0);
    lcd.write(1);
    lcd.setCursor(13,0);
    lcd.write(1);
    lcd.setCursor(14,0);
    lcd.write(1);
    lcd.setCursor(4,1);
    lcd.write(2);
    lcd.setCursor(13,1);
    lcd.write(2);
    lcd.setCursor(5,1);
    lcd.write(3);
    lcd.setCursor(6,1);
    lcd.write(3);
    lcd.setCursor(6,1);
    lcd.write(3);
    lcd.setCursor(7,1);
    lcd.write(3);
    lcd.setCursor(8,1);
    lcd.write(3);
    lcd.setCursor(9,1);
    lcd.write(3);
    lcd.setCursor(10,1);
    lcd.write(3);
    lcd.setCursor(11,1);
    lcd.write(3);
    lcd.setCursor(12,1);
    lcd.write(3);
    
    delay(2000);

    
lcd.clear();
 lcd.setCursor(3,0);
    lcd.write(1);
    lcd.setCursor(4,0);
    lcd.write(1);
    lcd.setCursor(5,0);
    lcd.write(1);
    lcd.setCursor(6,0);
    lcd.write(1);
    lcd.setCursor(7,0);
    lcd.setCursor(8,0);
    lcd.write(1);
    lcd.setCursor(9,0);
    lcd.write(1);
    lcd.setCursor(10,0);
    lcd.write(1);
    lcd.setCursor(11,0);
    lcd.write(1);
    lcd.setCursor(12,0);
    lcd.write(1);
    lcd.setCursor(13,0);
    lcd.write(1);
    lcd.setCursor(14,0);
    lcd.write(1);
    lcd.setCursor(3,1);
    lcd.write(4);
    lcd.setCursor(14,1);
    lcd.write(4);
    lcd.setCursor(4,1);
    lcd.write(3);
    lcd.setCursor(5,1);
    lcd.write(3);
    lcd.setCursor(6,1);
    lcd.write(3);
    lcd.setCursor(6,1);
    lcd.write(3);
    lcd.setCursor(7,1);
    lcd.write(3);
    lcd.setCursor(8,1);
    lcd.write(3);
    lcd.setCursor(9,1);
    lcd.write(3);
    lcd.setCursor(10,1);
    lcd.write(3);
    lcd.setCursor(11,1);
    lcd.write(3);
    lcd.setCursor(12,1);
    lcd.write(3);
    lcd.setCursor(13,1);
    lcd.write(3);
 delay (2000);

    
    
    }











  
