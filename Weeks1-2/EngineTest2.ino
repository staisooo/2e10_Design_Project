using namespace std;


const int LMotor_FPIN = 21;
const int LMotor_BPIN = 20;


const int RMotor_FPIN = 8;
const int RMotor_BPIN = 7;


void setup() {
  pinMode(LMotor_FPIN , OUTPUT);
  pinMode(LMotor_BPIN , OUTPUT);

  pinMode(RMotor_FPIN , OUTPUT);
  pinMode(RMotor_BPIN , OUTPUT);

  Serial.begin(9600);
  
}

char INPut;

void loop() {
  
  int F = 0;
  while (F != 4){
    digitalWrite(RMotor_FPIN, HIGH);
    digitalWrite(RMotor_BPIN, LOW);
    
    digitalWrite(LMotor_FPIN, HIGH);
    digitalWrite(LMotor_BPIN, LOW);

    delay(500);
    F++;
  }

  int L = 0;
  while (L != 2){
    digitalWrite(RMotor_FPIN, HIGH);
    digitalWrite(RMotor_BPIN, LOW);
    
    digitalWrite(LMotor_FPIN, LOW);
    digitalWrite(LMotor_BPIN, LOW);

    delay(500);
    L++;
  }

  int R = 0;
  while (R != 2){
    digitalWrite(RMotor_FPIN, LOW);
    digitalWrite(RMotor_BPIN, LOW);
    
    digitalWrite(LMotor_FPIN, HIGH);
    digitalWrite(LMotor_BPIN, LOW);

    delay(500);
    R++;
  }

  int B = 0;
  while (B != 4){
    digitalWrite(RMotor_FPIN, LOW);
    digitalWrite(RMotor_BPIN, HIGH);
    
    digitalWrite(LMotor_FPIN, LOW);
    digitalWrite(LMotor_BPIN, HIGH);

    delay(500);
    B++;
  }


}
