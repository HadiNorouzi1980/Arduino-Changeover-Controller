#pragma once

#include <vector>
#include <memory>
#include "../include/Interfaces/IRelay.hpp"
#include "../include/Interfaces/ISensors.hpp"

// Status of a wing after sensor check
// وضعیت یک بال پس از بررسی سنسورها
enum class WingStatus{
    OK,    // All sensors are OK - همه سنسورها سالم هستند
    FAIL   // At least one sensor failed - حداقل یک سنسور خطا داده است
};

class WingController
{
private:
    // List of sensors on this wing (unique ownership)
// لیستی از سنسورهای بال که کنترل این کلاس است (مالکیت یکتا)
    std::vector<std::unique_ptr<ISensors>> sensors;
    // Relay controlling this wing (unique ownership)
// رله کنترل‌کننده این بال (مالکیت یکتا)
    std::unique_ptr<IRelay> relay;

public:
    // Constructor accepts sensors and relay, transfers ownership
// سازنده که لیست سنسورها و رله را دریافت و مالکیت را منتقل می‌کند
    WingController(std::vector<std::unique_ptr<ISensors>> _sensors , std::unique_ptr<IRelay> _relay);

    // Checks all sensors; returns OK if all good, FAIL if any sensor fails
// بررسی همه سنسورها؛ اگر همه سالم بودند OK و در غیر اینصورت FAIL برمی‌گرداند
    WingStatus checkSensors();

    // Turn relay off
// خاموش کردن رله
    void turnOffRelay();

    // Turn relay on
// روشن کردن رله
    void turnOnRelay();
};

// Constructor implementation
// پیاده‌سازی سازنده
WingController::WingController(std::vector<std::unique_ptr<ISensors>> _sensors , std::unique_ptr<IRelay> _relay)
    : sensors(std::move(_sensors)), relay(std::move(_relay)){}

// Check sensors sequentially and return FAIL on first failure
// بررسی سنسورها به ترتیب و بازگشت FAIL در اولین خطا
WingStatus WingController::checkSensors(){
    for(auto const& sensor: sensors){
        if (!sensor->isOk())
        {
            return WingStatus::FAIL;
        }
    }
    return WingStatus::OK;
}

// Turn relay off by calling the relay's turnOff method
// خاموش کردن رله با فراخوانی متد turnOff رله
void WingController::turnOffRelay(){
    relay->turnOff();
}

// Turn relay on by calling the relay's turnOn method
// روشن کردن رله با فراخوانی متد turnOn رله
void WingController::turnOnRelay(){
    relay->turnOn();
}
