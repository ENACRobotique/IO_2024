#include <Arduino.h>
#include "metro.h"
#include "AX12A.h"
#include <Servo.h>
#include "config.h"
#include "controll.h"

Metro tic_tac(1000); // timer exécuté toutes les 1 sec
DynamixelSerial AX12A_serial;
Servo servo_pot_1;
Servo servo_pot_2;
Servo servo_pot_3;
Servo servo_pot_4;
Servo servo_bras;
Servo servo_pano;


void setup() 
{

    pinMode(LED_BUILTIN,OUTPUT);
    
    Serial.begin(115200);

    //mettre dans init_sequence

    AX12A_serial.init(&Serial3);
    servo_pot_1.attach(SERVO1);
    servo_pot_2.attach(SERVO2);
    servo_pot_3.attach(SERVO3);
    servo_pot_4.attach(SERVO4);
    servo_bras.attach(SERVO5);
    servo_pano.attach(SERVO6);

    delay(500);

    
    AX12A_serial.moveSpeed(AX_PINCE,PINCE_UP,AX_SPEED);
    
    delay(3000);
    
}



void loop() 
{
    
}
