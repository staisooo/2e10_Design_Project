int vSpeed = 255;        // MAX 255
int turn_speed = 255;    // MAX 255
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

const int motorBspeed = 12;
const int motorAspeed = 13;

int trigPin = 11;      // trig pin of ultrasonic sensor
int echoPin = 10;     // Echo pin of ultrasonic sensor

long duration, distance;

void setup() {
  Serial.begin(9600);

  pinMode( LEYE, INPUT );
  pinMode( REYE, INPUT );

  delay(random(500,2000)); //delay for random time
  //set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(trigPin, OUTPUT);         // set trig pin as output
  pinMode(echoPin, INPUT);          //set echo pin as input to capture reflected waves

  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
 
}

void loop() {

left_sensor_state = analogRead(LEYE);
right_sensor_state = analogRead(REYE);

digitalWrite(trigPin, LOW);
delayMicroseconds(2);   
digitalWrite(trigPin, HIGH);     // send waves for 10 us
delayMicroseconds(10);
duration = pulseIn(echoPin, HIGH); // receive reflected waves
distance = (duration /2)/29.1;   // convert to distance
delay(10);
if (distance <= 19)
  {
      digitalWrite(in1, LOW);  //Stop                
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);                                
      digitalWrite(in4, LOW);
      delay(1000);
      Serial.print("stopping for obstacle at ");
      Serial.print(distance );
      Serial.println("cm distance ");
   }
else 
{
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
}
