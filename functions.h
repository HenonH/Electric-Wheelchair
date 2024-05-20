#define xValue 5
#define yValue 6


// **************************** FUNCTION FOR FORWARD AND BACKWARD MOTIONS **************************** //
void send_y(int y){
  y=map(y,-200, 200, 0, 1023);
  analogWrite(yValue,y);
}

// **************************** FUNCTION FOR TURNING MOTIONS **************************** //
void send_x(int x){
  x=map(x,-200,200,0,1023);
  analogWrite(xValue,x);
}
