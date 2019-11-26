// LIBRARIES
#include <Servo.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


// CONSTANTS


// VARIABLES 

char receivedChar;
boolean newData = false;
int temp = 0;

void setup() {
  Serial.begin(9600);

  pinMode(13, OUTPUT);
 
  delay(2000);
}

//=======

void loop() {

 readInfo();
 readTemp();
 delay(100);
}

//======== FUNCTIONS

void readInfo() {

  if (Serial.available() > 0) {

    receivedChar = Serial.read();
    newData = true;
  }
 
  
}

void readTemp() {
  while(newData == true) {
    if (receivedChar == 'T' ) {
      temp = analogRead(0);
      Serial.println(temp);
   }


    newData = false;
    
  }
  
}


//======= END
