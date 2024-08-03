#include <Cytron_SmartDriveDuo.h>
#define AN1 5 // Arduino pin 5 is connected to MDDS30 pin AN1.   D5
#define AN2 6 // Arduino pin 6 is connected to MDDS30 pin AN2.  D5
#define IN1 7 // Arduino pin 7 is connected to MDDS30 pin IN1.  D7
#define IN2 8 // Arduino pin 8 is connected to MDDS30 pin IN2.   D7
#define joyX A1 // left/right effects
#define joyY A0 // back and forward movements
int xValue, yValue, hypotenuse;

Cytron_SmartDriveDuo smartDriveDuo30(PWM_INDEPENDENT, IN1, IN2, AN1, AN2);

void setup()
{
Serial.begin(9600);
}


void loop()
{
xValue=analogRead(joyX);  
yValue=analogRead(joyY);  //reads x and y from joystick (0,1023)

xValue=map(xValue,0,1023,-40,40); //its between -40 and 40 since we want the motors functioning at 40% power for full efficiency
yValue=map(xValue,0,1023,-40,40);
hypotenuse= sqrt(square(xValue)+square(yValue)); //when we turn one of the motors will be turning at this speed whereas the other will turn at a lower defualt speed

if (yValue>=0){
  if (0<=xValue){
    smartDriveDuo30.control(hypotenuse,yValue); //if we want to turn right, the left motor's speed will be the hypotonuse (higher)
    }
  else if (xValue<0){
    smartDriveDuo30.control(yValue,hypotenuse); //if we want to turn left, the right motor's speed will be the hypotonuse (higher)
    }
  }
else{
  if (0<=xValue){
    smartDriveDuo30.control(-1*hypotenuse,yValue); //if we are moving backwards and tilt the joystick left, the right motor's speed will be the hypotonuse (higher)
    }
  else if (xValue<0){
    smartDriveDuo30.control(yValue,-1*hypotenuse); //if we are moving backwards and tilt the joystick right, the left motor's speed will be the hypotonuse (higher)
    }
