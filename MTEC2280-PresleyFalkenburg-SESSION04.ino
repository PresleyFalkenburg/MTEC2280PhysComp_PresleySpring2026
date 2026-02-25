/*
  LED CYCLE WITH BUTTON STOP
  9 LEDs cycle one at a time. Button toggles pause.
*/

int ledPins[] = {8, 18, 17, 16, 15, 7, 6, 5, 4};
int buttonPin = 13;

int currentLed = 0;
bool running = true;
bool lastButton = LOW;

unsigned long lastTime = 0;
int delayTime = 200;

void setup() {
  for (int i = 0; i < 9; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT);
}

void loop() {
  bool button = digitalRead(buttonPin);
  
  if (button == HIGH && lastButton == LOW) {
    running = !running;
    delay(50);
  }
  lastButton = button;
  
  if (running && millis() - lastTime >= delayTime) {
    for (int i = 0; i < 9; i++) {
      digitalWrite(ledPins[i], LOW);
    }
    
    digitalWrite(ledPins[currentLed], HIGH);
    
    currentLed++;
    if (currentLed >= 9) currentLed = 0;
    
    lastTime = millis();
  }
}
