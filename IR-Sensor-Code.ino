/* This is the code for the IR reflective sensors. This does not us a specific
 *  library so I am going to define the pins directly. You can use #define or 
 *  int =; approach; in both cases, the pin number that is equated is the 
 *  connected pin number.
 *  This code works on the premise of turning the LED on and then off at a 
 *  frequency of 38.5 kHz for 1 millisecond. During the pause the IR sensor
 *  measures the amount of reflected light. If there is a lot of reflected
 *  light, then the object that is reflecting the light is white. The less
 *  light that is reflected, then the darker it is. 
 */
 
#define irLedPin #    //LED is connected to this pin
#define irSensorPin #   //IR sensor is connected to this pin

// This is the first function that intitializes and futher defines everything.
// It only loops once.
void setup() {
  /* This defines the pin type, either an input or an output: 
   *  The IR sensor receives a signal so it is input.
   *  The LED is sending a signal so it is an output. 
  */
  pinMode(irSensorPin, INPUT);
  pinMode(irLedPin, OUTPUT);

  // Serial.begin intitiates the sent signal
  Serial.begin(9600);
}

// This is the code that continuously loops until the Arduino is turns off.
void loop(){
  if(digitalRead(irSensorPin)== HIGH){
    /* This return value may change depending on whether or not the
    IR sensor has been built to reduce voltage in the presence of light
    or increase it.
    */
    // Drive motors
  } else {
    // Continue on
  }
}

