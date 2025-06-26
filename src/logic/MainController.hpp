#pragma once
#include "WingController.hpp"

// Main controller that manages both wings
// کنترلر اصلی که دو بال را مدیریت می‌کند
class MainController
{
private:
    // Unique ownership of right wing controller
// مالکیت یکتای کنترلر بال راست
    std::unique_ptr<WingController> rightWing;
    // Unique ownership of left wing controller
// مالکیت یکتای کنترلر بال چپ
    std::unique_ptr<WingController> leftWing;

public:
    // Constructor receives two wing controllers and takes ownership
// سازنده که دو کنترلر بال را دریافت و مالکیت را منتقل می‌کند
    MainController(std::unique_ptr<WingController> _rightWing , std::unique_ptr<WingController> _leftWing);
    
    // Main loop to check sensors and control relays accordingly
// حلقه اصلی برای بررسی سنسورها و کنترل رله‌ها بر اساس وضعیت
    void run();
};

// Constructor implementation
// پیاده‌سازی سازنده
MainController::MainController(std::unique_ptr<WingController> _rightWing , std::unique_ptr<WingController> _leftWing)
    : rightWing(std::move(_rightWing)), leftWing(std::move(_leftWing)){}

// Run method applies the logic:
// If both wings fail, turn both relays off.
// If right wing fails, turn off right relay and turn on left relay.
// Otherwise, turn off left relay and turn on right relay.
// متد run منطق زیر را پیاده‌سازی می‌کند:
// اگر هر دو بال خطا داشتند، هر دو رله را خاموش کن.
// اگر بال راست خطا داشت، رله راست را خاموش و رله چپ را روشن کن.
// در غیر اینصورت، رله چپ را خاموش و رله راست را روشن کن.
void MainController::run(){
    
    if (rightWing->checkSensors() == WingStatus::FAIL && leftWing->checkSensors() == WingStatus::FAIL)
    {
        rightWing->turnOffRelay();
        leftWing->turnOffRelay();
    }
    else if (rightWing->checkSensors() == WingStatus::FAIL)
    {
        rightWing->turnOffRelay();
        leftWing->turnOnRelay();
    }
    else
    {
        leftWing->turnOffRelay();
        rightWing->turnOnRelay();
    }
}
