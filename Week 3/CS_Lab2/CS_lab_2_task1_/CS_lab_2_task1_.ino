

//#error "You didn't update the sensor definitions!"
// CHANGE THESE TO MATCH YOUR WIRING, THEN DELETE THE PREVIOUS "#error" LINE
const int LEYE = A1;
const int REYE = A0;

void setup() {
  Serial.begin(9600);

  pinMode( LEYE, INPUT );
  pinMode( REYE, INPUT );

}

  String left_new_value = "";
  String right_new_value = "";
  String left_old_value = "";
  String right_old_value = "";
  
void loop() {


if( digitalRead( LEYE ) == HIGH )
{ 
  left_new_value = "low ";
} 
else
{
  left_new_value = "high ";
}

if (left_old_value != left_new_value)
{
  Serial.print(left_new_value);
}

left_old_value = left_new_value; 


if( digitalRead( REYE ) == HIGH )
{ 
  right_new_value = "low ";
} 
else
{
  right_new_value = "high ";
}

if (right_old_value != right_new_value)
{
  Serial.println(right_new_value);
}

right_old_value = right_new_value; 
 

/*  if( digitalRead( REYE ) == HIGH ){
    Serial.println(" right low  ");
  }else{
    Serial.println("right high ");
  }
  */
  delay(1000);
}
