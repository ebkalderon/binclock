#include <Arduino.h>
#include <Wire.h>
#include "Alarm.hpp"

Alarm::Alarm()
{
    this->buzzer_pin = 9;
    this->is_ringing = false;
    this->start_time = Time(12, 00);
    this->stop_time = Time(12, 01);
}

Alarm::Alarm(const Time &val)
{
    this->buzzer_pin = 9;
    this->is_ringing = false;
    this->start_time = val;
    this->stop_time = Time(String(val.to_int() + 1));
}

Alarm::Alarm(const String &str)
{
    this->buzzer_pin = 9;
    this->is_ringing = false;
    this->start_time = Time(str);
    this->stop_time = Time(String(str.toInt() + 1));
}

void Alarm::trigger(const Time &cur_time)
{
    if (!is_ringing && (cur_time == start_time)) {
        tone(buzzer_pin, 4000);
        is_ringing = true;
        Serial.println("Ring!");
    }

    if (is_ringing && (cur_time == stop_time)) {
        noTone(buzzer_pin);
        is_ringing = false;
        Serial.println("*quiet*");
    }
}

void Alarm::set_buzzer_pin(int val)
{
    buzzer_pin = val;
}
