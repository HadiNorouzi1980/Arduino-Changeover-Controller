#pragma once
#include <Arduino.h>
#include "../include/Interfaces/ISensors.hpp"

// Concrete implementation of ISensors using Arduino digital pins
// پیاده‌سازی واقعی ISensors با استفاده از پایه‌های دیجیتال آردوینو

class HardwareSensors : public ISensors
{
private:
    uint8_t pin;       // Arduino pin connected to the sensor
                       // پایه آردوینو که به سنسور متصل است
    bool ActiveHigh;   // True if sensor is active HIGH, false if active LOW
                       // اگر سنسور فعال شدنش با سیگنال HIGH باشد، true است، در غیر اینصورت false
public:
    // Constructor: sets the pin and active signal type (default true = active HIGH)
    // سازنده: پایه و نوع فعال بودن سنسور را مقداردهی می‌کند (پیشفرض فعال بودن با HIGH)
    explicit HardwareSensors(uint8_t _pin , bool _ActiveHigh = true);

    // Checks if sensor is active (returns true if pin reads HIGH or LOW depending on ActiveHigh)
    // بررسی وضعیت سنسور (مقدار HIGH یا LOW را بسته به نوع ActiveHigh برمی‌گرداند)
    bool isOk() override;
};

// Constructor implementation
// پیاده‌سازی سازنده
explicit HardwareSensors::HardwareSensors(uint8_t _pin , bool _ActiveHigh) : pin(_pin) , ActiveHigh(_ActiveHigh)
{
    pinMode(pin , INPUT); // Set pin as input
                         // تنظیم پایه به عنوان ورودی
}

// Read sensor state and compare to expected active signal
// خواندن وضعیت سنسور و مقایسه با سیگنال فعال مورد انتظار
bool HardwareSensors::isOk(){
    return digitalRead(pin) == (ActiveHigh ? HIGH : LOW);
}
