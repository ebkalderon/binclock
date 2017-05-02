#include "Alarm.hpp"
#include "Display.hpp"
#include "Time.hpp"

Alarm alarm;
Display *display;
Time now;

void setup()
{
    // Initialize the 16x8 LED matrix display.
    display = new Display();

    // Open a serial connection through USB.
    Serial.begin(9600);
    while (!Serial);

    Serial.print("Enter current time (24-hour format, no colon)");
    while (Serial.available() == 0)
        display->print_scrolling_text("No time set");

    // Set the initial time of the clock.
    String initial_time = Serial.readStringUntil('\n');
    now = Time(initial_time);
    Serial.println(" => " + now.to_string());
    display->print_static_text("OK");

    Serial.print("Enter time to ring alarm (24-hour format, no colon)");
    while (Serial.available() == 0)
        display->print_scrolling_text("No alarm set");

    /// Configure the alarm.
    String ring_time = Serial.readStringUntil('\n');
    alarm = Alarm(ring_time);
    Serial.println(" => " + Time(ring_time).to_string());
    display->print_static_text("OK");

    Serial.println("Clock has been configured!");
}

void loop()
{
    now.tick();
    display->print_time_binary(now);
    alarm.trigger(now);
}
