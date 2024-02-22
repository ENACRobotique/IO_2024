#include <Arduino.h>
#include "metro.h"
#include "AX12A.h"
#include <Servo.h>
#include "config.h"


Metro tic_tac(1000); // timer exécuté toutes les 1 sec
DynamixelSerial AX12A_s;
Servo servo1;
Servo servo2;
Servo servo3;
bool up = false;
void setup() 
{
    pinMode(MAG1,OUTPUT);
    pinMode(MAG2,OUTPUT);
    pinMode(MAG3,OUTPUT);
    pinMode(LED_BUILTIN,OUTPUT);

    // servo1.attach(SERVO1_PIN);
    // servo2.attach(SERVO2_PIN);
    // servo3.attach(SERVO3_PIN);
    
    Serial.begin(115200);
    AX12A_s.init(&Serial3);
    servo1.attach(SERVO1_PIN);
    servo2.attach(SERVO2_PIN);
    servo3.attach(SERVO3_PIN);
    delay(500);

    // init sequence  :

    
    AX12A_s.moveSpeed(AX_PINCE,PINCE_UP,AX_SPEED);
    AX12A_s.moveSpeed(AX_POT,POT_DOWN,AX_SPEED);
    servo1.writeMicroseconds(SERVO1_CLOSED);
    servo2.writeMicroseconds(SERVO2_CLOSED);
    servo3.writeMicroseconds(SERVO3_CLOSED);
    digitalWrite(MAG1,LOW);
    digitalWrite(MAG2,LOW);
    digitalWrite(MAG3,LOW);
    
    delay(3000);
    
}

void loop() 
{

    //test grab 1 plante
    // attraper les plantes 1 puis 2 puis 3 
    
    //1
    servo1.writeMicroseconds(SERVO1_OPEN);
    delay(3000);
    AX12A_s.moveSpeed(AX_PINCE,PINCE_DOWN,AX_SPEED); // descend 
    delay(1000);
    servo1.writeMicroseconds(SERVO1_CLOSED); // attrape la plante
    delay(500);
    AX12A_s.moveSpeed(AX_PINCE,PINCE_UP,AX_SPEED); // remonte
    delay(2000);

    //2 
    servo2.writeMicroseconds(SERVO2_OPEN);
    delay(3000);
    AX12A_s.moveSpeed(AX_PINCE,PINCE_DOWN,AX_SPEED); // descend 
    delay(1000);
    servo2.writeMicroseconds(SERVO2_CLOSED); // attrape la plante
    delay(500);
    AX12A_s.moveSpeed(AX_PINCE,PINCE_UP,AX_SPEED); // remonte
    delay(2000);
    
    //3
    servo3.writeMicroseconds(SERVO3_OPEN);
    delay(3000);
    AX12A_s.moveSpeed(AX_PINCE,PINCE_DOWN,AX_SPEED); // descend 
    delay(1000);
    servo3.writeMicroseconds(SERVO3_CLOSED); // attrape la plante
    delay(500);
    AX12A_s.moveSpeed(AX_PINCE,PINCE_UP,AX_SPEED); // remonte
    delay(2000);
    

    // pose dans les pots
    AX12A_s.moveSpeed(AX_PINCE,PINCE_MID,AX_SPEED); //decend les plantes dans les pots
    delay(1000);
    digitalWrite(MAG1,HIGH); //attrape le pot
    digitalWrite(MAG2,HIGH); //attrape le pot
    digitalWrite(MAG3,HIGH); //attrape le pot
    servo1.writeMicroseconds(SERVO1_OPEN); // lache la plante
    servo2.writeMicroseconds(SERVO2_OPEN); // lache la plante
    servo3.writeMicroseconds(SERVO3_OPEN); // lache la plante
    delay(1000);
    AX12A_s.moveSpeed(AX_PINCE,PINCE_UP,AX_SPEED); // remonte
    delay(1000);
    servo1.writeMicroseconds(SERVO1_CLOSED); // referme la pince
    servo2.writeMicroseconds(SERVO2_CLOSED); // referme la pince
    servo3.writeMicroseconds(SERVO3_CLOSED); // referme la pince
    delay(1000);

    // pose les pots
    AX12A_s.moveSpeed(AX_POT,POT_UP,AX_SPEED); // monte le pot
    delay(2000);
    digitalWrite(MAG1,LOW); //lache le pot
    digitalWrite(MAG2,LOW); //lache le pot
    digitalWrite(MAG3,LOW); //lache le pot
    delay(3000);
    AX12A_s.moveSpeed(AX_POT,POT_DOWN,AX_SPEED); // rentre le bras
    delay(2000);



    // if(tic_tac.check())
    // {
    //     servo1.writeMicroseconds(up ? (int)SERVO1_OPEN : (int)SERVO1_CLOSED);
    //     servo2.writeMicroseconds(up ? (int)SERVO2_OPEN : (int)SERVO2_CLOSED);
    //     servo3.writeMicroseconds(up ? (int)SERVO3_OPEN : (int)SERVO3_CLOSED);
        
    //     digitalToggle(LED_BUILTIN);
    //     up = !up;

        
    //     // digitalToggle(MAG2);
    //     // digitalToggle(MAG3);
        
    // }
    
}
