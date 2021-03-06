//Pins Connected to the H bridge Vccpins;
const int LMotor_PWM = A3;
const int RMotor_PWM = A2;

//Pins for foward annd backwards motion for each motor
const int LMotor_FPIN = 21;
const int LMotor_BPIN = 20;


const int RMotor_FPIN = 8;
const int RMotor_BPIN = 7;

int DELAY = 1500;

void setup() {
  pinMode(LMotor_FPIN , OUTPUT);
  pinMode(LMotor_BPIN , OUTPUT);

  pinMode(RMotor_FPIN , OUTPUT);
  pinMode(RMotor_BPIN , OUTPUT);

  pinMode(LMotor_PWM, OUTPUT);
  pinMode(RMotor_PWM, OUTPUT);
}

void loop() {
  
      analogWrite(LMotor_PWM, 191);
      analogWrite(RMotor_PWM, 64);
    
      
      digitalWrite(RMotor_FPIN, HIGH);
      digitalWrite(RMotor_BPIN, LOW);
        
      digitalWrite(LMotor_FPIN, HIGH);
      digitalWrite(LMotor_BPIN, LOW);
    
      delay(DELAY);

      analogWrite(LMotor_PWM, 64);
      analogWrite(RMotor_PWM, 191);

      digitalWrite(RMotor_FPIN, HIGH);
      digitalWrite(RMotor_BPIN, LOW);
        
      digitalWrite(LMotor_FPIN, HIGH);
      digitalWrite(LMotor_BPIN, LOW);
    
      delay(DELAY);

      analogWrite(LMotor_PWM, 255);
      analogWrite(RMotor_PWM, 255);
    
      
      digitalWrite(RMotor_FPIN, HIGH);
      digitalWrite(RMotor_BPIN, LOW);
        
      digitalWrite(LMotor_FPIN, LOW);
      digitalWrite(LMotor_BPIN, LOW);
    
      delay(DELAY);

      digitalWrite(RMotor_FPIN, LOW);
      digitalWrite(RMotor_BPIN, LOW);
        
      digitalWrite(LMotor_FPIN, HIGH);
      digitalWrite(LMotor_BPIN, LOW);
    
      delay(DELAY);

      analogWrite(LMotor_PWM, 64);
      analogWrite(RMotor_PWM, 255);
    
      
      digitalWrite(RMotor_FPIN, LOW);
      digitalWrite(RMotor_BPIN, HIGH);
        
      digitalWrite(LMotor_FPIN, LOW);
      digitalWrite(LMotor_BPIN, HIGH);
    
      delay(DELAY);

      analogWrite(LMotor_PWM, 127);
      analogWrite(RMotor_PWM, 64);

      digitalWrite(RMotor_FPIN, LOW);
      digitalWrite(RMotor_BPIN, HIGH);
        
      digitalWrite(LMotor_FPIN, LOW);
      digitalWrite(LMotor_BPIN, HIGH);
    
      delay(3000);
    
    
    
    
}
