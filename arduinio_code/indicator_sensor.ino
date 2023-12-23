const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 11;
const int MainMotorPin = 4;
const int pump1Pin = 3;
const int pump2Pin = 2;
const int moistureSensor1Pin = A0;
const int moistureSensor2Pin = A1;
const int moistureSensor3Pin = A2;
const int moistureSensor4Pin = A3;


const int warningLevel = 8; // Adjust this value based on your tank height and desired warning level

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(MainMotorPin, OUTPUT);
  pinMode(pump1Pin, OUTPUT);
  pinMode(pump2Pin, OUTPUT);

}

void loop() {
  // Measure distance using ultrasonic sensor
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration /2) / 29.1;  // Divide by 29.1 to convert microseconds to centimeters

  // Print distance to serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check water level and trigger warning buzzer if needed
  if (distance <= warningLevel) {
    digitalWrite(buzzerPin, HIGH); // Turn on the buzzer
    digitalWrite(MainMotorPin, HIGH);
    Serial.println("Warning: Water level is HIGH!");
  } else {
    digitalWrite(buzzerPin, LOW); // Turn off the buzzer
    digitalWrite(MainMotorPin, LOW);
  }
  

  int moistureValue1 = analogRead(moistureSensor1Pin) - 800;
  int moistureValue2 = analogRead(moistureSensor2Pin) - 800 ;

  int moistureValue3 = analogRead(moistureSensor3Pin) - 800;
  int moistureValue4 = analogRead(moistureSensor3Pin) - 800;

  int Area1MoisturePercent = ((moistureValue1 + moistureValue4))/100;
  int Area2MoisturePercent = ((moistureValue3 + moistureValue2))/100;

  Serial.println(moistureValue1);
  Serial.println(moistureValue4);
  Serial.print("Moisture Value for Area 1: ");
  Serial.println(Area1MoisturePercent);

  
  Serial.println(moistureValue3);
  Serial.println(moistureValue2);
  Serial.print("Moisture Value for Area 2: ");
  Serial.println(Area2MoisturePercent);

  if (Area1MoisturePercent > 0) {
    digitalWrite(pump1Pin, HIGH);
    Serial.println("pump 1 is supplying water to Area 1!");
  } else {
    digitalWrite(pump1Pin, LOW);
  }
  if (Area2MoisturePercent > 0) {
    digitalWrite(pump2Pin, HIGH);
    Serial.println("pump 2 is supplying water to Area 2!");
  } else {
    digitalWrite(pump2Pin, LOW);
  }



  delay(1500);




}

