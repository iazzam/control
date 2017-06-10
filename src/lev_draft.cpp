int relayA = 7;
int relayB = 3;
void setup() {
    // put your setup code here, to run once:
    pinMode(relayA,OUTPUT);
    pinMode(relayB,OUTPUT);
    
}
void loop() {
    // put your main code here, to run repeatedly:
    ballValveControl(relayA, relayB, 1);
    ballValveControl(relayA, relayB, 1);
    
}
/* ballValveControl - Used to control motorized ball valve - levitation system
 *  Parameters
 *  ------------
 *  int relayA - GPIO pin assigned to relayA for control
 *  int relayB - GPIO pin assigned to relayB for control
 *  int setState - 0 to close valve, 1 to open valve
 *  ------------
 *  6 second delay for allowing valve to open/close
 *  Return for error handling
*/
int ballValveControl(int relayA, int relayB, int setState)
{
    if(setState == 1)
    {
        digitalWrite(relayA,LOW);
        digitalWrite(relayB,HIGH);
        delay(6000);
        
        return 1;
    }
    if(setState == 0)
    {
        digitalWrite(relayA,HIGH);
        digitalWrite(relayB,LOW);
        delay(6000);
        return 1;
    }
    return 0;
}