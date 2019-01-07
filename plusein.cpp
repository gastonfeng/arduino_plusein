#include "plusein.h"
plusein::plusein(uint8 pin, uint32 min, uint32 max)
{
    this->pin = pin;
    this->max = max;
    this->min = min;
    pinMode(this->pin, INPUT);
    this->last_level = digitalRead(this->pin);
    this->last_tick = millis();
}

void plusein::poll()
{
    uint8 l = digitalRead(pin);
    uint32 t = millis();
    if (last_level != l)
    {
        uint32 tick = t - last_tick;
        if (tick > max)
        {
            period = 0;
        }
        else if (tick < min)
        {
            period = 0;
        }
        else
        {
            period += tick;
        }
        last_level = l;
        last_tick = t;
    }
}
float plusein::freq()
{
    if (period == 0)
        return 0;
    return 10000 / period;
}