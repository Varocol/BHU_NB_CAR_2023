#include "Hardware.h"
#include "Task.h"
void setup()
{
  // if (Hardware_Init())
  // {
  //   debug_init();
  // }
  Hardware_Init();
}

void loop()
{
  data_json();
}
