// this constant won't change:
const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int ledPin = 13;       // the pin that the LED is attached to

// Variables will change:

int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
int state = 0 ;
bool ledState = false ;
int wait = 1000 ;
unsigned long lastBlinkTime = 0 ;

void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600); 
}


void loop() {
  unsigned long currentTime = millis();
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      state = state + 1 ;
      if (state == 2) {
        state = 0 ;
      }
    }
  }


  if(state == 0) {
    digitalWrite(ledPin, LOW) ;
    ledState = false ;
  } else if (state == 1) {
    if (currentTime - lastBlinkTime > wait) {
      ledState = !ledState;
      lastBlinkTime = millis();
    }
  }

  if (ledState == true) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  lastButtonState = buttonState;
}










