#define trigPin D2
#define echoPin D1
#define ledPin D4
#define buzzerPin D6

long duration;
int distance;
void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);


  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin,LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration*0.034/2;

  if (distance <= 7) {
    on();
    return;
  }
  if (distance > 4) {
    off();
    return;
  }

  Serial.print("Distance: ");
  Serial.println(distance);  
  delay(1000);
  }

void on() {
  digitalWrite(ledPin, HIGH);
  digitalWrite(buzzerPin, HIGH);
}

void off() {
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);
}
