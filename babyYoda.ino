#include <Servo.h>

Servo headn; 
Servo heads;

//int pos = 1;
  char pos;

void setup() {
  // put your setup code here, to run once:
  // set your servo to a pin...
  //'servoname'.attach(pin#)

  headn.attach(13);
  heads.attach(12);
       
}

void loop() 
{
//  Testing...
//  for(int angle = 140; angle < 180; angle++)  
//  {                                  
//    headn.write(angle);               
//    delay(15);                   
//  } 
//  for(int angle = 180; angle > 140; angle--)    
//  {                                
//    headn.write(angle);           
//    delay(15);       
//  } 
//     for(int angle = 0; angle<180; angle++)
//     {
//        heads.write(angle);
//        delay(30);
//     }
//     for(int angle = 180; angle>0; angle--)
//     {
//        heads.write(angle);
//        delay(30);
//     }     

//  Actual Code...
  switch (pos) 
  {
  case 'N':
    for(int angle = 140; angle < 180; angle++)  
    {                                  
       headn.write(angle);               
       delay(15);                   
    } 
    for(int angle = 180; angle > 140; angle--)    
    {                                
       headn.write(angle);           
       delay(15);       
    } 
   break;
  case 'S':
    for(int angle = 0; angle<180; angle++)
    {
        heads.write(angle);
        delay(30);
    }
    for(int angle = 180; angle>0; angle--)
    {
        heads.write(angle);
        delay(30);
    }
   break;
  default:
    // if nothing else matches, do the default
    // default is optional
    break;
  }
  
}
