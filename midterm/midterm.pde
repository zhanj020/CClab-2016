import processing.video.*;

import processing.serial.*;



PImage bg;
PFont font;
Movie mov;
Movie mov1;
Movie mov2;


Serial myPort;

int touchValue1=0;
int touchValue2=0;

void setup() {
  myPort = new Serial(this, Serial.list()[0], 9600);
  mov = new Movie(this, "1.mp4");
  mov1= new Movie(this, "3.mp4");
  mov2= new Movie(this, "4.mp4");
  size(1280 , 720);
  bg = loadImage("wallpaper.jpg");
  font = createFont("HennyPenny-Regular.otf", 20);
  // Prints out the available serial ports.
  mov.noLoop();
  mov.frameRate(24);
  mov.play();
  mov.jump(0);
  mov.pause();
}

void serialEvent(Serial port) {
  String inString = port.readStringUntil('\n');
  if (inString != null) {
    inString = trim(inString);
    //println(inString);
    int[] allButtons = int(split(inString, ','));
    if (allButtons.length == 2) { 
      touchValue1 = allButtons[0];
      touchValue2 = allButtons[1];
    }
  }
}

void movieEvent(Movie m) {
  m.read();
}

void backgroundDraw(){
image(bg, 0,0);
  textAlign(CENTER);
  textFont(font,50);
  fill(100,100,100);
  text("Hold My Hands! ",500,height/2);
}

void draw() {
  if (touchValue1!=0 && touchValue2==0) {
    image(mov, 0, 0);
    mov.play();
    mov.loop();
    mov1.stop();
    println("play");
    print(touchValue1);
    print('\t');
    println(touchValue2);
  } else if(touchValue1 ==0 && touchValue2!=0) {
    image(mov1, 0, 0);
    mov1.play();
    mov1.loop();
    mov.stop();
    println("play");
    print(touchValue1);
    print('\t');
    println(touchValue2);
  }else if(touchValue1 !=0 && touchValue2!=0){
    image(mov2, 0, 0);
    mov2.play();
    mov2.loop();
    mov.stop();
    mov1.stop();
    println("play");
    print(touchValue1);
    print('\t');
    println(touchValue2);
  }
  
  else{
    mov.stop();
    mov1.stop();
    mov2.stop();
    backgroundDraw();
  }
}