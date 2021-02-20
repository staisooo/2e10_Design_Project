
int trigPin = 11;      // trig pin of HC-SR04
int echoPin = 10;     // Echo pin of HC-SR04

// motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;

// motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;

long duration, distance;

void setup() {
  
  delay(random(500,2000));   // delay for random time
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);      // set Motor pins as output
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  pinMode(trigPin, OUTPUT);         // set trig pin as output
  pinMode(echoPin, INPUT);          //set echo pin as input to capture reflected waves

  // turn off motors - inital state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);     // send waves for 10 us
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH); // receive reflected wavess
  distance = (duration /2)/29.1;   // convert to distance
  delay(10);
    // If you dont get proper movements of your robot then alter the pin numbers
  if (distance > 19)            
  {
    digitalWrite(in1, HIGH);                    // move forward
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);                                
    digitalWrite(in4, LOW);                                                       
  }

  if (distance < 18)
  {
    digitalWrite(in1, LOW);  //Stop                
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);                                
    digitalWrite(in4, LOW);
    delay(500);
    Serial.print("stopping for obstacle at ");
    Serial.print(distance );
    Serial.println("cm distance ");
  }


}
