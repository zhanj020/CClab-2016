import processing.serial.*;
import cc.arduino.*;

PFont font;

Arduino arduino ;

boolean LEDlight = false;

void setup() {
  background(200);
  fill(200);
  size(650, 400);
  arduino = new Arduino(this, Arduino.list()[0], 57600);
  
  font = createFont("Arial",25);
  textFont(font);
};

void draw(){

  text("Press Space Bar to Turn On/Off the light",width/2-200,height/2);
  fill(84, 145, 158);
  
  
  
};


void keyPressed()
{
    if(LEDlight == true){
      background(255);
      arduino.digitalWrite(13, Arduino.HIGH); 
    }
    else{
      arduino.digitalWrite(13, Arduino.LOW) ; 
      background(0);
   
    }
    LEDlight=!LEDlight;
}