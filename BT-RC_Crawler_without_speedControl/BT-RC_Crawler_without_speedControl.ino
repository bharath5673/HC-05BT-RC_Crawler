
const int motor1Pin1 = 3;
const int motor1Pin2 = 4;
const int motor2Pin1 = 5;
const int motor2Pin2 = 6;

char bt = 'S';

void setup() {

  Serial.begin(9600);
  Serial.println("CAR READY");
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

}

void loop() {

  if (Serial.available() > 0) {
    bt = Serial.read();
    Serial.println(bt);
  }

  switch (bt) {
    // forward
    case 'F':
      digitalWrite(motor1Pin1, HIGH);
      break;

    // left
    case 'L':
      digitalWrite(motor2Pin1, HIGH);
      break;

    // right
    case 'R':
      digitalWrite(motor2Pin2, HIGH);
      break;

    // forward left
    case 'G':
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor2Pin1, HIGH);
      break;


    // forward right
    case 'I':
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor2Pin2, HIGH);
      break;


    // backward left
    case 'H':
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, HIGH);
      break;

    // backward right
    case 'J':
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin2, HIGH);
      break;

    // backward
    case 'B':
      digitalWrite(motor1Pin2, HIGH);
      break;

    // Stop
    case 'S':
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, LOW);

    // reset
    case 'T':
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, LOW);  
  }
}
