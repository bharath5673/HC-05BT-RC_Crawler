
const int motor1Pin2 = 3;
const int motor1Pin1 = 4;
const int motor1PinSpeed = 5;
const int motor2PinSpeed = 6;
const int motor2Pin1 = 7;
const int motor2Pin2 = 8;


int r1 = 8; //  frontlight
int g1 = 9; //  backlight
int b1 = 10; //  hornplease


int Speed = 100; // 0 - 255.


char bt = 'S';

void setup() {

  Serial.begin(9600);
  Serial.println("CAR READY");
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor1PinSpeed, OUTPUT);
  pinMode(motor2PinSpeed, OUTPUT); 
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  
  pinMode(r1, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(g1, OUTPUT);

}

void loop() {

  if (Serial.available() > 0) {
    bt = Serial.read();
    Serial.println(bt);
  }

  switch (bt) {


    case '0':
      Speed = 100;
      break;
    case '1':
      Speed = 140;
      break;
    case '2':
      Speed = 153;
      break;
    case '3':
      Speed = 165;
      break;
    case '4':
      Speed = 178;
      break;
    case '5':
      Speed = 191;
      break;
    case '6':
      Speed = 204;
      break;
    case '7':
      Speed = 216;
      break;
    case '8':
      Speed = 229;
      break;
    case '9':
      Speed = 242;
      break;
    case 'q':
      Speed = 255;
      break;



    case 'W':
      Serial.println("HEADLIGHTS ON");
      digitalWrite(r1, HIGH);
      break;

    case 'w':
      Serial.println("HEADLIGHTS OFF");
      digitalWrite(r1, LOW);
      break;

    case 'U':
      Serial.println("BACKLIGHTS ON");
      digitalWrite(g1, HIGH);
      break;

    case 'u':
      Serial.println("BACKLIGHTS OFF");
      digitalWrite(g1, LOW);
      break;

    case 'V':
      Serial.println("HORN ON");
      digitalWrite(b1, HIGH);
      break;

    case 'v':
      Serial.println("HORN OFF");
      digitalWrite(b1, LOW);
      break;



    // forward
    case 'F':
      digitalWrite(motor1Pin1, HIGH);
      analogWrite(motor1PinSpeed, Speed);
      break;

    // left
    case 'L':
      digitalWrite(motor2Pin1, HIGH);
      analogWrite(motor2PinSpeed, 170);
      break;

    // right
    case 'R':
      digitalWrite(motor2Pin2, HIGH);
      analogWrite(motor2PinSpeed, 170);
      break;

    // backward
    case 'B':
      digitalWrite(motor1Pin2, HIGH);
      analogWrite(motor1PinSpeed, Speed);
      break;





    // forward left
    case 'G':
      analogWrite(motor1PinSpeed, Speed);
      digitalWrite(motor1Pin1, HIGH);
      break;
      digitalWrite(motor2Pin1, HIGH);
      analogWrite(motor2PinSpeed, 170);            
      break;


    // forward right
    case 'I':
      analogWrite(motor1PinSpeed, Speed);
      digitalWrite(motor1Pin1, HIGH);
      break;
      digitalWrite(motor2Pin2, HIGH);
      analogWrite(motor2PinSpeed, 170);      
      break;


    // backward left
    case 'H':
      analogWrite(motor1PinSpeed, Speed);
      digitalWrite(motor1Pin2, HIGH);
      break;
      digitalWrite(motor2Pin1, HIGH);
      analogWrite(motor2PinSpeed, 170);      
      break;

    // backward right
    case 'J':
      analogWrite(motor1PinSpeed, Speed);
      digitalWrite(motor1Pin2, HIGH);
      break;
      digitalWrite(motor2Pin2, HIGH);
      analogWrite(motor2PinSpeed, 170);            
      break;



    // Stop
    case 'S':
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, LOW);
      break;

    // reset
    case 'T':
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, LOW);
      break;
  }
}
