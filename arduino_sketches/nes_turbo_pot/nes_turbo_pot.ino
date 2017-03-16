#include <NESpad.h> // https://github.com/joshmarinacci/nespad-arduino
#include <Joystick.h> // https://github.com/MHeironimus/ArduinoJoystickLibrary/tree/version-1.0

// put your own strobe/clock/data pin numbers here -- see the pinout in readme.txt
NESpad nintendo = NESpad(2,3,4);

byte state = 0;
int turboSwitch = 0; // State of turbo switch
const int switchPin = 6; // Pin of turbo switch
int potPin = 0; // select the input pin for the potentiometer
int turboVal = 0; // Reading from the pot
int mappedTurboVal = 0;
long doubleit = 0;

unsigned long previousMillis = 0;

long turboSince1;
long turboSince2;

const int turboLedPin =  10;      // the number of the LED pin

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
  Joystick.begin();
  pinMode(switchPin, INPUT_PULLUP); // Turbo switch
  Serial.begin(9600);
  pinMode(turboLedPin, OUTPUT);
}

void loop() {

  turboSwitch = digitalRead(switchPin); // Read turbo switch pin
  turboVal = analogRead(potPin); // Read analog pin (pot)
  mappedTurboVal = map(turboVal, 1, 1023, 40, 200); // Map the pot values
  doubleit = mappedTurboVal*2; // Double the mapped reading from the pot

  state = nintendo.buttons();

  if (turboSwitch == HIGH)
  {
    digitalWrite(turboLedPin, HIGH);

    // A
    if (state & NES_A)
    {
      if(!a)
      {
        if (millis() - turboSince1 >= mappedTurboVal)
        {
          turboSince1 = millis();
          Joystick.pressButton(0);
        }
        if (millis() - turboSince2 >= doubleit)
        {
          turboSince2 = millis();
          Joystick.releaseButton(0);
        }
      }
    }

    // B
    if (state & NES_B)
    {
      if(!b)
      {
        if (millis() - turboSince1 >= mappedTurboVal)
        {
          turboSince1 = millis();
          Joystick.pressButton(1);
        }
        if (millis() - turboSince2 >= doubleit)
        {
          turboSince2 = millis();
          Joystick.releaseButton(1);
        }
      }
    }

  }

  else
  {
    digitalWrite(turboLedPin, LOW);
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
