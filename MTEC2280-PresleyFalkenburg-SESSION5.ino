const int ledPins[] = {8, 18, 17, 16, 15, 7, 6, 5, 4};
const int numPins = sizeof(ledPins) / sizeof(ledPins[0]);
const int POT_PIN = 9;
const int BUTTON_PIN = 13;

bool isOff = false;

void setup() {
  for (int i = 0; i < numPins; i++)
    pinMode(ledPins[i], OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    isOff = true;
    for (int i = 0; i < numPins; i++)
      analogWrite(ledPins[i], 0);
    while (digitalRead(BUTTON_PIN) == LOW);
    return;
  }


  isOff = false;

  // pot picks which single LED is on
  int index = map(analogRead(POT_PIN), 0, 1023, 0, numPins - 1);

  for (int i = 0; i < numPins; i++)
    analogWrite(ledPins[i], i == index ? 255 : 0);
}