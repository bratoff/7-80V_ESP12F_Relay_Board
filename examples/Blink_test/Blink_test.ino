/*********
  Rui Santos
  Complete project details at http://randomnerdtutorials.com 
  Heavily modified by B. Ratoff August 2023 
*********/
#define LED_PIN 5
#define RELAY_PIN 16

void setup() {
  // initialize GPIO 2 as an output.
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN,OUTPUT);
  digitalWrite(RELAY_PIN,LOW);
  digitalWrite(LED_PIN,HIGH);
  Serial.begin(115200);
  delay(100);
  Serial.println();
  Serial.println();
  Serial.println("Using relay GPIO # "+String(RELAY_PIN));
  Serial.println("GPIO register size: "+String(sizeof(GPOC))+" bytes");
  delay(100);
}

// the loop function runs over and over again forever
void loop() {
//  while(true) yield();
  static unsigned long lastMillis = millis();
  static bool state = HIGH;
  if(millis()-lastMillis >= 1000) {
    lastMillis = millis();
    state = !state;
    digitalWrite(RELAY_PIN,state);
    digitalWrite(LED_PIN,!state);
  }
}
