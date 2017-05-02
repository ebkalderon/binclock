#include <Arduino.h>
#include "Time.hpp"

const static unsigned long MINUTE_LEN_IN_MS = 60000;
const static unsigned MINUTES_IN_HOUR = 60;
const static unsigned HOURS_IN_DAY = 24;

Time::Time()
{
    this->hours = 0;
    this->minutes = 0;
    this->last_tick_ms = millis();
}

Time::Time(unsigned hours, unsigned minutes)
{
    this->hours = hours;
    this->minutes = minutes;
    this->last_tick_ms = millis();
}

Time::Time(String str)
{
    while (str.length() < 4)
        str = "0" + str;

    String hours = str.substring(0, 2);
    String minutes = str.substring(2, 4);

    this->hours = hours.toInt();
    this->minutes = minutes.toInt();
    this->last_tick_ms = millis();
}

bool Time::operator ==(const Time &rhs)
{
    bool mins_eq = this->minutes == rhs.minutes;
    bool hours_eq = this->hours == rhs.hours;
    return mins_eq && hours_eq;
}

void Time::tick()
{
    unsigned long now = millis();
    
    if (now >= last_tick_ms + MINUTE_LEN_IN_MS) {
        unsigned num_minutes_passed = (now - last_tick_ms) / MINUTE_LEN_IN_MS;
        minutes += num_minutes_passed;

        if (minutes >= MINUTES_IN_HOUR) {
            minutes = 0;
            hours++;
            
            if (hours >= HOURS_IN_DAY)
                hours = 0;
        }

        Serial.println("Integer time is: " + to_string());
        Serial.println("Binary time is: " + to_binary_string());

        last_tick_ms = now;
    }
}

String Time::to_binary_string()
{
    String time_bin = "";

    for (int i = 4; i >= 0; i--) {
        unsigned bit = (hours >> i) & 1;
        time_bin += bit;
    }

    for (int i = 5; i >= 0; i--) {
        unsigned bit = (minutes >> i) & 1;
        time_bin += bit;
    }

    return time_bin;
}

unsigned Time::to_int()
{
    return (hours * 100) + minutes;
}

String Time::to_string()
{
    char time[6] = { 0 };
    sprintf(time, "%02u:%02u", hours, minutes);

    return String(time);
}
