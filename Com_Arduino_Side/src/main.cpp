#include "Arduino.h"

#define BAUD 9600
#define DELAY_TIME 1000

const char* helloWorld = "Hello, world!";
uint64_t counter = 0;


void setup() {
  Serial.begin(BAUD);
}

void loop() {
  counter += 1;
  Serial.print("#");
  Serial.println(counter);
  delay(DELAY_TIME);
}
