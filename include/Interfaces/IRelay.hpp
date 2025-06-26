#pragma once

// Interface for controlling a relay device
// رابط کنترل یک دستگاه رله

class IRelay
{
private:
    // No private members needed for an interface
    // برای اینترفیس نیازی به عضو خصوصی نیست
public:
    // Turns the relay on
    // روشن کردن رله
    virtual void turnOn() = 0;

    // Turns the relay off
    // خاموش کردن رله
    virtual void turnOff() = 0;

    // Virtual destructor to ensure proper cleanup in derived classes
    // سازنده مجازی برای پاک‌سازی صحیح در کلاس‌های مشتق‌شده
    virtual ~IRelay() = default;
};
