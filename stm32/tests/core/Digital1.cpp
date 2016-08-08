#include<Arduino.h>

void setup()
{

  pinMode(PIN_LED,OUTPUT);

}


void loop()
{
    digitalWrite(PIN_LED,LOW);
    delay(50);
    digitalWrite(PIN_LED,HIGH);
    delay(50);
}
