#pragma once

// Interface for reading sensor status
// رابط برای بررسی وضعیت سنسور

class ISensors
{
private:
    // No private members required for interface
    // نیازی به اعضای خصوصی در اینترفیس نیست
public:
    // Checks if the sensor is functioning correctly
    // بررسی اینکه آیا سنسور به درستی کار می‌کند یا نه
    virtual bool isOk() = 0;

    // Virtual destructor to ensure proper cleanup in derived classes
    // سازنده مجازی برای پاکسازی درست در کلاس‌های مشتق‌شده
    virtual ~ISensors() = default;
};
