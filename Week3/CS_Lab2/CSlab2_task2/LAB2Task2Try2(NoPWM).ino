volatile int LEYEcount =0;

volatile int REYEcount =0;

const int LEYE = 10;
const int REYE = 11;

const int LMotor_FPIN = 21;
const int LMotor_BPIN = 20;


const int RMotor_FPIN = 8;
const int RMotor_BPIN = 7;

void setup() {
  Serial.begin(9600);
  pinMode( LEYE, INPUT );
  pinMode( REYE, INPUT );

  pinMode(LMotor_FPIN, OUTPUT);
  pinMode(LMotor_BPIN, OUTPUT);
  pinMode(RMotor_FPIN, OUTPUT);
  pinMode(RMotor_BPIN, OUTPUT);

  // Turn off motors - Initial state
  digitalWrite(LMotor_FPIN, LOW);
  digitalWrite(LMotor_BPIN, LOW);
  digitalWrite(RMotor_FPIN, LOW);
  digitalWrite(RMotor_BPIN, LOW);

  
  /*attachInterrupt(digitalPinToInterrupt(LEYE), LEYEchange, CHANGE);
  attachInterrupt(digitalPinToInterrupt(REYE), REYEchange, CHANGE);*/
  
}

void LEYEchange(){
  LEYEcount = LEYEcount + 1;
  Serial.println("Change has occured");
}

void REYEchange(){
  REYEcount++;
  Serial.println("Change has occured");
}

void loop() {
{

  while ((digitalRead( LEYE ) == LOW ) && (digitalRead( REYE ) == LOW ))
  {

    // Set motors to maximum speed
    // For PWM maximum possible values are 0 to 255
    //analogWrite(enA, 255);
   //analogWrite(enB, 255);

    // Turn on motor A & B
    digitalWrite(LMotor_FPIN, HIGH);
    digitalWrite(LMotor_BPIN, LOW);
    digitalWrite(RMotor_FPIN, HIGH);
    digitalWrite(RMotor_BPIN, LOW);
  }

  while ((digitalRead( LEYE ) == HIGH ) && (digitalRead( REYE ) == HIGH ))
  {
    // Turn off motors
    digitalWrite(LMotor_FPIN, LOW);
    digitalWrite(LMotor_BPIN, LOW);
    digitalWrite(RMotor_FPIN, LOW);
    digitalWrite(RMotor_BPIN, LOW);
  }

  while ((digitalRead( LEYE ) == LOW ) && (digitalRead( REYE ) == HIGH ))
  {
    //turn left
    digitalWrite(LMotor_FPIN, HIGH);
    digitalWrite(LMotor_BPIN, LOW);
    digitalWrite(RMotor_FPIN, LOW);
    digitalWrite(RMotor_BPIN, LOW);
  }

  while ((digitalRead( LEYE ) == HIGH ) && (digitalRead( REYE ) == LOW ))
  {
    //turn right
    digitalWrite(LMotor_FPIN, LOW);
    digitalWrite(LMotor_BPIN, LOW);
    digitalWrite(RMotor_FPIN, HIGH);
    digitalWrite(RMotor_BPIN, LOW);
  }
}
}
