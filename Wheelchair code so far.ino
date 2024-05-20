#include <Cytron_SmartDriveDuo.h>
#define AN1 5 // Arduino pin 5 is connected to MDDS30 pin AN1.   D5
#define AN2 6 // Arduino pin 6 is connected to MDDS30 pin AN2.  D5
#define IN1 7 // Arduino pin 7 is connected to MDDS30 pin IN1.  D7
#define IN2 8 // Arduino pin 8 is connected to MDDS30 pin IN2.   D7
#define joyX A1 // left/right effects
#define joyY A0 // back and forward movements
int xValue, yValue;
Cytron_SmartDriveDuo smartDriveDuo30(PWM_INDEPENDENT, IN1, IN2, AN1, AN2);


void setup()
{
  Serial.begin(9600);
}


void loop()
{
  xValue=analogRead(joyX);
  yValue=analogRead(joyY);  
  if (xValue<=561 && xValue>=461) { //if x is in middle, move in the y only
    if (yValue>=551) {
        yValue = map(yValue, 561, 1023, 0, 50); //converts y to spwm values
        smartDriveDuo30.control(-1*yValue, .95*yValue); // left motor, right motor
    }
    else if (yValue<=461) {
      yValue = map(yValue, 471, 0, 0, -50); //converts y to spwm values      
        smartDriveDuo30.control(-1*yValue, .95*yValue); // left motor, right motor
    }
    else {
        smartDriveDuo30.control(0, 0);      
    }
  }
  else if (yValue>=471 && yValue<=561) { //if x is in middle, move in the y only
    if (xValue>=551) {
        xValue = map(xValue, 561, 1023, 0, -50); //converts y to spwm values
        smartDriveDuo30.control(xValue, .95*xValue); // left motor, right motor
    }
    else if (xValue<=461) {
      xValue = map(xValue, 461, 0, 0, 50); //converts y to spwm values      
        smartDriveDuo30.control(xValue, .95*xValue); // left motor, right motor
    }
  }  
  else  {
    smartDriveDuo30.control(0, 0);      
  }
}
