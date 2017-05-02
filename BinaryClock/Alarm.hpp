#ifndef ALARM_HPP
#define ALARM_HPP

#include "Time.hpp"

class Alarm {
public:
    // Creates a new `Alarm` with a default ring time of 12:00 noon.
    Alarm();

    // Creates a new `Alarm` instance with the given ring time.
    Alarm(const Time &val);

    // Parses the given string and creates a new `Alarm` instance from it. The
    // string must consist of four consecutive positive integers, representing
    // a valid time value in 24-hour format.
    Alarm(const String &str);

    // Triggers the alarm if the time value is equal to the ring time,
    // then turns the alarm off automatically once it's been ringing for
    // over 1 minute and 5 seconds.
    void trigger(const Time &cur_time);

    // Sets which output pin controls the alarm buzzer.
    void set_buzzer_pin(int val);

private:
    int buzzer_pin;
    bool is_ringing;
    Time start_time;
    Time stop_time;
};

#endif // ALARM_HPP
