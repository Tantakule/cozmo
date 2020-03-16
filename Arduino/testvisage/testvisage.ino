#include <LiquidCrystal.h>



LiquidCrystal a(8, 9, 10, 11, 12, 13);
LiquidCrystal b(2, 3, 4, 5, 6, 7);

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

byte hautbouchestoique[8]={

 B11111,
 B11111,
 B00000,
 B00000,
 B00000,
 B00000,
 B00000,
 B00000
};

byte coteboucheetonne[8]={

 B11111,
 B11111,
 B11111,
 B11111,
 B11111,
 B11111,
 B11111,
 B11111
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

    a.begin(16, 2); 
    
    b.begin(16, 2); 
  }


void visagenormal() { 


  a.display();
  b.display();

   b.createChar(2, cotebouche);
    b.createChar(3, basbouche);
     b.createChar(4, coteboucheetonne);
     b.createChar(5, hautbouche); 
     b.setCursor(1,0);
    b.write(5);
    b.setCursor(2,0);
    b.write(5);
    b.setCursor(3,0);
    b.write(5);
    b.setCursor(4,0);
    b.write(5);
    b.setCursor(5,0);
    b.write(5);
    b.setCursor(6,0);
    b.write(5);
    b.setCursor(7,0);
    b.write(5);
    b.setCursor(8,0);
    b.write(5);
    b.setCursor(9,0);
    b.write(5);
    b.setCursor(10,0);
    b.write(5);
    b.setCursor(11,0);
    b.write(5);
    b.setCursor(12,0);
    b.write(5);
    b.setCursor(13,0);
    b.write(5);
     b.setCursor(14,0);
    b.write(5);
    b.setCursor(2,1);
    b.write(2);
    b.setCursor(13,1);
    b.write(2);
     b.setCursor(3,1);
    b.write(3);
    b.setCursor(4,1);
    b.write(3);
    b.setCursor(5,1);
    b.write(3);
    b.setCursor(6,1);
    b.write(3);
    b.setCursor(7,1);
    b.write(3);
    b.setCursor(8,1);
    b.write(3);
    b.setCursor(9,1);
    b.write(3);
    b.setCursor(10,1);
    b.write(3);
    b.setCursor(11,1);
    b.write(3);
    b.setCursor(12,1);
    b.write(3);
    

   a.createChar(1, debutoeil); 
     
    a.createChar(2, milieuoeil);
    a.createChar(3, finoeil);
     a.createChar(4, debutsourciletonne); 
    a.createChar(5, milieusourciletonne);
    a.createChar(6, finsourciletonne);
 
    a.setCursor(4,0);
    a.write(4);
    a.setCursor(5,0);
    a.write(5);
    a.setCursor(6,0); 
    a.write(6);
  
    a.setCursor(8,0);
    a.write(4);
    a.setCursor(9,0);
    a.write(5);
    a.setCursor(10,0); 
    a.write(6);
    
      a.setCursor(4,1);
    a.write(1);
    a.setCursor(5,1);
    a.write(2);
    a.setCursor(6,1); 
    a.write(3);
    
    a.setCursor(8,1);
    a.write(1);
    a.setCursor(9,1);
    a.write(2);
    a.setCursor(10,1); 
    a.write(3);


delay(3000);


a.clear();
b.clear();

 b.createChar(2, cotebouche);
    b.createChar(3, basbouche);
     b.createChar(4, coteboucheetonne);
     b.createChar(5, hautbouchestoique); 
    
   b.createChar(2, cotebouche);
    b.createChar(3, basbouche);
     b.createChar(4, coteboucheetonne);
     b.createChar(5, hautbouche); 
     b.setCursor(1,0);
    b.write(5);
    b.setCursor(2,0);
    b.write(5);
    b.setCursor(3,0);
    b.write(5);
    b.setCursor(4,0);
    b.write(5);
    b.setCursor(5,0);
    b.write(5);
    b.setCursor(6,0);
    b.write(5);
    b.setCursor(7,0);
    b.write(5);
    b.setCursor(8,0);
    b.write(5);
    b.setCursor(9,0);
    b.write(5);
    b.setCursor(10,0);
    b.write(5);
    b.setCursor(11,0);
    b.write(5);
    b.setCursor(12,0);
    b.write(5);
    b.setCursor(13,0);
    b.write(5);
     b.setCursor(14,0);
    b.write(5);
    b.setCursor(2,1);
    b.write(2);
    b.setCursor(13,1);
    b.write(2);
     b.setCursor(3,1);
    b.write(3);
    b.setCursor(4,1);
    b.write(3);
    b.setCursor(5,1);
    b.write(3);
    b.setCursor(6,1);
    b.write(3);
    b.setCursor(7,1);
    b.write(3);
    b.setCursor(8,1);
    b.write(3);
    b.setCursor(9,1);
    b.write(3);
    b.setCursor(10,1);
    b.write(3);
    b.setCursor(11,1);
    b.write(3);
    b.setCursor(12,1);
    b.write(3);
    

a.createChar(7, milieuoeilferme);
 a.setCursor(4,0);
    a.write(4);
    a.setCursor(5,0);
    a.write(5);
    a.setCursor(6,0); 
    a.write(6);
  
    a.setCursor(8,0);
    a.write(4);
    a.setCursor(9,0);
    a.write(5);
    a.setCursor(10,0); 
    a.write(6);

    a.createChar(1, debutoeilferme);
    a.createChar(2, finoeilferme);
      a.setCursor(4,1);
    a.write(1);
    a.setCursor(5,1);
    a.write(7);
    a.setCursor(6,1); 
    a.write(2);


    


    
 
    a.setCursor(8,1);
    a.write(1);
    a.setCursor(9,1);
    a.write(7);
    a.setCursor(10,1); 
    a.write(2);



    delay(400);

    a.clear();
    b.clear();

    

    }

    void visageetonne() { 


  a.display();
  b.display();

   b.createChar(2, cotebouche);
    b.createChar(3, hautbouche);
     b.createChar(4, coteboucheetonne);
     b.createChar(5, hautbouche); 
   
    b.setCursor(5,0);
    b.write(4);
    b.setCursor(6,0);
    b.write(2);
    b.setCursor(7,0);
    b.write(2);
    b.setCursor(8,0);
    b.write(2);
    
    b.setCursor(9,0);
    b.write(4);
    b.setCursor(5,1);
    b.write(4);
       b.setCursor(6,1);
    b.write(3);
    b.setCursor(7,1);
    b.write(3);
     b.setCursor(8,1);
    b.write(3);
    b.setCursor(9,1);
    b.write(4);
   
    
    

   a.createChar(1, debutoeil); 

    
     
    a.createChar(2, milieuoeil);
    a.createChar(3, finoeil);
     a.createChar(4, debutsourciletonne); 
    a.createChar(5, milieusourciletonne);
    a.createChar(6, finsourciletonne);
 
    a.setCursor(4,0);
    a.write(4);
    a.setCursor(5,0);
    a.write(5);
    a.setCursor(6,0); 
    a.write(6);
  
    a.setCursor(8,0);
    a.write(4);
    a.setCursor(9,0);
    a.write(5);
    a.setCursor(10,0); 
    a.write(6);
    
      a.setCursor(4,1);
    a.write(1);
    a.setCursor(5,1);
    a.write(2);
    a.setCursor(6,1); 
    a.write(3);
    
    a.setCursor(8,1);
    a.write(1);
    a.setCursor(9,1);
    a.write(2);
    a.setCursor(10,1); 
    a.write(3);


delay(3000);


a.clear();
b.clear();

 b.createChar(2, cotebouche);
    b.createChar(3, hautbouche);
     b.createChar(4, coteboucheetonne);
     b.createChar(5, hautbouchestoique); 
    
   b.setCursor(5,0);
    b.write(4);
    b.setCursor(6,0);
    b.write(2);
    b.setCursor(7,0);
    b.write(2);
    b.setCursor(8,0);
    b.write(2);
    
    b.setCursor(9,0);
    b.write(4);
    b.setCursor(5,1);
    b.write(4);
       b.setCursor(6,1);
    b.write(3);
    b.setCursor(7,1);
    b.write(3);
     b.setCursor(8,1);
    b.write(3);
    b.setCursor(9,1);
     b.write(4);
  
    

a.createChar(7, milieuoeilferme);
 a.setCursor(4,0);
    a.write(4);
    a.setCursor(5,0);
    a.write(5);
    a.setCursor(6,0); 
    a.write(6);
  
    a.setCursor(8,0);
    a.write(4);
    a.setCursor(9,0);
    a.write(5);
    a.setCursor(10,0); 
    a.write(6);

    a.createChar(1, debutoeilferme);
    a.createChar(2, finoeilferme);
      a.setCursor(4,1);
    a.write(1);
    a.setCursor(5,1);
    a.write(7);
    a.setCursor(6,1); 
    a.write(2);


    


    
 
    a.setCursor(8,1);
    a.write(1);
    a.setCursor(9,1);
    a.write(7);
    a.setCursor(10,1); 
    a.write(2);



    delay(400);

    a.clear();
    b.clear();

    

    }

    void visagestoique() {  
      b.createChar(1, hautbouche); 
     
    b.createChar(2, cotebouche);
    b.createChar(3, basbouche);
     b.createChar(4, coteboucheetonne);
     b.createChar(5, hautbouchestoique);


  a.display();
  b.display();


      b.setCursor(2,0);
    b.write(1);
    b.setCursor(3,0);
    b.write(1);
    b.setCursor(4,0);
    b.write(1);
    b.setCursor(5,0);
    b.write(1);
    b.setCursor(6,0);
    b.write(1);
    b.setCursor(7,0);
    b.write(1);
    b.setCursor(8,0);
    b.write(1);
    b.setCursor(9,0);
    b.write(1);
    b.setCursor(10,0);
    b.write(1);
    b.setCursor(11,0);
    b.write(1);
    b.setCursor(12,0);
    b.write(1);
    b.setCursor(13,0);
    b.write(1);

     b.setCursor(2,1);
    b.write(5);
    b.setCursor(3,1);
    b.write(5);
    b.setCursor(4,1);
    b.write(5);
    b.setCursor(5,1);
    b.write(5);
    b.setCursor(6,1);
    b.write(5);
    b.setCursor(7,1);
    b.write(5);
    b.setCursor(8,1);
    b.write(5);
    b.setCursor(9,1);
    b.write(5);
    b.setCursor(10,1);
    b.write(5);
    b.setCursor(11,1);
    b.write(5);
    b.setCursor(12,1);
    b.write(5);
    b.setCursor(13,1);
    b.write(5);

    

    

   a.createChar(1, debutoeil); 
     
    a.createChar(2, milieuoeil);
    a.createChar(3, finoeil);
     a.createChar(4, debutsourciletonne); 
    a.createChar(5, milieusourciletonne);
    a.createChar(6, finsourciletonne);
 
    a.setCursor(4,0);
    a.write(4);
    a.setCursor(5,0);
    a.write(5);
    a.setCursor(6,0); 
    a.write(6);
  
    a.setCursor(8,0);
    a.write(4);
    a.setCursor(9,0);
    a.write(5);
    a.setCursor(10,0); 
    a.write(6);
    
      a.setCursor(4,1);
    a.write(1);
    a.setCursor(5,1);
    a.write(2);
    a.setCursor(6,1); 
    a.write(3);
    
    a.setCursor(8,1);
    a.write(1);
    a.setCursor(9,1);
    a.write(2);
    a.setCursor(10,1); 
    a.write(3);


delay(3000);


a.clear();
b.clear();
   b.createChar(1, hautbouche); 
     
    b.createChar(2, cotebouche);
    b.createChar(3, basbouche);
     b.createChar(4, coteboucheetonne);
     b.createChar(5, hautbouchestoique);


    
    b.setCursor(2,0);
    b.write(1);
    b.setCursor(3,0);
    b.write(1);
    b.setCursor(4,0);
    b.write(1);
    b.setCursor(5,0);
    b.write(1);
    b.setCursor(6,0);
    b.write(1);
    b.setCursor(7,0);
    b.write(1);
    b.setCursor(8,0);
    b.write(1);
    b.setCursor(9,0);
    b.write(1);
    b.setCursor(10,0);
    b.write(1);
    b.setCursor(11,0);
    b.write(1);
    b.setCursor(12,0);
    b.write(1);
    b.setCursor(13,0);
    b.write(1);

     b.setCursor(2,1);
    b.write(5);
    b.setCursor(3,1);
    b.write(5);
    b.setCursor(4,1);
    b.write(5);
    b.setCursor(5,1);
    b.write(5);
    b.setCursor(6,1);
    b.write(5);
    b.setCursor(7,1);
    b.write(5);
    b.setCursor(8,1);
    b.write(5);
    b.setCursor(9,1);
    b.write(5);
    b.setCursor(10,1);
    b.write(5);
    b.setCursor(11,1);
    b.write(5);
    b.setCursor(12,1);
    b.write(5);
    b.setCursor(13,1);
    b.write(5);
    

a.createChar(7, milieuoeilferme);
 a.setCursor(4,0);
    a.write(4);
    a.setCursor(5,0);
    a.write(5);
    a.setCursor(6,0); 
    a.write(6);
  
    a.setCursor(8,0);
    a.write(4);
    a.setCursor(9,0);
    a.write(5);
    a.setCursor(10,0); 
    a.write(6);

    a.createChar(1, debutoeilferme);
    a.createChar(2, finoeilferme);
      a.setCursor(4,1);
    a.write(1);
    a.setCursor(5,1);
    a.write(7);
    a.setCursor(6,1); 
    a.write(2);


    


    
 
    a.setCursor(8,1);
    a.write(1);
    a.setCursor(9,1);
    a.write(7);
    a.setCursor(10,1); 
    a.write(2);



    delay(400);

    a.clear();
    b.clear();

    

    }

    void loop(){
      visagenormal();
      visagestoique();
      visageetonne();
      }
