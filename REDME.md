# Wings Controller Project / پروژه کنترلر بال‌ها

## Introduction / معرفی

This project is a controller system for managing two independent wings, each connected to multiple sensors and one relay.  
The goal is to monitor sensor states and control relays accordingly for each wing's health status.  
Written in C++ using a three-layer architecture, developed for STM32 board with Arduino framework.

این پروژه یک سیستم کنترلر برای مدیریت دو بال مستقل است که هر بال به چند سنسور و یک رله متصل است.  
هدف کنترل وضعیت سنسورها و روشن/خاموش کردن رله‌ها بر اساس سلامت هر بال است.  
این پروژه به زبان ++C و با استفاده از معماری سه لایه نوشته شده و روی برد STM32 با فریمورک آردوینو توسعه یافته است.

## Project Structure / ساختار پروژه

- `src/hardware` : Real hardware implementation (sensors and relays)  
- `src/logic` : Controller logic (WingController and MainController)  
- `include/Interfaces` : Interface definitions for sensors and relays  
- `src/main.cpp` : Program entry point, configuration and running controller

- `src/hardware` : پیاده‌سازی سخت‌افزار واقعی (سنسورها و رله‌ها)  
- `src/logic` : منطق کنترلر (WingController و MainController)  
- `include/Interfaces` : تعریف اینترفیس‌ها برای سنسورها و رله‌ها  
- `src/main.cpp` : نقطه ورود برنامه، پیکربندی و اجرای کنترلر

## How to Build and Run / نحوه ساخت و اجرای پروژه

1. Use PlatformIO in VSCode.  
2. Select STM32F103C8 (Blue Pill) board.  
3. Compile the project and flash it to the board.  
4. Observe sensor inputs and relay states.

1. از نرم‌افزار PlatformIO در VSCode استفاده کنید.  
2. برد STM32F103C8 (Blue Pill) را انتخاب کنید.  
3. پروژه را کامپایل کرده و روی برد فلش کنید.  
4. ورودی سنسورها و وضعیت رله‌ها را مشاهده کنید.

## Class Explanation / توضیح کلاس‌ها

- `ISensors` : Base interface for sensors with `isOk()` method  
- `IRelay` : Base interface for relay with `turnOn()` and `turnOff()` methods  
- `HardwareSensors` : Real sensor implementation with pin and active state  
- `HardwareRelay` : Hardware relay implementation controlling output pin  
- `WingController` : Controls one wing with a set of sensors and one relay  
- `MainController` : Manages and coordinates two WingControllers with priority and relay logic

- `ISensors` : اینترفیس پایه سنسورها با تابع `isOk()`  
- `IRelay` : اینترفیس پایه رله با توابع `turnOn()` و `turnOff()`  
- `HardwareSensors` : پیاده‌سازی سنسورهای واقعی با پین و وضعیت فعال (ActiveHigh)  
- `HardwareRelay` : پیاده‌سازی رله سخت‌افزاری با کنترل پین خروجی  
- `WingController` : کنترل یک بال با مجموعه‌ای از سنسورها و یک رله  
- `MainController` : مدیریت و هماهنگی دو WingController با قوانین اولویت و قطع رله‌ها

## Important Notes / نکات مهم

- Sensors and relays are managed with `unique_ptr` for clear ownership.  
- C++17 standard features are used.  
- Arduino library and PlatformIO are recommended for development.

- سنسورها و رله‌ها با اشاره‌گر هوشمند `unique_ptr` مدیریت می‌شوند تا مالکیت منابع به صورت واضح باشد.  
- از استاندارد C++17 و امکانات آن استفاده شده است.  
- برای توسعه، کتابخانه Arduino و PlatformIO توصیه می‌شود.

## License / لایسنس

MIT License

---

