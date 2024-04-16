#include <Arduino.h>
#include "metro.h"
#include "AX12A.h"
#include <Servo.h>
#include "config.h"

using namespace std;

// Msg format on 7 bytes ex : "2 1500\n"
#define BUFFER_SIZE 7

Metro tic_tac(1000); // timer exécuté toutes les 1 sec

DynamixelSerial AX12A_serial;
Servo servo_pot_1;
Servo servo_pot_2;
Servo servo_pot_3;
Servo servo_pot_4;
Servo servo_bras;
Servo servo_pano;

enum act 
{
  S_pot_1 = '1' ,
  S_pot_2 = '2',
  S_pot_3 = '3',
  S_pot_4 = '4',
  S_bras = '5',
  S_pano = '6',
  ax_L = '7' ,
  ax_R = '8'
};


void setup() 
{
    pinMode(LED_BUILTIN,OUTPUT);
    Serial.begin(115200);
    Serial1.begin(500000);
    
    AX12A_serial.init(&Serial1);
    servo_pot_1.attach(SERVO1_PIN);
    servo_pot_2.attach(SERVO2_PIN);
    servo_pot_3.attach(SERVO3_PIN);
    servo_pot_4.attach(SERVO4_PIN);
    servo_bras.attach(SERVO5_PIN);
    servo_pano.attach(SERVO6_PIN);

    delay(600);
    Serial.print(" Rédy");
}

void order(int actionneur, int valeur)
{
  switch (actionneur)
  {
  case S_pot_1:
    servo_pot_1.writeMicroseconds(valeur);
    digitalToggle(LED_BUILTIN);
    break;
  case S_pot_2:
    servo_pot_2.writeMicroseconds(valeur);
    digitalToggle(LED_BUILTIN);
    break;
  case S_pot_3:
    servo_pot_3.writeMicroseconds(valeur);
    digitalToggle(LED_BUILTIN);
    break;
  case S_pot_4:
    servo_pot_4.writeMicroseconds(valeur);
    digitalToggle(LED_BUILTIN);
    break;
  case S_bras:
    servo_bras.writeMicroseconds(valeur);
    digitalToggle(LED_BUILTIN);
    break;
  case S_pano:
    servo_pano.writeMicroseconds(valeur);
    digitalToggle(LED_BUILTIN);
    break;
  case ax_L:
    AX12A_serial.moveSpeed(AX_left,valeur,AX_SPEED);
    digitalToggle(LED_BUILTIN);
    break;
  case ax_R:
    AX12A_serial.moveSpeed(AX_right,valeur,AX_SPEED);
    digitalToggle(LED_BUILTIN);
    break;
  
  default:
    break;
  }
}

void receive_serial()
{
  char buffer[BUFFER_SIZE];
  if (Serial.available() > 0) 
  {
    Serial.readBytesUntil('\n',buffer,BUFFER_SIZE);

    int actionneur = buffer[0];
    
    buffer[0] = '0';
    buffer[1] = '0';
    char *output;
    int val = strtol(buffer,&output,10); // on converti la chaine de carractère en l'entier équivalent (pas ascii)
    order(actionneur,val);
  }
}

void loop() {receive_serial();}
