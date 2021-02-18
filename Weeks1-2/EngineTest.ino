using namespace std;


const int LMotor_FPIN = 21;
const int LMotor_BPIN = 20;

int mSpeed = 200;


const int RMotor_FPIN = 11;
const int RMotor_BPIN = 10;


void setup() {
  pinMode(LMotor_FPIN , OUTPUT);
  pinMode(LMotor_BPIN , OUTPUT);

  pinMode(RMotor_FPIN , OUTPUT);
  pinMode(RMotor_BPIN , OUTPUT);

  Serial.begin(9600);
  
}

char INPut;

void loop() {


  int i =0;

  INPut=Serial.read();

  if (INPut == 'F'){
    while(i < 3){
      digitalWrite(RMotor_FPIN, HIGH);
      digitalWrite(RMotor_BPIN, LOW);
  
      digitalWrite(LMotor_FPIN, HIGH);
      digitalWrite(LMotor_BPIN, LOW);
      i++;
      delay(500);
    }
  }

  if (INPut == 'B'){
    while(i < 3){
      digitalWrite(RMotor_FPIN, LOW);
      digitalWrite(RMotor_BPIN, HIGH);
  
      digitalWrite(LMotor_FPIN, LOW);
      digitalWrite(LMotor_BPIN, HIGH);
      i++;
      delay(500);
    }
  }

   if (INPut == 'R'){
    while(i < 2){
      digitalWrite(RMotor_FPIN, LOW);
      digitalWrite(RMotor_BPIN, LOW);
  
      digitalWrite(LMotor_FPIN, HIGH);
      digitalWrite(LMotor_BPIN, LOW);
      i++;
      delay(500);
    }
   }

   if (INPut == 'L'){
    while(i < 2){
      digitalWrite(RMotor_FPIN, HIGH);
      digitalWrite(RMotor_BPIN, LOW);
  
      digitalWrite(LMotor_FPIN, LOW);
      digitalWrite(LMotor_BPIN, LOW);
      i++;
      delay(500);
    }
  }
  
  digitalWrite(RMotor_FPIN, LOW);
  digitalWrite(RMotor_BPIN, LOW);

  digitalWrite(LMotor_FPIN, LOW);
  digitalWrite(LMotor_BPIN, LOW);


}
