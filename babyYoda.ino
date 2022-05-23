#include <Servo.h>

Servo nod;
Servo shake;

Servo revL; 
Servo waveL;

Servo revR;
Servo waveR;

void setup() {
  // put your setup code here, to run once:
  // set your servo to a pin...
  //'servoname'.attach(pin#)
  
 nod.attach(13);
 shake.attach(12);
  
 revL.attach(8);
 waveL.attach(9);
 
 revR.attach(4);
 waveR.attach(3);
}

void loop() 
{
  //  Script for waving hands simultaneously, "crazy Yoda"
    for(int angle = 180; angle>0; angle--)
    {
      revL.write(angle);
      revR.write(angle);
      delay(20);
    }
    for(int angle = 110; angle<140; angle++)
    {
      waveL.write(angle);
      delay(10);
    }
    for(int angle = 140; angle>110; angle--)
    {
      waveL.write(angle);
      delay(10);
    }
      for(int angle = 110; angle<140; angle++)
    {
      waveL.write(angle);
      delay(10);
    }
    for(int angle = 140; angle>110; angle--)
    {
      waveL.write(angle);
      delay(10);
    }      
     for(int angle = 0; angle<180; angle++)
    {
      revL.write(angle);
      revR.write(angle);
      delay(20);
    }
    for(int angle = 90; angle<130; angle++)
    {
      waveR.write(angle);
      delay(10);
    }
    for(int angle = 130; angle>90; angle--)
    {
      waveR.write(angle);
      delay(10);
    }
      for(int angle = 90; angle<130; angle++)
    {
      waveR.write(angle);
      delay(10);
    }
    for(int angle = 130; angle>90; angle--)
    {
      waveR.write(angle);
      delay(10);
    }

  
//  Script for Reaching the Ball/*The FORCE*
//    for(int angle = 0; angle<180; angle++)
//    {
//      revR.write(angle);
//      delay(10);
//    }
//    for(int angle = 100; angle>50; angle--)
//    {
//      shake.write(angle);
//      delay(30);
//    }
//    for(int angle = 180; angle>130; angle--)
//    {
//      revR.write(angle);
//      delay(20);
//    }
//    //delay(3000);
//    for(int angle = 130; angle<180; angle++)
//    {
//      revR.write(angle);
//      delay(20);
//    }
//    for(int angle = 50; angle<110; angle++)
//    {
//      shake.write(angle);
//      delay(30);
//    }
//    for(int angle = 180; angle>0; angle--)
//    {
//      revR.write(angle);
//      delay(20);
//    }
//    
//    delay(1000);

  //  Testing for Head...

//  for(int angle = 90; angle < 120; angle++)  
//  {                                  
//    nod.write(angle);               
//    delay(20);                   
//  } 
//  for(int angle = 120; angle > 90; angle--)    
//  {                                
//    nod.write(angle);           
//    delay(20);       
//  } 
  //nod.write(90);
//  for(int angle = 50; angle<150; angle++)
//  {
//    shake.write(angle);
//    delay(30);
//  }
//  for(int angle = 150; angle>50; angle--)
//  {
//    shake.write(angle);
//    delay(30);
//  }  


////Testing for Hand...
  delay(1000);
  for(int angle = 180; angle>0; angle--)
  {
    revL.write(angle);
    delay(25);
  }      
  for(int angle = 110; angle<140; angle++)
  {
    waveL.write(angle);
    delay(10);
  }
  for(int angle = 140; angle>110; angle--)
  {
    waveL.write(angle);
    delay(10);
  }
  for(int angle = 0; angle<180; angle++)
  {
    revL.write(angle);
    delay(25);
  }

//  for(int angle = 0; angle<180; angle++)
//  {
//    revR.write(angle);
//    delay(25);
//  }       
//  for(int angle = 90; angle<130; angle++)
//  {
//    waveR.write(angle);
//    delay(10);
//  }
//  for(int angle = 130; angle>90; angle--)
//  {
//    waveR.write(angle);
//    delay(10);
//  }
//    for(int angle = 90; angle<130; angle++)
//  {
//    waveR.write(angle);
//    delay(10);
//  }
//  for(int angle = 130; angle>90; angle--)
//  {
//    waveR.write(angle);
//    delay(10);
//  }
//  for(int angle = 180; angle>0; angle--)
//  {
//    revR.write(angle);
//    delay(25);
//  }

  
}
