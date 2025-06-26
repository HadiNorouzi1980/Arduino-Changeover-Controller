#pragma once

#include <Arduino.h>
#include "Interfaces/IRelay.hpp"

// Concrete implementation of IRelay using Arduino digital pins
// پیاده‌سازی واقعی IRelay با استفاده از پایه‌های دیجیتال آردوینو

class HardwareRelay : public IRelay
{
private:
    uint8_t pin; // Arduino pin connected to the relay
                 // پایه‌ی آردوینو که به رله متصل است
public:
    // Constructor to initialize the relay pin
    // سازنده برای مقداردهی اولیه به پایه‌ی رله
    HardwareRelay(uint8_t _pin);

    // Turns the relay on
    // روشن کردن رله
    void turnOn() override;

    // Turns the relay off
    // خاموش کردن رله
    void turnOff() override;
};

// Constructor implementation
// پیاده‌سازی سازنده
HardwareRelay::HardwareRelay(uint8_t _pin) : pin(_pin)
{
    pinMode(pin, OUTPUT);     // Set the pin as output
                              // تنظیم پایه به عنوان خروجی
    digitalWrite(pin, LOW);   // Ensure the relay is off initially
                              // اطمینان از اینکه رله در ابتدا خاموش است
}

// Turn on the relay by setting pin HIGH
// روشن کردن رله با قرار دادن پایه در وضعیت HIGH
void HardwareRelay::turnOn(){
    digitalWrite(pin, HIGH);
}

// Turn off the relay by setting pin LOW
// خاموش کردن رله با قرار دادن پایه در وضعیت LOW
void HardwareRelay::turnOff(){
    digitalWrite(pin, LOW);
}
