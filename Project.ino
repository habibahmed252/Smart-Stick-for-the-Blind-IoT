// Smart Stick for the Blind: obstacle detection with an HC-SR04 ultrasonic sensor.
int trigPin = 11;   // sends the ultrasonic pulse
int echoPin = 8;    // receives the echo
int buzzer = 2;     // buzzer
int led = 5;        // LED

long duration;      // echo travel time
int distance;       // final distance in cm

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // Reset the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a 10 microsecond pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Time the echo, then convert to distance (speed of sound 0.034 cm/us, there and back)
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // Alert when an obstacle is 20 cm away or closer
  if (distance <= 20) {
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
  }

  delay(20);
}
