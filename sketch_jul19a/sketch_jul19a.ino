// Start Button
int button_pin = 7;

// Distance sensors
const int trig_pin_left = 3;
const int echo_pin_left = 4;
const int trig_pin_right = 5;
const int echo_pin_right = 6;

int scan_distance = 60;

// Line sensors
int top_left = A1;
int top_right = A2;
int bottom_left = A3;
int bottom_right = A4;

int white = 0;
int black = 1;

// Motor control
int motor1pin1 = 12;
int motor1pin2 = 11;

int motor2pin1 = 10;
int motor2pin2 = 9;

int motor1speed = 13;
int motor2speed = 8;

long duration;
int distance;

void setup() {
  // put your setup code here, to run once:

  // Setup IO pins
  pinMode(button_pin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
  pinMode(trig_pin_left, OUTPUT); 
  pinMode(echo_pin_left, INPUT); 
  
  pinMode(trig_pin_right, OUTPUT); 
  pinMode(echo_pin_right, INPUT); 

  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  pinMode(motor1speed, OUTPUT); 
  pinMode(motor2speed, OUTPUT);

  // Starts the serial communication for debugging
  Serial.begin(9600); 

}

void loop() {
  Serial.println("Working");
  // put your main code here, to run repeatedly:
  // Clears the trigPin
  digitalWrite(trig_pin_left, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trig_pin_left, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin_left, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  unsigned int duration = pulseIn(echo_pin_left, HIGH);
  // Calculating the distance
  unsigned int distance = duration * 0.034 / 2;

  Serial.println("Left");
  Serial.println(distance);

  // put your main code here, to run repeatedly:
  // Clears the trigPin
  digitalWrite(trig_pin_right, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trig_pin_right, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin_right, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echo_pin_right, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;

  Serial.println("Right");
  Serial.println(distance);


}
