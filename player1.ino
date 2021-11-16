#include <pt.h>

static struct pt pt1, pt2;

//Global variables

//Player 1's motors
int motor1Direction = 0;
int motor2Direction = 0;

const int CW = 1;
const int CCW = 2;

void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);
  PT_INIT(&pt1);
  PT_INIT(&pt2);
}

bool motor1() {
  if (digitalRead(2) == HIGH) {
    motor1Direction = CW;
    return true;
  }
  if (digitalRead(3) == HIGH) {
    motor1Direction = CCW;
    return true;
  }
  else {
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    return false;
  }
}

bool motor2() {
  if (digitalRead(8) == HIGH) {
    motor2Direction = CW;
    return true;
  }
  if (digitalRead(9) == HIGH) {
    motor2Direction = CCW;
    return true;
  }
  else {
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    return false;
  }
}

static int protothread1(struct pt *pt) {
  PT_BEGIN(pt);
  while (true) {
    PT_WAIT_UNTIL(pt, motor1());
    if (motor1Direction == CW) {
      digitalWrite(4, HIGH);
    }
    else if (motor1Direction == CCW) {
      digitalWrite(5, HIGH);
    }
  }
  PT_END(pt);
}

static int protothread2(struct pt *pt) {
  PT_BEGIN(pt);
  while (true) {
    PT_WAIT_UNTIL(pt, motor2());
    if (motor2Direction == CW) {
      digitalWrite(6, HIGH);
    }
    else if (motor2Direction == CCW) {
      digitalWrite(7, HIGH);
    }
  }
  PT_END(pt);
}

void loop() {
  protothread1(&pt1);
  protothread2(&pt2);
}
