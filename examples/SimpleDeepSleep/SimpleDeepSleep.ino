#include "LowPower.h"

#define SLEEP_PIN 0
#define WAKE_PIN A3

LowPower lowPower;


void goToSleep(){
    lowPower.deepSleep(); // lowPower.deepSleep();
}

void setup(){
    lowPower = LowPower();
    attachInterrupt(digitalPinToInterrupt(SLEEP_PIN), goToSleep, RISING);
    lowPower.enableWakeupFromPin(WAKE_PIN);
    pinMode(LED_BUILTIN, OUTPUT);

    

}

void loop(){
    digitalWrite(LED_BUILTIN, HIGH);
    lowPower.delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    lowPower.delay(100);

}