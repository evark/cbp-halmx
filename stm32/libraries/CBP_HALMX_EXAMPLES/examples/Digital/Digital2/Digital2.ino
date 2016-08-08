/*
 * BEWARE - BluePill does not have BUTTON, define it!!!
 */
 
int dtime;

void setup()
{
  pinMode(PIN_LED,OUTPUT);
  pinMode(BUTTON, INPUT);
}


void loop()
{
    if ( digitalRead(BUTTON) )
        dtime=50;
    else
        dtime=200;

    digitalWrite(PIN_LED,LOW);
    delay(dtime);
    digitalWrite(PIN_LED,HIGH);
    delay(dtime);
}
