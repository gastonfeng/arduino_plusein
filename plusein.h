#include <Arduino.h>
#define nrs 32
class plusein
{
  public:
    plusein(uint8 pin, uint32 min, uint32 max);
    void poll();
    float freq();

  private:
    uint8 pin;
    uint8 last_level,index;
    uint32 last_tick, min, max,period,buf[nrs],sum;
};