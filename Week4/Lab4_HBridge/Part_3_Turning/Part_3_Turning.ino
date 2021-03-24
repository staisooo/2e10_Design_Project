/**********************************************************
 EE Lab 4 Part 2: 
I put a 3 s delay for each condition.
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
  // soft turn left
  analogWrite(LHS_Red, 0);
  analogWrite(LHS_Black, 0);
  analogWrite(RHS_Red, 0);
  analogWrite(RHS_Black, 128);
  delay(2000);
  brake_wheels();

  // soft turn right
  analogWrite(LHS_Red, 0);
  analogWrite(LHS_Black, 128);
  analogWrite(RHS_Red, 0);
  analogWrite(RHS_Black, 0);
  delay(2000);
  brake_wheels();
  
  // hard turn left
  analogWrite(LHS_Red, 0);
  analogWrite(LHS_Black, 0);
  analogWrite(RHS_Red, 0);
  analogWrite(RHS_Black, 255);
  delay(2000);
  brake_wheels();
  
  // hard turn right
  analogWrite(LHS_Red, 0);
  analogWrite(LHS_Black, 255);
  analogWrite(RHS_Red, 0);
  analogWrite(RHS_Black, 0);
  delay(2000);
  brake_wheels();
  
  // hard turn left while reversing
  analogWrite(LHS_Red, 128);
  analogWrite(LHS_Black, 0);
  analogWrite(RHS_Red, 128);
  analogWrite(RHS_Black, 0);
  delay(2000);
  analogWrite(LHS_Red, 255);
  analogWrite(LHS_Black, 0);
  analogWrite(RHS_Red, 128);
  analogWrite(RHS_Black, 0);
  delay(3000);
  brake_wheels();

  // hard turn right while reversing
  analogWrite(LHS_Red, 128);
  analogWrite(LHS_Black, 0);
  analogWrite(RHS_Red, 128);
  analogWrite(RHS_Black, 0);
  delay(2000);
  analogWrite(LHS_Red, 128);
  analogWrite(LHS_Black, 0);
  analogWrite(RHS_Red, 255);
  analogWrite(RHS_Black, 0);
  delay(3000);
  brake_wheels();
}

void brake_wheels() {
  analogWrite(LHS_Red, 0);
  analogWrite(LHS_Black, 0);
  analogWrite(RHS_Red, 0);
  analogWrite(RHS_Black, 0);
  delay(3000);
};
