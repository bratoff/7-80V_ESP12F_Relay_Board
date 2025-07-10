int pins[] = {0,2,4,5,12,13,14,15,16};
int numPins = sizeof(pins)/sizeof(int);

void setup() {
  Serial.begin(115200);
  delay(100);
  Serial.println("");
  Serial.println("GPIO pin input test");
  Serial.println("");
}

void loop() {
  for(int i=0; i<numPins; i++) {
    Serial.println("Setting GPIO"+String(pins[i]+" to 0"));
    pinMode(pins[i],OUTPUT);
    digitalWrite(pins[i],LOW);
    delay(250);
    Serial.println("Setting GPIO"+String(pins[i]+" to 1"));
    digitalWrite(pins[i],HIGH);
    delay(250);
    pinMode(pins[i],INPUT);
  }
}
