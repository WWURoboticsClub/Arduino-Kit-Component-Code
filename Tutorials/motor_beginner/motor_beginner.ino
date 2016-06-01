// The functions used to test the motors
void drive(int leftSpeed, int rightSpeed);
void checkRange(int *val);
void setMotorStates(int leftVal, int rightVal);

// The pins for the DC Motors
// Pins controlling the speed of the motor via PWM
int enA = 5;
int enB = 6;

// Pins controlling the direction the motors are going
// Left motor (speed controlled by enA)
int motorPin1 = 7;
int motorPin2 = 2;
// Right motor (speed conotrlled by enB)
int motorPin3 = 3;
int motorPin4 = 4;

void setup() {
  // Output debug information/distances
  Serial.begin(9600);

  // Set the pins to output our signals
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
}

void loop() {
  Serial.println("Im working");
  drive(120, 120);
  delay(1000);
  drive(0, 0);
  delay(1000);
}

/// Sends an analog signal to the motors
/// \param leftSpeed The value to set the motor to. range: [-255,255]
/// \param rightSpeed The value to set the motors to. range: [-255,255]
void drive(int leftSpeed, int rightSpeed) {
  // Make sure the values are in range.
  checkRange(&leftSpeed);
  checkRange(&rightSpeed);

  analogWrite(enA, abs(leftSpeed));
  analogWrite(enB, abs(rightSpeed));

  setMotorStates(leftSpeed, rightSpeed);
}

/// Sets the motor states to go forward, backward, or stop
/// \param leftVal The left value you're sending to the motors
/// \param rightVal The right value you're sending to the motors
void setMotorStates(int leftVal, int rightVal) {
    // Invert the motor with software. Delete if this was done with hardware.
    leftVal *= -1;
    
    // Check left motors
    // Set the motors to stop
    if (leftVal == 0) {
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, LOW);
    }
    // Set the motors to go backwards
    else if (leftVal < 0) {
      digitalWrite(motorPin1, HIGH);
      digitalWrite(motorPin2, LOW);
    }
    // Set motors to go forward
    else if (leftVal > 0) {
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, HIGH);
    }

    // Check right motors
    // Set the motors to stop
    if (rightVal= 0) {
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, LOW);
    }
    // Set the motors to go backwards
    else if (rightVal < 0) {
      digitalWrite(motorPin3, HIGH);
      digitalWrite(motorPin4, LOW);
    }
    // Set motors to go forward
    else if (rightVal > 0) {
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, HIGH);
    }
}

/// Makes sure the input is within the required range
/// \param val The input to check
void checkRange(int *val) {
  if (*val < -255)
    *val = -255;
  else if (*val > 255)
    *val = 255;
}
