const int JoyStick_pin = 8; //plug Joystick 'Button' into pin 8
const int X_pin = A0;       //plug joystick X direction into pin A0
const int Y_pin = A1;       //plug joystick Y direction into pin A1
int xc;
int yc;
int JSButton;

void setup() {
  for (int i = 0; i < 2; i++) {
    pinMode(JoyStick_pin, INPUT);
  }
  
  Serial.begin(115200);
}

void loop() {
  int x = analogRead(X_pin);  //read x direction value and -517 to bring back to around 0
  int y = analogRead(Y_pin);  //read y direction value and -512 to bring back to around 0

  if (x < 10) {         //joystick has off set of +/-8 so this negates that
    xc = 0;             //turn analogue value into integer. 0, 1 or 2 depending on state
  } else if (x > 1000) {   
    xc = 2;
  } else {
    xc = 1;
  }

  if (y > 1000) {
    yc = 0;
  } else if (y < 10) {
    yc = 2;
  } else {
    yc = 1;
  }

  Serial.print("S");  //start printing the data, format is Sxc,yc,buttonStates > S1,1,0
  Serial.print(xc);
  Serial.print(",");
  Serial.print(yc);
  Serial.print(",");
  Serial.println("0");

  delay(40);

}
