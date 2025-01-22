#include <Servo.h>  //tell code to use servo library
#define LIFT_PIN 3  //define the numbers the pins are connected to
#define LED_RED 4
#define LED_GREEN 5
#define BUTTON 6

Servo lift;  //make a servo object called "lift"

void setup() {

  pinMode(BUTTON, INPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);

  lift.attach(LIFT_PIN);  //connect the servo object to the pin
  lift.write(90);         //set the start of the propeller to 90 degrees
}

void loop() {

  if (digitalRead(BUTTON) == 1) {  //if the button is pressed and held, the green LED flashes 5 times before the arm starts to drop from 90  slowly down to 27 degree then back to 90
    digitalWrite(LED_RED, LOW);
    delay(200);
    for (int i = 0; i < 5; i++) {
      digitalWrite(LED_GREEN, HIGH);
      delay(200);
      digitalWrite(LED_GREEN, LOW);
      delay(200);
    }
    lift.write(90);
    delay(2000);
    lift.write(60);
    delay(500);
    lift.write(27);
    delay(2000);
    lift.write(90);
    delay(500);

  } else {
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_RED, HIGH);  //if the button is not pressed, the red LED will light up to indicate that the excavator is not working
    lift.write(90);
    delay(2000);
  }
}
