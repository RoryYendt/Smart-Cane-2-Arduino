#define trigPin 4
#define echoPin 2
#define IN1  6
#define IN2  7
#define IN3  8
#define IN4  9

int Steps = 0;
boolean Direction = true;// gre
unsigned long last_time;
unsigned long currentMillis ;
int steps_left=4095;
long time;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT); //indicates that the trigPin on the HC-sr04 ultrasonic sensor is an output
  pinMode(echoPin, INPUT); //indicates that the echoPin on the HC-sr04 ultrasonic sensor is an input
  pinMode(IN1, OUTPUT); //these four rows indicate that the pins on the driver for the stepper motor are outputs
  pinMode(IN2, OUTPUT); // ^
  pinMode(IN3, OUTPUT); // ^^
  pinMode(IN4, OUTPUT); // ^^^
}

void loop() {
 
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Tells the sensor to set the trigPin off
  delayMicroseconds(2); // Delays for 2 microseconds
  digitalWrite(trigPin, HIGH); // Tells the sensor to set the trigPin on
  delayMicroseconds(10); // Delays for 10 microseconds
  digitalWrite(trigPin, LOW); //Tells the sensor to set the trigPin off
  duration = pulseIn(echoPin, HIGH); //Sends the ultrasonic wave through the echoPin
  distance = (duration/2) / 29.1; //sets the duration
  Serial.println(distance); //looks for distance
  if (distance < 150) {  // This is when the vibration motor knows how to turn on. If the distance is less than 150cm, the stepper motor will vibrate.
    moveStepper(1); //turns motor on
    
  
}
    
    }


void moveStepper(int direction) {
 currentMillis = micros();
  if(currentMillis-last_time>=1000){
   stepper(1); 
   time=time+micros()-last_time;
   last_time=micros();
   
  }
}

    void stepper(int xw){
  for (int x=0;x<xw;x++){
 switch(Steps){
    case 0:
   digitalWrite(IN1, LOW); 
   digitalWrite(IN2, LOW);
   digitalWrite(IN3, LOW);
   digitalWrite(IN4, HIGH);
    break; 
    case 1:
   digitalWrite(IN1, LOW); 
   digitalWrite(IN2, LOW);
   digitalWrite(IN3, HIGH);
   digitalWrite(IN4, HIGH);
    break; 
    case 2:
   digitalWrite(IN1, LOW); 
   digitalWrite(IN2, LOW);
   digitalWrite(IN3, HIGH);
   digitalWrite(IN4, LOW);
    break; 
    case 3:
   digitalWrite(IN1, LOW); 
   digitalWrite(IN2, HIGH);
   digitalWrite(IN3, HIGH);
   digitalWrite(IN4, LOW);
    break; 
    case 4:
   digitalWrite(IN1, LOW); 
   digitalWrite(IN2, HIGH);
   digitalWrite(IN3, LOW);
   digitalWrite(IN4, LOW);
    break; 
    case 5:
   digitalWrite(IN1, HIGH); 
   digitalWrite(IN2, HIGH);
   digitalWrite(IN3, LOW);
   digitalWrite(IN4, LOW);
    break; 
   case 6:
   digitalWrite(IN1, HIGH); 
   digitalWrite(IN2, LOW);
   digitalWrite(IN3, LOW);
   digitalWrite(IN4, LOW);
    break; 
    case 7:
   digitalWrite(IN1, HIGH); 
   digitalWrite(IN2, LOW);
   digitalWrite(IN3, LOW);
   digitalWrite(IN4, HIGH);
    break; 
    default:
   digitalWrite(IN1, LOW); 
   digitalWrite(IN2, LOW);
   digitalWrite(IN3, LOW);
   digitalWrite(IN4, LOW);
    break; 
    
 }
 
 SetDirection();
  }
} 

void SetDirection(){
if(Direction==1){ Steps++;}
if(Direction==0){ Steps--; }
if(Steps>7){Steps=0;}
if(Steps<0){Steps=7; }
}
