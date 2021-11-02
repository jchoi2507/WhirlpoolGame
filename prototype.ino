//Digital output pins for turning motors 1 and 2 CW and CCW
int motor1CW_OUTPUT_PIN = 2;
int motor1CCW_OUTPUT_PIN = 3;
int motor2CW_OUTPUT_PIN = 4;
int motor2CCW_OUTPUT_PIN = 5;

//Digital input pins for detecting when the appropriate button is pushed to turn the motors CW or CCW
int motor1CW_INPUT_PIN = 8;
int motor1CCW_INPUT_PIN = 9;
int motor2CW_INPUT_PIN = 10;
int motor2CCW_INPUT_PIN = 11;

//global variables to utilize in switch function
int motorID = 0;
const int motor1CW = 1;
const int motor1CCW = 2;
const int motor2CW = 3;
const int motor2CCW = 4;

//Function that determines if a button was pressed
void determineMotorID() {
  if (digitalRead(motor1CW_INPUT_PIN) == HIGH) {
    motorID = motor1CW;
  }
  else if (digitalRead(motor1CCW_INPUT_PIN) == HIGH) {
    motorID = motor1CCW;
  }
  else if (digitalRead(motor2CW_INPUT_PIN) == HIGH) {
    motorID = motor2CW;
  }
  else if (digitalRead(motor2CCW_INPUT_PIN) == HIGH) {
    motorID = motor2CCW;
  }
}

void setup() {
  pinMode(motor1CW_OUTPUT_PIN, OUTPUT);
  pinMode(motor1CCW_OUTPUT_PIN, OUTPUT);
  pinMode(motor2CW_OUTPUT_PIN, OUTPUT);
  pinMode(motor2CCW_OUTPUT_PIN, OUTPUT);

  digitalWrite(motor1CW_OUTPUT_PIN, LOW);
  digitalWrite(motor1CCW_OUTPUT_PIN, LOW);
  digitalWrite(motor2CW_OUTPUT_PIN, LOW);
  digitalWrite(motor2CCW_OUTPUT_PIN, LOW);
}

void loop() {
  switch (motorID) {
    default:
      determineMotorID(); //If no button is pressed, keep looping until a button is pressed
    case (motor1CW):
      digitalWrite(motor1CW_OUTPUT_PIN, HIGH);
      while (true) {
        if (digitalRead(motor1CW_INPUT_PIN) == LOW) {
          digitalWrite(motor1CW_OUTPUT_PIN, LOW);
          break;
        }
      }
      motorID = 0;
    case (motor1CCW):
      digitalWrite(motor1CCW_OUTPUT_PIN, HIGH);
      while (true) {
        if (digitalRead(motor1CCW_INPUT_PIN) == LOW) {
          digitalWrite(motor1CCW_OUTPUT_PIN, LOW);
          break;
        }
      }
      motorID = 0;
    case (motor2CW):
      digitalWrite(motor2CW_OUTPUT_PIN, HIGH);
      while (true) {
        if (digitalRead(motor2CW_INPUT_PIN) == LOW) {
          digitalWrite(motor2CW_OUTPUT_PIN, LOW);
          break;
        }
      }
      motorID = 0;
    case (motor2CCW):
      digitalWrite(motor2CCW_OUTPUT_PIN, HIGH);
      while (true) {
        if (digitalRead(motor2CCW_INPUT_PIN) == LOW) {
          digitalWrite(motor2CCW_OUTPUT_PIN, LOW);
          break;
        }
      }
      motorID = 0;
  }
}
