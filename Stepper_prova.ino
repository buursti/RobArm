#include <AccelStepper.h>

const int Step_pin = 2;
const int Dir_pin = 3;

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

  digitalWrite(M0, LOW);
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);

  float MaxRPM = 200;
  float Max_speed = stepsPerRevolution * MaxRPM / 60;
  stepper.setMaxSpeed(200);

  float Accel = 500;
  float Accel_step = Accel * stepsPerRevolution / 60;
  stepper.setAcceleration(200);

  stepper.setCurrentPosition(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  stepper.move(200);

  while (stepper.distanceToGo() != 0) {
    stepper.run();}

  delay(2000);

  stepper.move(-200);

  while (stepper.distanceToGo() != 0) {
    stepper.run();}

  delay(2000);
}
