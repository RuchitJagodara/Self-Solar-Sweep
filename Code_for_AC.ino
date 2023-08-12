#include <AFMotor.h>

AF_DCMotor motor1(1);  // Create motor object for M1 on Arduino Mega pin 10
AF_DCMotor motor2(4);  // Create motor object for M2 on Arduino Mega pin 9
AF_DCMotor motor3(2);
void setup() {
  // Initialize motor control pins
  motor1.setSpeed(0);    // Set initial speed of motor1 to 0
  motor1.run(RELEASE);   // Stop motor1
  motor2.setSpeed(0);    // Set initial speed of motor2 to 0
  motor2.run(RELEASE);   // Stop motor2
  motor3.setSpeed(0);    // Set initial speed of motor2 to 0
  motor3.run(RELEASE);   // Stop motor2
}


void loop() {
  
  static int iterationCount = 0;
  static int iterationCount1 = 0;
  // Check if the desired number of iterations has been reached
  if (iterationCount >= 3) {
    // Stop both motors
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    return;  // Exit the loop
  }
  
  motor3.setSpeed(255);  // Set the speed of motor1 (0-255)
  motor3.run(FORWARD);  // Run motor1 in the forward direction
  if (iterationCount >= 1) {
  motor3.run(RELEASE);
  }
  motor1.setSpeed(255);  // Set the speed of motor1 (0-255)
  motor1.run(FORWARD);  // Run motor1 in the forward direction
  delay(2200);
  motor1.run(RELEASE);  // Stop motor1
  motor3.run(RELEASE);  // Stop motor1
  delay(1000);
  motor2.setSpeed(255);  // Set the speed of motor2 (0-255)
  motor2.run(FORWARD);  // Run motor2 in the forward direction
  delay(2200);
  motor2.run(RELEASE);  // Stop motor2
  delay(1000);
  iterationCount++;
  iterationCount1++;
}
