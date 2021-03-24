/**********************************************************
 EE Lab 4 Part 1: 
 There is a 1.5 second delay after every condition
 and each wheel will be run on full speed using the 
 digitalWrite() function.
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
  //set all the motor control pins to outputs
  pinMode(LHS_Red, OUTPUT);
  pinMode(LHS_Black, OUTPUT);
  pinMode(RHS_Red, OUTPUT);
  pinMode(RHS_Black, OUTPUT);
}

void loop() {
  digitalWrite(LHS_Red, LOW);
  digitalWrite(LHS_Black, HIGH);
  digitalWrite(RHS_Red, LOW);
  digitalWrite(RHS_Black, HIGH);
  delay(3000);
  brake_wheels();
  
  digitalWrite(LHS_Red, HIGH);
  digitalWrite(LHS_Black, LOW);
  digitalWrite(RHS_Red, HIGH);
  digitalWrite(RHS_Black, LOW);
  delay(3000);
  brake_wheels();
  
  digitalWrite(LHS_Red, HIGH);
  digitalWrite(LHS_Black, LOW);
  digitalWrite(RHS_Red, LOW);
  digitalWrite(RHS_Black, HIGH);
  delay(3000);
  brake_wheels();
  
  digitalWrite(LHS_Red, LOW);
  digitalWrite(LHS_Black, HIGH);
  digitalWrite(RHS_Red, HIGH);
  digitalWrite(RHS_Black, LOW);
  delay(3000);
  brake_wheels();
}

void brake_wheels() {
  digitalWrite(LHS_Red, LOW);
  digitalWrite(LHS_Black, LOW);
  digitalWrite(RHS_Red, LOW);
  digitalWrite(RHS_Black, LOW);
  delay(1500);
};
