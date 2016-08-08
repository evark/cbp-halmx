void setup()
{

  pinMode(PIN_LED,OUTPUT);

}


void loop()
{
    digitalWrite(PIN_LED,LOW);
    HAL_Delay(50);
    digitalWrite(PIN_LED,HIGH);
    HAL_Delay(50);
}
