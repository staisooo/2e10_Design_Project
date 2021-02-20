int vSpeed = 110;        // MAX 255
int turn_speed = 230;    // MAX 255
int turn_delay = 10;
 
// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;

//Sensor Connection
const int LEYE = A1;
const int REYE = A0;

int left_sensor_state;
int right_sensor_state;

const int motorBspeed = 11;
const int motorAspeed = 10;

void setup() {
  Serial.begin(9600);

  pinMode( LEYE, INPUT );
  pinMode( REYE, INPUT );

  //set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
 
}

void loop() {

left_sensor_state = analogRead(LEYE);
right_sensor_state = analogRead(REYE);

if(right_sensor_state > 500 && left_sensor_state < 500)
{
  Serial.println("turning right");

  digitalWrite (in1,HIGH); 
  digitalWrite (in2,LOW);                      
  digitalWrite (in3,LOW);  
  digitalWrite (in4,LOW);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, turn_speed);
 
 }
 
if(right_sensor_state < 500 && left_sensor_state > 500)
{
  Serial.println("turning left");
 
  digitalWrite (in1,LOW);
  digitalWrite (in2,LOW);                      
  digitalWrite (in3,HIGH); 
  digitalWrite (in4,LOW);

  analogWrite (motorAspeed, turn_speed);
  analogWrite (motorBspeed, vSpeed);

  delay(turn_delay);
 }

if(right_sensor_state < 500 && left_sensor_state < 500)
{
  Serial.println("going forward");

  digitalWrite (in1,HIGH);
  digitalWrite (in2,LOW);                      
  digitalWrite (in3,HIGH);
  digitalWrite (in4,LOW);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);

  delay(turn_delay);
 
  }

if(right_sensor_state > 500 && left_sensor_state > 500)
{
  Serial.println("stop");

  digitalWrite (in1,LOW);
  digitalWrite (in2,LOW);                      
  digitalWrite (in3,LOW);
  digitalWrite (in4,LOW);
 
  analogWrite (0, 0);
  analogWrite (0, 0); 
}

}
