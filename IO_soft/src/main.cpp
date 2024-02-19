#include <Arduino.h>
#include "../lib/metro.h"
#include "AX12A.h"
#include <Servo.h>

#define MAG3 PA11
#define MAG2 PB8
#define MAG1 PB9

#define STEPPER_2_STP PC1
#define STEPPER_2_DIR PC0

#define AX12A_PIN PC4

#define POT_UP 550
#define POT_DOWN 210

#define PINCE_UP 975
#define PINCE_MID 570
#define PINCE_DOWN 360

#define SERVO1_PIN PA7
#define SERVO1_OPEN 760
#define SERVO1_CLOSED 1140

#define SERVO2_PIN PA8
#define SERVO2_OPEN 1500
#define SERVO2_CLOSED 1800

#define SERVO3_PIN PA9
#define SERVO3_OPEN 1200
#define SERVO3_CLOSED 1516

Metro tic_tac(2000); // timer exécuté toutes les 1 sec
DynamixelSerial AX12A_s;
int AX_pince = 7;
int AX_pot = 5;
Servo servo1;
Servo servo2;
Servo servo3;
void setup() 
{
    pinMode(STEPPER_2_DIR,OUTPUT);
    pinMode(STEPPER_2_STP,OUTPUT);
    digitalWrite(STEPPER_2_DIR,HIGH);
    pinMode(MAG1,OUTPUT);
    pinMode(MAG2,OUTPUT);
    pinMode(MAG3,OUTPUT);
    pinMode(LED_BUILTIN,OUTPUT);

    // servo1.attach(SERVO1_PIN);
    // servo2.attach(SERVO2_PIN);
    // servo3.attach(SERVO3_PIN);
    
    Serial.begin(115200);

}

void loop() 
{
    if(tic_tac.check())
    {
        digitalToggle(LED_BUILTIN);


        digitalToggle(MAG1);
        digitalToggle(MAG2);
        digitalToggle(MAG3);
        
    }
    // servo1.writeMicroseconds(SERVO1_CLOSED);
    // delay(1000);
    // servo1.writeMicroseconds(SERVO1_OPEN);
    // delay(1000);
    
}
