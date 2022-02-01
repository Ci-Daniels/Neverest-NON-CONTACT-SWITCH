//constants
const int trigpin=12;//define the input pin of trig 10
const int echopin=13;//define input of echo 11
const int ledpin=10;//define the led input pin 12
const int ldrpin=A1;//define ldr input pin A0
const int relaypin1=11;//define realay input pin 9
const int maximum_distance=4;//set the threshold distance of the ultrasonic sensor to turn led on or off

//variables
long duration;
int distance;
int oldledstate = LOW;
int relaystate = HIGH;
int currentledstate=LOW;
int ledpinstate=LOW;

void setup() {
  Serial.begin(9600);//initialise the serial port
  pinMode(relaypin1,OUTPUT);//set pin to output mode
  pinMode(trigpin,OUTPUT);//set pin to output mode
  pinMode(echopin,INPUT);//set pin to input mode
  pinMode(ledpin,OUTPUT);//set pin to output mode
  pinMode(ldrpin,INPUT);//set pin to input mode
  Serial.begin(9600);
  delay(2000);
  Serial.println("Waiting for hand to get closer!");
}

void loop() {
  
  read_sensor();
  int ldrstatus = analogRead(ldrpin);//read status of the ldr
  distance= read_sensor;
  
   if((distance<maximum_distance)||(ldrstatus<150))
   {
    oldledstate=1;
     }
      else oldledstate=0;
      
void read_sensor();
    {
      if(oldledstate!=currentledstate)
      {
        if (oldledstate==1)
        {
          if (ledpinstate==1)
          {
            ledpinstate=0;
            digitalWrite(ledpin, ledpinstate);
            digitalWrite(relaypin1, HIGH);
            Serial.print("TURN LED OFF:");//print value to serial monitor
            Serial.println(ldrstatus);
            Serial.print("The distance is:");//print value to serial monitor
            Serial.println(distance);
            delay(500);
            }
            else  
              ledpinstate=1; 
              digitalWrite(ledpin, ledpinstate);
              digitalWrite(relaypin1, LOW);
              Serial.print("TURN LED ON:");//print value to serial monitor
              Serial.println(ldrstatus);
              Serial.print("The distance is:");//print value to serial monitor
              Serial.println(distance);
              delay(500);
          }
          currentledstate = oldledstate ;
      }
   }
}
      
void read_sensor() {
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(20);//generate 20 microseconds pulse to trigpin this will tell the sensor to send out the echo pulse
  digitalWrite(trigpin, LOW);  
  //measure duration of pulse from ECHO pin
  duration = pulseIn(echopin,HIGH);
  //calculatin the distance in cm
  //distance=speed*duration per cycle
  //speed=340m/s=0.034cm/ms
  distance = (0.017 *duration);//per cycle
  }
