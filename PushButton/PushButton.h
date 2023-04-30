#ifndef PUSHBUTTON_H //if not defined
#define PUSHBUTTON_H //define library in use

#include <Arduino.h> //include library

class PushButton { //pb class
  private: //private
    int pin; //pb pin
    int state; //state of pb
    int lastReading; //last reading of pb state
    unsigned long lastDebounceTime; //debounce previous time
    unsigned long debounceDelay; //debounce delay

  public: //public
    PushButton(int p); //contructor
    int getState(); //read state of pb
};

#endif
