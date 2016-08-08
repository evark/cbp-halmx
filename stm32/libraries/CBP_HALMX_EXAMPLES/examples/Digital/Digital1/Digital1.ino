void setup()
{

  pinMode(LEDPIN,OUTPUT);

}


void loop()
{
    digitalWrite(LEDPIN,LOW);
    HAL_Delay(50);
    digitalWrite(LEDPIN,HIGH);
    HAL_Delay(50);
}
