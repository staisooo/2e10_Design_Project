#include <PID_v2.h>

//motor a connections 
const int enA = 9;
const int in1 = 8;
const int in2 = 7;
//motor b connections
const int enB = 3;
const int in3 = 4;
const int in4 = 5;

const int minSpeed = 100;
const int maxSpeed = 255;

long duration;

int trigPin = 11;
int echoPin = 10;

double kp = 5 ;
double ki = 1 ;
double kd = 0 ;

double distance, output, setPoint;
PID myPID(&distance, &output, &setPoint, kp, ki, kd, DIRECT);
int currentSpeed, previousSpeed;

//double computePID(double inp);
double getDistance();
//void setMotorSpeed(int speed);

void setup(){
  Serial.begin(9600);
  distance = getDistance();
  setPoint = 30;
  currentSpeed = maxSpeed;
  previousSpeed = maxSpeed;
  myPID.SetMode(AUTOMATIC);
  
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(trigPin, OUTPUT);         
  pinMode(echoPin, INPUT);  

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop()
{
  distance = getDistance();
  myPID.Compute();
  if(distance > setPoint)
  {
    setForwardSpeed(maxSpeed);
  }
  
  if (distance <= 13 && distance >= 10)
  {
    setForwardSpeed(0);
  }
  
  if (distance >13 && distance <= setPoint)
  {
    Serial.print("Distance = ");
    Serial.println(distance);
    //delay(10);

    Serial.print("Output = ");
    Serial.println(output);
    Serial.print("SetPoint = ");
    Serial.println(setPoint);
    //delay(200);
    setForwardSpeed((maxSpeed - output));;
  }
  
  if (distance < 10 && distance >= 5)
  {
    Serial.print("Distance = ");
    Serial.println(distance);
    //delay(10);

    Serial.print("Output = ");
    Serial.println(output);
    Serial.print("SetPoint = ");
    Serial.println(setPoint);
   // delay(200);
    setBackwardSpeed(minSpeed + output);  
  }
  
  if (distance < 5)
  {
    Serial.print("Distance = ");
    Serial.println(distance);
    //delay(10);

    Serial.print("Output = ");
    Serial.println(output);
    Serial.print("SetPoint = ");
    Serial.println(setPoint);
    //delay(200);
    setBackwardSpeed(maxSpeed);
  }

  //delay(10);
}

double getDistance() {
  int echoTime;                  
  double calcualtedDistance;         
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);

  echoTime = pulseIn(echoPin, HIGH);

  calcualtedDistance = echoTime / 58.26;  //calculate the distance of the object that reflected the pulse (half the bounce time multiplied by the speed of sound)
  return calcualtedDistance;              
}

void setForwardSpeed(int buggySpeed)
{
  Serial.print("Setting speed to ");
  Serial.println(buggySpeed);
  //delay(2000);


  analogWrite(enA, buggySpeed);
  analogWrite(enB, buggySpeed);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
    
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void setBackwardSpeed(int buggySpeed)
{
  Serial.print("Backwards at ");
  Serial.println(buggySpeed);
  //delay(2000);


  analogWrite(enA, buggySpeed);
  analogWrite(enB, buggySpeed);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
    
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
