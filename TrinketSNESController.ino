/*
 * TrinketSNESController.ino
 * Created by Zachary Ferguson
 * Connects the trinket with a SNES contoller to act as a keyboard and get button presses.
 * More info: http://www.mit.edu/~tarvizo/nes-controller.html
 */

#include <TrinketKeyboard.h>

#define LATCH_PIN 0
#define DATA_PIN 1
#define CLOCK_PIN 2

#define SET_LATCH(state) digitalWrite(LATCH_PIN, state)
#define SET_CLOCK(state) digitalWrite(CLOCK_PIN, state)
#define GET_DATA() digitalRead(DATA_PIN)

#define WAIT(microsec) delayMicroseconds(microsec)

/*
 * Keycodes:
 * Clock Cycle     Button Reported
 * ===========     ===============
 *  1               B
 *  2               Y
 *  3               Select
 *  4               Start
 *  5               Up on joypad
 *  6               Down on joypad
 *  7               Left on joypad
 *  8               Right on joypad
 *  9               A
 *  10              X
 *  11              L
 *  12              R
 *  13              none (always high)
 *  14              none (always high)
 *  15              none (always high)
 *  16              none (always high)
 */
const byte buttonCodes[] = {
    KEYCODE_B,
    KEYCODE_Y,
    KEYCODE_BACKSPACE,
    KEYCODE_ENTER,
    KEYCODE_ARROW_UP,
    KEYCODE_ARROW_DOWN,
    KEYCODE_ARROW_LEFT,
    KEYCODE_ARROW_RIGHT,
    KEYCODE_A,
    KEYCODE_X,
    KEYCODE_L,
    KEYCODE_R   
  };

unsigned short pressedButtons;

/* Initializes the pins. */
void setup()
{
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode( DATA_PIN,  INPUT);

  pressedButtons = 0;
  
  /* Start the usb keyboard. */
  TrinketKeyboard.begin();
}

/* Gets the buttons being pressed and then presses the corresponding key. */
void loop()
{
  /* Communicate with the computer. */
  TrinketKeyboard.poll();
  delay(3);
  
  unsigned short data = getSNESData();

  byte i;
  for(i = 0; i < 12; i++)
  {
    if((data >> i) & 0x01 && !((pressedButtons >> i) & 0x1))
    {
      TrinketKeyboard.pressKey(0, buttonCodes[i]);
      pressedButtons |= 0x01 << i;
      //TrinketKeyboard.print("Pressed");
    }
    else if(!((data >> i) & 0x01) && (pressedButtons >> i) & 0x1)
    {
      pressedButtons &= ~(0x01 << i);
      TrinketKeyboard.pressKey(0, 0);
      //TrinketKeyboard.print("Released");
    }
  }
}

/* Gets the button pressed data and returns it as bits of a short. */
unsigned short getSNESData()
{
  unsigned short data = 0;
  
  /* Tell the SNES controller to send data. */
  SET_LATCH(LOW);
  SET_CLOCK(LOW);
  
  SET_LATCH(HIGH);
  WAIT(12);
  SET_LATCH(LOW);

  byte i;
  for (i = 0; i < 16; i++)
  {
    WAIT(6);
    SET_CLOCK(LOW);

    /* Save if button i is being pressed, 1, or not, 0. */ 
    data |= ((GET_DATA() == LOW ? 1:0) << i);
    
    WAIT(6);
    SET_CLOCK(HIGH);
  }

  return data;
}
