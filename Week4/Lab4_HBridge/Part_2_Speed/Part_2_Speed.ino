/**********************************************************
 EE Lab 4 Part 2: 
3/4 speed is 191 for analogWrite
while 1/2 speed is about 128
I put a 1.5 s delay for each condition and 3 s for each
condition to run.
 **********************************************************/
// Red wire moves wheels backwards
// Black wire moves wheels forwards

// Motor A connections (Right Wheel)
const int RHS_Red = 6;
const int RHS_Black = 5;
// Motor B connections (Left Wheel)
const int LHS_Red = 2;  
const int LHS_Black = 12;

void setup() {
  Serial.begin(9600);
  //set all the motor control pins to outputs
  pinMode(LHS_Red, OUTPUT);
  pinMode(LHS_Black, OUTPUT);
  pinMode(RHS_Red, OUTPUT);
  pinMode(RHS_Black, OUTPUT);
}

void loop() {
  // forwards at 3/4 speed
  analogWrite(LHS_Red, 0);
  analogWrite(LHS_Black, 191);
  analogWrite(RHS_Red, 0);
  analogWrite(RHS_Black, 191);
  delay(3000);
  brake_wheels();
  
  // forwards at 1/2 speed
  analogWrite(LHS_Red, 0);
  analogWrite(LHS_Black, 128);
  analogWrite(RHS_Red, 0);
  analogWrite(RHS_Black, 128);
  delay(3000);
  brake_wheels();

  // backwards at 3/4 speed
  analogWrite(LHS_Red, 191);
  analogWrite(LHS_Black, 0);
  analogWrite(RHS_Red, 191);
  analogWrite(RHS_Black, 0);
  delay(3000);
  brake_wheels();
  
  // backwards at 1/2 speed
  analogWrite(LHS_Red, 128);
  analogWrite(LHS_Black, 0);
  analogWrite(RHS_Red, 128);
  analogWrite(RHS_Black, 0);
  delay(3000);
  brake_wheels();
  
}

void brake_wheels() {
  analogWrite(LHS_Red, 0);
  analogWrite(LHS_Black, 0);
  analogWrite(RHS_Red, 0);
  analogWrite(RHS_Black, 0);
  delay(1500);
};
