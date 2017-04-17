#include <DigiMouse.h>
//#include <DigiKeyboard.h>
#define LED 1
void setup() {
  DigiMouse.begin();
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

boolean rndflag() { return random(1) > .5; }

int x,y;
bool flag;
int count = 0;

void loop() {
  x=random(-50,50);
  y=random(-50,50);
  DigiMouse.moveX(x);
  DigiMouse.moveY(y);
  DigiMouse.delay(500);
  flag = rndflag();
  if(count % 3 == 0)
  {
    DigiMouse.setButtons(1<<0); //left click
    DigiMouse.delay(10);
    DigiMouse.setButtons(0); //unclick all
    digitalWrite(LED, HIGH);
  }
  if (count % 2 == 0)
  {
    
    DigiMouse.scroll(-5);
  }
  else
  {
    digitalWrite(LED, LOW);
    DigiMouse.scroll(5);
  }
  count++;
}
