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
  // create an array of values
  // reverse one value so that both are going in the same direction
  int vals[2] = { -leftVal, rightVal };
  int motors[4] = { motorPin1, motorPin2, motorPin3, motorPin4 };
  
  Serial.println(String(leftVal) + "," + String(rightVal));
  for (int i = 0; i < 2; i++) {
    // Set the motors to stop
    if (vals[i] == 0) {
      digitalWrite(motors[2 * i], LOW);
      digitalWrite(motors[(2 * i) + 1], LOW);
      Serial.println("stopped");
    }
    // Set the motors to go backwards
    else if (vals[i] < 0) {
      digitalWrite(motors[2 * i], HIGH);
      digitalWrite(motors[(2 * i) + 1], LOW);
      Serial.println("reversed");
    }
    // Set motors to go forward
    else if (vals[i] > 0) {
      digitalWrite(motors[2 * i], LOW);
      digitalWrite(motors[(2 * i) + 1], HIGH);
      Serial.println("forward");
    }
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
