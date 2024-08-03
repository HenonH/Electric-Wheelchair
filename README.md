This repository contains code for controlling the electric wheelchair at Saint Pat's using two different setups:

wheelchairDefault.ino:
  For arduino uno, controls wheelchair using PWM signals and an analog joystick

  
Folder (removed while i edit):
  For D1 mini and Arduino Uno
  Contains code for controlling the wheelchair using a D1 Mini.
  D1 Mini communicates with an Arduino via a web server and allows control of the motors using a phone. 
  Note that this code is still under development and requires a logic converter to convert the 3.3V signals from the D1 Mini into 5V signals that the Arduino can understand.
