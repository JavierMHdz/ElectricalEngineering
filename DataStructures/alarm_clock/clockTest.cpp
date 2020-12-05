#include <iostream>
#include "clock.h"
using namespace std;

int main 9)
{
   Clock c1;
   c1.printTime();
   Clock c2(13, 48, 00);
   c2.setAlarmTime(13,48,30);
   c2.toggleEnable();
   for (int i = 0; i < 35; i++)
   {
      c2.tick();
      c2.printTime();
   }
}
