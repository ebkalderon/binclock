#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "Time.hpp"

// Represents a 16-by-8 LED matrix display.
class Display {
public:
    // Creates a new handle to the display.
    Display();

    // Outputs some rapidly scrolling text.
    void print_scrolling_text(const String &text);

    // Displays some static text for one (1) second and then clears the screen.
    // If the text is too long to fit in the frame, the extra characters will
    // be trimmed off.
    void print_static_text(const String &text);

    // Displays the given `Time` value in binary using vertical bars. Lit
    // columns represent a one (1) while dark columns represent a zero (0).
    void print_time_binary(const Time &val);
};

#endif // DISPLAY_HPP
