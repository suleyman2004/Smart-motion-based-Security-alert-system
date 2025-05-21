const int trigPin = 10;
const int echoPin = 11;
const int buzzerPin = 9;
const int ledPin=8;

long duration;
int distance;

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
 
  Serial.begin(9600);
}

void loop() {

  distance = calculateDistance();


  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");


  buzzAccordingToDistance(distance);



  
  delay(500);  
}

int calculateDistance() {

  digitalWrite(trigPin, LOW);
  digitalWrite(ledPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  digitalWrite(ledPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  digitalWrite(ledPin, LOW);
 
  duration = pulseIn(echoPin, HIGH);  
  if (duration == 0) {
     return -1;
  }

  
  distance = duration * 0.034 / 2;
  return distance;
}

void buzzAccordingToDistance(int d) {
  if ( d > 0 && d <= 100) {
    int delayTime = map(d, 0, 100, 50, 500);  
    digitalWrite(buzzerPin, LOW); 
    digitalWrite(ledPin, HIGH);           
    delay(delayTime);
    digitalWrite(buzzerPin, HIGH);    
    digitalWrite(ledPin, LOW);         
    delay(delayTime);
  } else {
    digitalWrite(buzzerPin, HIGH);   
    digitalWrite(ledPin, LOW);            
  }
}
