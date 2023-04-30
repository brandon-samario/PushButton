/*
  The program uses classes to implement a pushbutton with debounce.
  The purpose of the program is to detect when a button is pressed and print a message to the serial monitor.
  The program defines a class called PushButton that has private variables for the pin number, the current state of the button, the last state of the button, the last time the button was debounced, and the debounce delay.
  The class has a constructor that initializes these variables and sets the pin mode to INPUT_PULLUP.
  The class has a public function called read() that reads the state of the button and debounces it.
  It does this by checking if the current reading is different from the last state, and if it is, it sets the last debounce time to the current time.
  If the difference between the current time and the last debounce time is greater than the debounce delay, it updates the state of the button to the current reading.
  In the loop() function, the program reads the state of the button using the read() function and checks if the button is pressed.
  If the button is pressed, the program prints a message to the serial monitor.
*/

#include <Arduino.h> //include library
#include "PushButton.h" //include library

PushButton button(2); //pb connected to digital pin 2 on arduino

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //start serial monitor
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState = button.getState(); //recieve button state

  if (buttonState == HIGH) { //state of button
    Serial.println("Button is pressed"); //serial print, text printed once button is pressed
  }
}
