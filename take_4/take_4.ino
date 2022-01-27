//kariithi_wanjiku
//**The non-contact switch take 3 using the relay module**//
//constants
const int trigpin=12;//define the input pin of trig 10
const int echopin=13;//define input of echo 11
const int ledpin=10;//define the led input pin 12
const int ldrpin=A1;//define ldr input pin A0
const int relaypin1=11;//define realay input pin 9
const int maximum_distance=3;//set the threshold distance of the ultrasonic sensor to turn led on or off

//variables
long duration;
int distance;

void setup() 
{
  Serial.begin(9600);//initialise the serial port
  pinMode(relaypin1,OUTPUT);//set pin to output mode
  pinMode(trigpin,OUTPUT);//set pin to output mode
  pinMode(echopin,INPUT);//set pin to input mode
  pinMode(ledpin,OUTPUT);//set pin to output mode
  pinMode(ldrpin,INPUT);//set pin to input mode
}

void loop() {
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2); //generate 2 microseconds pulse to trigpin
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10); 
 

  //measure duration of pulse from ECHO pin
  duration = pulseIn(echopin,HIGH);
  //calculatin the distance in cm
  //distance=speed*duration per cycle
  //speed=340m/s=0.034cm/ms
  distance = (0.017 *duration);//per cycle
  int ldrstatus = analogRead(ldrpin);//read status of the ldr

  //loop
 
  
  if(ldrstatus<15)
      {
       digitalWrite(relaypin1,LOW); 
       digitalWrite(ledpin,HIGH);
       Serial.print("TURN LED ON:");//print value to serial monitor
       Serial.println(ldrstatus);
       Serial.print("Thedistance is:");//print value to serial monitor
       Serial.println(distance);
       delay(2000);
      }
  
       else if((ldrstatus<15) || (distance<maximum_distance))
        {
           digitalWrite(relaypin1,LOW);   
           digitalWrite(ledpin,HIGH);
           Serial.print("TURN LED ON:");//print value to serial monitor
           Serial.println(ldrstatus);
           Serial.print("Thedistance is:");//print value to serial monitor
           Serial.println(distance);
         delay(3000);
        }
     
          else {
            digitalWrite(relaypin1,HIGH); 
            digitalWrite(ledpin,LOW);
            Serial.print("TURN LED OFF:");
            Serial.println(ldrstatus);
            Serial.print("Thedistance is:");//print value to serial monitor
            Serial.println(distance);
        }    
        delay(500);
 }
 
