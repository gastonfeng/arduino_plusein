#include "plusein.h"
plusein::plusein(uint8 pin, uint32 min, uint32 max)
{
    this->pin = pin;
    this->max = max;
    this->min = min;
    pinMode(this->pin, INPUT);
    this->last_level = digitalRead(this->pin);
    this->last_tick = micros();
    index=0;
    sum=0;
}

void plusein::poll()
{
    uint8 l = digitalRead(pin);
    uint32 t = micros();
    if (last_level != l)
    {
        uint32 tick = t - last_tick;
        if (tick > max)
        {
        }
        else if (tick < min)
        {
        }
        else
        {
            sum-=buf[index];
            buf[index]=tick;
            sum+=buf[index];
            period = sum/(nrs/2);
            index++;
            if(index>=nrs)index=0;
        }
        last_level = l;
        last_tick = t;
    }
}
float plusein::freq()
{
    if (period == 0)
        return 0;
    return 1000000 / period;
}