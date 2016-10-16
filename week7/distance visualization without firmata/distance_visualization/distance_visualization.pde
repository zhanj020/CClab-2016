/* Created by Jialu Zhang

   Inspired by the Processing sketch by ScottC on
   the 10 Nov 2012 : http://arduinobasics.blogspot.com/
*/

import processing.serial.*;

import cc.arduino.*;

Serial myPort;
int echo=8;
int trig=7;
int distance;

void setup() {
  size(500, 300);

  // Prints out the available serial ports.
   myPort = new Serial(this, Serial.list()[0], 9600);

}

void draw() {
  String readDistance = myPort.readStringUntil('\n');

    if(readDistance != null) {
     readDistance=trim(readDistance);
     
       distance = int(map(Integer.parseInt(readDistance),0,200,0,255));
       if(distance<0){
       /*If computer receives a negative number (-1), then the
       sensor is reporting an "out of range" error. Convert all
       of these to a distance of 0. */
       distance = 0;
       }
     }
     println(distance);
     
      background(#222930);
      fill(#E9E9E9);
      textSize(80);
      text(distance +" cm", width/2-60, height/2); 
}