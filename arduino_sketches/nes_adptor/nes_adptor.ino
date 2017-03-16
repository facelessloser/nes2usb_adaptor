#include <NESpad.h> // https://github.com/joshmarinacci/nespad-arduino
#include <Joystick.h> // https://github.com/MHeironimus/ArduinoJoystickLibrary/tree/version-1.0

// put your own strobe/clock/data pin numbers here -- see the pinout in readme.txt
NESpad nintendo = NESpad(2,3,4);

byte state = 0;

/* A button gets marked as true as soon as it is pressed. That way
we know to not "press" it again */
boolean a = false; //A      Button
boolean b = false; //B      Button
boolean u = false; //Up     Button
boolean d = false; //Down   Button
boolean l = false; //Left   Button
boolean r = false; //Right  Button
boolean s = false; //Start  Button
boolean e = false; //Select Button

void setup() {
  Serial.begin(9600);    
  Joystick.begin();
}

void loop() {

  delay(5);

  state = nintendo.buttons();

  // A
  if (state & NES_A)
  {
    if(!a)
    {
      a = true; //Make sure the button is only pressed once
      Joystick.pressButton(0);
    }
  }
 //Key might have been released so we check and if so change the
 //value in our released array
  else if (a == true)
  {
    a = false;
    Joystick.releaseButton(0);
  }

  // B
  if (state & NES_B)
  {
    if(!b)
    {
      b = true; //Make sure the button is only pressed once
      Joystick.pressButton(1);
    }
  }
  //Key might have been released so we check and if so change the
  //value in our released array
  else if (b == true)
  {
    b = false;
    Joystick.releaseButton(1);
  }

  // Up
  if (state & NES_UP)
  {
    if(!u)
    {
      u = true; //Make sure the button is only pressed once
      Joystick.pressButton(2);
    }
  }
  //Key might have been released so we check and if so change the
  //value in our released array
  else if (u == true)
  {
    u = false;
    Joystick.releaseButton(2);
  }

  // Down
  if (state & NES_DOWN)
  {
    if(!d)
    {
      d = true; //Make sure the button is only pressed once
      Joystick.pressButton(3);
    }
  }
  //Key might have been released so we check and if so change the
  //value in our released array
  else if (d == true)
  {
    d = false;
    Joystick.releaseButton(3);
  }

  // Left
  if (state & NES_LEFT)
  {
    if(!l)
    {
      l = true; //Make sure the button is only pressed once
      Joystick.pressButton(4);
    }
  }
  //Key might have been released so we check and if so change the
  //value in our released array
  else if (l == true)
  {
    l = false;
    Joystick.releaseButton(4);
  }

  //Right
  if (state & NES_RIGHT)
  {
    if(!r)
    {
      r = true; //Make sure the button is only pressed once
      Joystick.pressButton(5);
    }
  }
  //Key might have been released so we check and if so change the
  //value in our released array
  else if (r == true)
  {
    r = false;
    Joystick.releaseButton(5);
  }

  //Start
  if (state & NES_START)
  {
    if(!s)
    {
      s = true; //Make sure the button is only pressed once
      Joystick.pressButton(6);
    }
  }
  //Key might have been released so we check and if so change the
  //value in our released array
  else if (s == true)
  {
    s = false;
    Joystick.releaseButton(6);
  }

  //Select
  if (state & NES_SELECT)
  {
    if(!e)
    {
      e = true; //Make sure the button is only pressed once
      Joystick.pressButton(7);
    }
  }
  //Key might have been released so we check and if so change the
  //value in our released array
  else if (e == true)
  {
    e = false;
    Joystick.releaseButton(7);
  }

}
