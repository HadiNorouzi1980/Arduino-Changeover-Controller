// File: src/main.cpp

#include <Arduino.h>
#include "../src/hardware/HardwareRelay.hpp"
#include "../src/hardware/HardwareSensors.hpp"
#include "../src/logic/WingController.hpp"
#include "../src/logic/MainController.hpp"

// Create a smart pointer for the main controller
std::unique_ptr<MainController> controller;

void setup() {
  // Right wing sensors setup
  std::vector<std::unique_ptr<ISensors>> rightSensors;
  rightSensors.push_back(std::make_unique<HardwareSensors>(2, true));
  rightSensors.push_back(std::make_unique<HardwareSensors>(3, true));
  rightSensors.push_back(std::make_unique<HardwareSensors>(4, true));

  // Left wing sensors setup
  std::vector<std::unique_ptr<ISensors>> leftSensors;
  leftSensors.push_back(std::make_unique<HardwareSensors>(5, true));
  leftSensors.push_back(std::make_unique<HardwareSensors>(6, true));
  leftSensors.push_back(std::make_unique<HardwareSensors>(7, true));

  // Initialize relays for both wings
  auto rightRelay = std::make_unique<HardwareRelay>(8);
  auto leftRelay = std::make_unique<HardwareRelay>(9);

  // Create WingController instances for each wing
  auto rightWing = std::make_unique<WingController>(std::move(rightSensors), std::move(rightRelay));
  auto leftWing  = std::make_unique<WingController>(std::move(leftSensors), std::move(leftRelay));

  // Construct the main controller with both wings
  controller = std::make_unique<MainController>(std::move(rightWing), std::move(leftWing));
}

void loop() {
  // Periodically check the system state and update relays
  controller->run();
  delay(500);
}
