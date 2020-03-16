
#include <SPI.h>
//#include <SD.h>
#include "SdFat.h"
#include <SFEMP3Shield.h>
SdFat sd;

#define SD_CS_PIN 9
SFEMP3Shield MP3player;

File myFile;
bool opened = false;
int countOpen = 0;
int countClose = 0;
bool runVoice = 0;
char data;

void setup()
{
  Serial.begin(9600);
  Serial.println("Initializing SD card...");

  if (!sd.begin(SD_CS_PIN))
  {
    Serial.println("initialization failed!");
    return;
  }
  
  Serial.println("Initialization done");
  
  MP3player.begin();
  MP3player.setVolume(00, 00);
}

void loop()
{

  while (Serial.available())
  {
    data = Serial.read();
    Serial.write(data);
    
    if (data == '@') countClose++;
    else if (data == '!') countOpen++;
    
    else {
      for (int i=0; i< countClose; i++){ 
        myFile.write('@');
      }
      for (int i=0; i < countOpen; i++){
        myFile.write('!');
      }
      myFile.write(data);
      countOpen = 0;
      countClose = 0;
    }

    if (countOpen >= 3) {
        sd.remove("track002.mp3");
       myFile = sd.open("track002.mp3", FILE_WRITE);
       delay(100);
       Serial.println(myFile);
       Serial.println("File opened");
       countOpen = 0;
    }
    
    if (countClose >= 3) {
      myFile.close();
      delay(100);
      Serial.println("File closed");
      Serial.flush();
      MP3player.setVolume(10000000000, 1000000000);
      MP3player.playTrack(2);
      countClose = 0;
      
      
    }
  }
}
