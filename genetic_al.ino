#include <Servo.h>
#include <time.h>
#include <stdlib.h>

//if our servos have restrictions on the range
//of motion, change these
#define lowerbound 5
#define upperbound 175
#define wait 500             //used in delay, in mS

//setup our servos
Servo servo1, servo2, servo3;

//declare the functions
void displayVars(unsigned int, unsigned int, unsigned int);
void crossover(unsigned int *, unsigned int *, unsigned int *, int);
void mutation(unsigned int *, unsigned int *, unsigned int *, int);
void testbounds(unsigned int *, unsigned int *, unsigned int *);

void setup() {
  Serial.begin(9600);           //setup serial communication for the monitor
  srand(time(NULL));            //set the seed for random
  
  servo1.attach(7);
  servo2.attach(6);
  servo3.attach(5);
}

void loop() {
  unsigned int s1, s2, s3;        //declare the output variables for our servos
  int i;

  //try to generate random numbers for our servos
  s1 = rand() * 13;
  srand(rand());
  s2 = rand() * rand();
  srand(rand());
  s3 = rand() + s2 * 8;

  while(1)
  {
    //if even
    if(i % 2 == 0)
    {
      mutation(&s1, &s2, &s3, i * 3); 
    }
    else
      crossover(&s1, &s2, &s3, i % 8);

    srand(rand());                //use random to seed the next call to random
    i = rand();                   //set i to a random number

    servo1.write(s1);
    servo2.write(s2);
    servo3.write(s3);
    delay(wait);
  
  }
  
}

void displayVars(unsigned int s1, unsigned int s2, unsigned int s3)
{
  Serial.print("s1 = ");
  Serial.print(s1, HEX);
  Serial.print(" s2 = ");
  Serial.print(s2,HEX);
  Serial.print(" s3 = ");
  Serial.println(s3, HEX);

}

//take in pointers to integers and set them using a crossover function depending on the number
//of crossovers wanted
void crossover(unsigned int *s1, unsigned int *s2, unsigned int *s3, int num)
{
    unsigned int p1, p2, c1, c2;

    //create parents using our inputs
    //whatever the number of crossovers, parents will always be the same
    p1 = (((*s1 << 4) | ((*s2 >> 4) & 0x0F)) & 0xFFF);
    p2 = (((*s2 << 8) | (*s3 & 0xFF)) & 0xFFF);

    //these if statements determine which crossover to use
    if(num <2)
    {
      c1 = p2;
      c2 = p1;
    }
    else if(num == 2)
    {
      c1 = ((p1 & 0xFC0) | (p2 & 0x3F));
      c2 = ((p1 & 0x3F) | (p2 & 0xFC0));
    }
    else if(num == 3)
    {
      c1 = ((p1 & 0xF0F) | (p2 & 0x0F0));
      c2 = ((p1 & 0x0F0) | (p2 & 0xF0F));      
    }
    else if(num == 4 || num == 5)
    {
      c1 = ((p1 & 0xE38) | (p2 & 0x1C7));
      c2 = ((p1 & 0x1C7) | (p2 & 0xE38));      
    }
    else if(num == 6)
    {
      c1 = ((p1 & 0xCCC) | (p2 & 0x333));
      c2 = ((p1 & 0x333) | (p2 & 0xCCC));      
    }
    else
    {    
      c1 = ((p1 & 0xAAA) | (p2 & 0x555));
      c2 = ((p2 & 0x555) | (p2 & 0xAAA));  
    }
    
    //set the servo pins
    *s1 = (c1 >> 4);
    *s2 = ((c1 & 0x0F) << 4) | ((c2 & 0xF00) >> 8);
    *s3 = (c2 & 0xFF);
}

//perform a mutation at a specified point
void mutation(unsigned int *s1, unsigned int *s2, unsigned int *s3, int num)
{
    unsigned int p1, p2;
    
    //create parents using our inputs
    p1 = (((*s1 << 4) | ((*s2 >> 4) & 0x0F)) & 0xFFF);
    p2 = (((*s2 << 8) | (*s3 & 0xFF)) & 0xFFF);

    //perform mutation
    p1 ^= (1 << (num % 12));
    p2 ^= (1 << (num % 12));

    //set the servo pins
    *s1 = (p1 >> 4);
    *s2 = ((p1 & 0x0F) << 4) | ((p2 & 0xF00) >> 8);
    *s3 = (p2 & 0xFF);  
}

//make sure the bounds are not being violated. Because we are using servos
//we cannot have outputs greater than upper bound or less than the lower bound
void testbounds(unsigned int *s1, unsigned int *s2, unsigned int *s3)
{
    //mask to get only a byte of information
    *s1 &= 0xFF;
    *s2 &= 0xFF;
    *s3 &= 0xFF;
    
    if(*s1 < lowerbound)
      *s1 += (lowerbound + 5);
    if(*s1 > upperbound)
      *s1 -= 128;
      
    if(*s2 < lowerbound)
      *s2 += (lowerbound + 5);
    if(*s2 > upperbound)
      *s2 -= 128;

    if(*s3 < lowerbound)
      *s3 += (lowerbound + 5);
    if(*s3 > upperbound)
      *s3 -= 128;
}

