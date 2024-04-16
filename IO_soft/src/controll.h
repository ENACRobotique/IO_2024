#ifndef CONTROLL_H
#define CONTROLL_H

#include <Servo.h>
#include "config.h"

void init_sequence(int s1,int s2,int s3,int s4,int s5,int s6,int axLeft,int axRight)
{
    // position initiale a prendre par tout les actionneurs ( envoyé depuis le haut niveau pour pas avoir a re flash )
}

void move_servo(Servo servo, int value)
{
    // move le servo pour la pince
    servo.writeMicroseconds(value)
}

void lift(int AX12,int val)
{
    // move l'ax
    AX12A_serial.moveSpeed(AX12,val,AX_SPEED);
}

#endif /*CONTROLL_H*/