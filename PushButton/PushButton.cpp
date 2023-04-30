#include "PushButton.h" //include pushbutton header

PushButton::PushButton(int p) { //pb
  pin = p; //pin = p
  state = LOW; //state of pb not pressed
  lastReading = LOW; //recent reading of pb state
  lastDebounceTime = 0; //previous debounce time
  debounceDelay = 50; //debounce delay time
  pinMode(pin, INPUT); //set pin as input
}

int PushButton::getState() { //read state of pb
  int reading = digitalRead(pin); //read state of pin

  if (reading != lastReading) { //check if state changed since previous result
    lastDebounceTime = millis(); //debounce time set in millis
  }

  if ((millis() - lastDebounceTime) > debounceDelay) { //check reading of previous debounce, if greater than debouce value
    if (reading != state) { //read if buttonstate changed
      state = reading; //buttonstate
    }
  }

  lastReading = reading; //save the reading state of pb
  return state; //reset
}
