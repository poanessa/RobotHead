/*******************************************************
 * Program: head_control
 * Author: Daniel Diaz
 * This program will control the movement of the eyes
 * for the copernicus robot. Tested using an Arduino Mega
 *******************************************************/

#include <Servo.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

//define the 4 servos for the eyes and eyelids
Servo s1, s2, s3, s4, s5, s6, s7;
String in;
void blinkBoth(void);
void lookLeft(void);
void lookRight(void);
void crossEyes(void);
void lookApart(void);
void closeEyes(void);
void openEyes(void);
void openMid(void);
void lookStraight(void);
void smile(void);
void relax(void);
void openMouth(void);
void closeMouth(void);


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

  relax();
  lookStraight();
  openEyes();
  
  Serial.begin(9600);
}

void loop() {
    while (Serial.available() > 0) {
    //read the string from the serial port
    in = Serial.readString();
    //remove the garbage from the end of the input
    in.trim();
    in.toLowerCase();

    if(in == "happy"){
        openEyes();
        smile();
        delay(1000);
    }
    else if(in == "mad"){
      //close eyes 50%
      relax();
      openMid();
      delay(1000);
    }
    else if(in == "nothing")
    {
      relax();
      openEyes();
      lookApart();
      delay(500);
      closeEyes();
      delay(200);
      crossEyes();
      openEyes();
      delay(1000);
      lookStraight();
    }else
    {
      relax();
      closeEyes();
      s6.write(90);
      delay(1000);
    }


    //print, replace this will emotion functions and case statement
    Serial.print(in);
  }
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
void closeEyes(void)
{
  s1.write(160);
  s2.write(140);
  delay(200);
}
void openEyes(void)
{
  s1.write(115);
  s2.write(180);
  delay(200);
}
void openMid(void)
{
  s1.write(137);
  s2.write(160);
  delay(200);
}
void lookLeft(void)
{
  s3.write(100);
  s4.write(60);
  delay(200);
}
void lookRight(void)
{
  s3.write(150);
  s4.write(100);
  delay(200);
}
void lookStraight(void)
{
  s3.write(125);
  s4.write(80);
  delay(200);
}
void lookApart(void)
{
  s3.write(100);
  s4.write(100);
  delay(200);
}
void crossEyes(void)
{
  s3.write(150);
  s4.write(60);
  delay(200);
}
void smile(void)
{
    //smile
  s5.write(74);
  s6.write(90);
  delay(200);
}
void relax(void)
{
  s5.write(145);
  s6.write(0);
  delay(200);
}
void openMouth(void)
{
  //open Mouth
  s7.write(0);
  delay(200);
}
void closeMouth(void)
{
  //close Mouth
  s7.write(70);
  delay(200);

}

// below are the speaking facial motions

void speakA(void)
{
  //lips for A sound
  s7.write(70);
  s5.write(75);
  s6.write(90);
  delay(200);
}

void speakO(void)
{
  //lips for O sound
  s7.write(70);
  s5.write(145);
  s6.write(0);
  delay(200);
}

void speakE(void)
{
  //lips for E sound
  s7.write(50);
  s5.write(75);
  s6.write(90);
  delay(200);
}

void speakWR(void)
{
  //lips for W or R sound
  s7.write(50);
  s5.write(145);
  s6.write(0);
  delay(200);
}

void speakTS(void)
{
  //lips for T or S sound
  s7.write(20);
  s5.write(65);
  s6.write(80);
  delay(200);
}

void speakLN(void)
{
  //lips for L or N sound
  s7.write(65);
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
  s7.write(0);
  s5.write(145);
  s6.write(0);
  delay(200);
}

void speakFV(void)
{
  //lips for F or V sound
  s7.write(25);
  s5.write(50);
  s6.write(70);
  delay(200);
}
