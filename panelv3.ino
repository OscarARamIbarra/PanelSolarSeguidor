#include <Servo.h>
//Definiendo Servos
Servo horizontal;
int servoh = 0;
int servohLimitHigh = 180;
int servohLimitLow = 10;

Servo vertical; 
int servov = 0; 
int servovLimitHigh = 60;
int servovLimitLow = 1;
//Asignando LDRs
int ldrtop = A2; //top LDR
int ldrbot = A1; //top right LDR
int ldrright = A3; // right LDR
int ldrleft = A0; // leftt LDR

 void setup () 
 {
  horizontal.attach(9);
  horizontal.write(0);
  vertical.attach(10);
  vertical.write(0);
  delay(500);
 }

void loop()
{
  //capturando valores analogicos de cada LDR
  int top = analogRead(ldrtop);
  int bot = analogRead(ldrbot);
  int right = analogRead(ldrright);
  int left = analogRead(ldrleft);
  // calculando el Promedio
  int avgtop = top; //Promedio del top LDRs
  int avgbot = bot; //Promedio del bottom LDRs
  int avgleft = left; //Promedio del left LDRs
  int avgright = right; //Promedio del right LDRs

  if (avgtop < avgbot)
  {
    vertical.write(++servov);
    if (servov > servovLimitHigh) 
     { 
      servov = servovLimitHigh;
     }
    delay(10);
  }
  else if (avgbot < avgtop)
  {
    vertical.write(--servov);
    if (servov < servovLimitLow)
  {
    servov = servovLimitLow;
  }
    delay(10);
  }
  else 
  {
    vertical.write(servov);
  }
  
  if (avgleft > avgright)
  {
    horizontal.write(++servoh);
    if (servoh > servohLimitHigh)
    {
    servoh = servohLimitHigh;
    }
    delay(10);
  }
  else if (avgright > avgleft)
  {
    horizontal.write(--servoh);
    if (servoh < servohLimitLow)
     {
     servoh = servohLimitLow;
     }
    delay(10);
  }
  else 
  {
    horizontal.write(servoh);
  }
  delay(50);
}
 

