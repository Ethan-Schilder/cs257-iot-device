#include <iostream>
#include <string>

class SmartThermostat {
private:
    float currentTemp;
    float targetTemp;
    bool isHeating;
    bool isCooling;
    std::string mode;

public:
    SmartThermostat() : currentTemp(72.0), targetTemp(72.0), 
                       isHeating(false), isCooling(false), mode("off") {}
    
    void setTargetTemp(float temp) {
        targetTemp = temp;
        std::cout << "Target temperature set to " << targetTemp << "°F" << std::endl;
        updateSystem();
    }
    
    void setMode(const std::string& newMode) {
        mode = newMode;
        std::cout << "Mode changed to " << mode << std::endl;
        updateSystem();
    }
    
    void updateSystem() {
        isHeating = false; // Reset states
        isCooling = false;
        if (mode == "heat" && currentTemp < targetTemp) {
            isHeating = true;
        } else if (mode == "cool" && currentTemp > targetTemp) {
            isCooling = true;
        } else if (mode == "auto") {
            if (currentTemp <= targetTemp - 2) { // Heat if 2°F or more below
                isHeating = true;
            } else if (currentTemp >= targetTemp + 2) { // Cool if 2°F or more above
                isCooling = true;
            }
        }
    }
    
    void simulateTemperatureChange() {
        if (isHeating) currentTemp += 0.5;
        if (isCooling) currentTemp -= 0.5;
    }
    
    void displayStatus() {
        std::cout << "Thermostat Status:" << std::endl;
        std::cout << "  Current Temp: " << currentTemp << "°F" << std::endl;
        std::cout << "  Target Temp: " << targetTemp << "°F" << std::endl;
        std::cout << "  Mode: " << mode << std::endl;
        std::cout << "  Heating: " << (isHeating ? "ON" : "OFF") << std::endl;
        std::cout << "  Cooling: " << (isCooling ? "ON" : "OFF") << std::endl;
    }
};

int main() {
    SmartThermostat myThermostat;
    myThermostat.displayStatus();
    myThermostat.setMode("auto"); // User input here
    myThermostat.setTargetTemp(80.0); // User input here
    for (int i = 0; i < 10; i++) {
        myThermostat.simulateTemperatureChange();
        myThermostat.updateSystem(); // Update after temp change
    }
    myThermostat.displayStatus();
    return 0;
}