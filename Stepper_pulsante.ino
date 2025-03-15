#include <AccelStepper.h>

const int Step_pin = 2;
const int Dir_pin = 3;

const int Botton = 4;

const int M0 = 6;
const int M1 = 7;
const int M2 = 8;

const int stepsPerRevolution = 200;

AccelStepper stepper(AccelStepper::DRIVER, Step_pin, Dir_pin);

void setup() {
  // put your setup code here, to run once:
  pinMode(M0, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);

  pinMode(Botton, INPUT);

  digitalWrite(M0, LOW);
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);

  float MaxRPM = 360;
  float Max_speed = stepsPerRevolution * MaxRPM * 4 / 60;
  stepper.setMaxSpeed(Max_speed);

  float Accel = 500;
  float Accel_step = Accel * stepsPerRevolution / 60;
  stepper.setAcceleration(3000);

  stepper.setCurrentPosition(0);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(Botton) == HIGH) {
    stepper.move(16000);

    while (stepper.distanceToGo() != 0) {
    stepper.run();}

    delay(500);

    stepper.move(-16000);

    while (stepper.distanceToGo() != 0) {
    stepper.run();}
  }

  delay(20);
}
