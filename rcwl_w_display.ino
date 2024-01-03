/*
Using RCWL-0516 Microwave Radar Proximity sensor
to detect motion and output its state to a 1.8 inch TFT lcd screen.
*/

#include <TFT.h> 
#include <SPI.h>

#define cs 10
#define dc 9
#define rst 8
TFT TFTscreen = TFT(cs, dc, rst);

const int sensor = 12;              // the pin that the sensor is attached to

int state = LOW;                    // by default, no motion detected
int val = 0;                        // variable to store the sensor status (value)

void setup() {
  pinMode(sensor, INPUT);           // initialize sensor as an input
  Serial.begin(9600);               // initialize serial

  TFTscreen.begin();
  TFTscreen.background(0, 0, 0);
  TFTscreen.setTextSize(1);
}

void loop() {
  TFTscreen.stroke(255, 255, 255);
  val = digitalRead(sensor);
  
  if (val == HIGH) 
  {
    if (state == LOW) 
    {
      TFTscreen.background(0, 0, 0);
      TFTscreen.text("Something is moving!", 6, 57);
      state = HIGH;                 // update variable state to HIGH
    }
  }
  else 
  {
    if (state == HIGH) 
    {
      TFTscreen.background(0, 0, 0);
      TFTscreen.text("Motion has stopped!", 6, 57);
      state = LOW;                  // update variable state to LOW
    }
  }

}
