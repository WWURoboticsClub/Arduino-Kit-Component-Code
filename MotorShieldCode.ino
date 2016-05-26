/* This is the code for the motor control via the L298N_Dual_H_Bridge component. 
 * Because there is no specific library for it, I declared the pins associated 
 * with the motor shield to the connected pins on the Arduino. The motor shield 
 * has the pins IN1-IN4, ENA and ENB. 
 */
 
  //Motor 1
int enA = ; 
int in1 = ;
int in2 = ;
  //Motor 2
int enB = ;
int in3 = ;
int in4 = ;

void setup() {
  // This turns all the motor control pins to outputs 
pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
}

void loop() {
  /* digitalWrite(pin, OUTPUT) turns the motors on. Note that the pins 
   *  corresponding to this command are the 'IN1' to 'IN4' 
   *  
   */
  // Turns on motor 1:
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);

  // Turns on motor 2:
digitalWrite(in1, HIGH);
digitalWrite(in1, LOW);

// Controls motor speed:
analogWrite(enA, 200);
analogWrite(enB, 200);
}
