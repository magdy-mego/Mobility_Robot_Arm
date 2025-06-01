#include <Servo.h>

#define servo1 9
#define servo2 8
#define servo3 7
#define servo4 6

Servo mservo1, mservo2, mservo3, mservo4;

int pos = 0;
char Incoming_value = 0;
char usechar = "0";

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  
  mservo1.attach(servo1); // 150-50
  mservo2.attach(servo2); // 0-180
  mservo3.attach(servo3); // 40-120
  mservo4.attach(servo4); // 0-35

  //default servo position
  mservo1.write(100); //up-down
  mservo2.write(0); //left-right
  mservo3.write(80); //forward-back
  mservo4.write(0); //clamp
}

int srv1 = 100;
int srv2 = 0;
int srv3 = 80;
int srv4 = 0;

void loop() 
{

  if(Serial.available() > 0)  
  {
    Incoming_value = Serial.read();
    //Serial.println(Incoming_value);
    usechar = Incoming_value;
  }

  if(usechar=='0')
  {
    
  }
  
  if(usechar=='A')
  {
    if(srv1<150)
    {
      srv1++;
      mservo1.write(srv1);
      
      delay(10);
     }
  }
  
  if(usechar=='B')
  {
    if(srv1>50)
    {
      srv1--;
      mservo1.write(srv1);
      
      delay(10);
     }
  }

  if(usechar=='C')
  {
    if(srv2<180)
    {
      srv2++;
      mservo2.write(srv2);
      
      delay(10);
     }
  }

  if(usechar=='D')
  {
    if(srv2>0)
    {
      srv2--;
      mservo2.write(srv2);
      
      delay(10);
     }
  }

  if(usechar=='G')
  {
    if(srv3<120)
    {
      srv3++;
      mservo3.write(srv3);
      
      delay(10);
     }
   }
   
   if(usechar=='J')
   {
    if(srv3>40)
    {
      srv3--;
      mservo3.write(srv3);
      
      delay(10);
     }
   }

   //-----

   if(usechar=='F')
  {
    if(srv4<35)
    {
      srv4++;
      mservo4.write(srv4);
      
      delay(10);
     }
   }
   
   if(usechar=='I')
   {
    if(srv4>0)
    {
      srv4--;
      mservo4.write(srv4);
      
      delay(10);
     }
   }

   
      
}
