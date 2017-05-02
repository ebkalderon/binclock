#ifndef TIME_HPP
#define TIME_HPP

// Standard 24-hour time value, suitable for display on a clock.
class Time {
public:
    // Creates a new `Time` instance with an initial value of 00:00.
    Time();

    // Creates a new `Time` instance with the given values.
    Time(unsigned hours, unsigned minutes);

    // Parses the given string and creates a new `Time` instance from it. The
    // string must consist of four consecutive positive integers, representing
    // a valid time value in 24-hour format.
    Time(String str);

    // Overloads the `==` operator for equality checking.
    bool operator ==(const Time &rhs);

    // Updates the time value according to the system clock.
    void tick();

    // Returns a string representation of the raw binary time value, with the
    // hours in the first 5 bits and the minutes in the remaining 6 bits
    // ("HHHHHMMMMMM").
    String to_binary_string();

    // Returns the integer time value in as one (1) to four (4) digit unsigned
    // integer value (HHMM).
    unsigned to_int();

    // Returns a string containing the human-readable time value ("HH:MM").
    String to_string();

private:
    unsigned hours;
    unsigned minutes;
    unsigned long last_tick_ms;
};

#endif // TIME_HPP
