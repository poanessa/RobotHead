/*******************************************************
 * Program: head_control_speaking
 * Author: Daniel Diaz/ Tuna Poanessa
 * This program will control the movement of the mouth
 * for the copernicus robot. Tested using an Arduino Mega
 *******************************************************/

#include <Servo.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

//define the 4 servos for the eyes and eyelids
Servo s1, s2, s3, s4, s5, s6, s7;

//Says "hello, my name is Copernicus"
String in;
//hello
void speakE(void);
void speakO(void);
void relax(void);l
void speakMBP(void);
void speakA(void);
void speakTS(void);
void speakR(void);
void speakLN(void);
void blinkBoth(void);
void lookStraight(void);
void openEyes(void);
void closeEyes(void);

void speakC(void);


void setup() {
  //associate each servo with PWM pin on board
  /*
  * Servo 1 and Servo 2 are the eyelids
  * Servo 1: Closed = 160, Open = 115
  * Servo 2: Closed = 140, Open = 180
  */
  s1.attach(2);           //bounds 115-160
  s2.attach(3);           //bounds 140-180
 /*Servo 3 and Servo 4 are the eyes
 * Servo 3: Left = 100, Right = 150
 * Servo 4: Left = 60, Right = 100
 */
  s3.attach(4);           //bounds 100-150
  s4.attach(5);           //bounds 60-100
  /*Servo 5 and 6 are lip sides
   * Servo 5(right): Relaxed = 145, Stretched = 75
   * Servo 6(left):  Relaxed = 0,   Stretched = 90
   */
  s5.attach(6);
  s6.attach(7);
  //Servo 7 is lip bottom: Open = 0, Closed = 70
  s7.attach(8);
  closeEyes();
  relax();
  lookStraight();
  openEyes();
  blinkBoth();
    
  Serial.begin(9600);
}

void loop() {
   //hello
   speakE();
   //delay(100);
   speakLN();
   //delay(100);
   speakO();
   //delay(100);
   relax();
   delay(1000);
   blinkBoth();

//my
  speakMBP();
  //delay(100);
  speakA();
  //delay(100);
  //speakE();
  //delay(100);
  relax();
  delay(500);
   blinkBoth();

//name
  speakLN();
  //delay(100);
  speakA();
  //delay(100);
  speakMBP();
  //delay(100);
  //speakE();
  //delay(100);
  relax();
  delay(500);
   blinkBoth();

//is
  speakA();
  //delay(100);
  relax();
  delay(500);
   blinkBoth();
  
//Copernicus
  speakC();
  //delay(100);
  speakMBP();
  //delay(100);
  speakR();
  //delay(100);
  speakLN();
  //delay(100);
  speakC();
  //delay(100);  
  speakO();
  //delay(100);
  speakS();
  //delay(100);
  relax();
  delay(5000);
   blinkBoth();
}


// below are the speaking facial motions

void speakA(void)
{
  //lips for A sound
  s7.write(30);
  s5.write(75);
  s6.write(90);
  delay(200);
}

void speakO(void)
{
  //lips for O sound
  s7.write(0);
  s5.write(145);
  s6.write(0);
  delay(200);
}

void speakE(void)
{
  //lips for E sound
  s7.write(20);
  s5.write(75);
  s6.write(90);
  delay(200);
}

void speakWR(void)
{
  //lips for W or R sound
  s7.write(50);
  s5.write(75);
  s6.write(90);
  delay(200);
}

void speakTS(void)
{
  //lips for T or S sound
  s7.write(50);
  s5.write(65);
  s6.write(80);
  delay(200);
}

void speakLN(void)
{
  //lips for L or N sound
  s7.write(40);
  s5.write(75);
  s6.write(90);
  delay(200);
}

void speakUQ(void)
{
  //lips for U or Q sound
  s7.write(35);
  s5.write(145);
  s6.write(0);
  delay(200);
}

void speakMBP(void)
{
  //lips for M, B, or P sound
  s7.write(70);
  s5.write(145);
  s6.write(0);
  delay(200);
}

void speakFV(void)
{
  //lips for F or V sound
  s7.write(60);
  s5.write(50);
  s6.write(70);
  delay(200);
}

void speakR(void)
{
  //lips for R sound
  s7.write(30);
  s5.write(145);
  s6.write(0);
  delay(200);
}

void speakS(void)
{
  //lips for S sound
  s7.write(70);
  s5.write(75);
  s6.write(90);
  delay(200);
}

void relax(void)
{
  //lips for S sound
  s7.write(70);
  s5.write(145);
  s6.write(0);
  delay(200);
}

void blinkBoth(void)
{
  s1.write(160);
  s2.write(140);
  delay(200);
  s1.write(115);
  s2.write(180);
  delay(200);  
 
}

void speakC(void)
{
  //lips for E sound
  s7.write(40);
  s5.write(65);
  s6.write(80);
  delay(200);
}

void openEyes(void)
{
  s1.write(105);
  s2.write(180);
  delay(200);
}
void lookStraight(void)
{
  s3.write(125);
  s4.write(80);
  delay(200);
}

void closeEyes(void)
{
  s1.write(160);
  s2.write(140);
  delay(200);
}
