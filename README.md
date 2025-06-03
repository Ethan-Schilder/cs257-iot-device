# cs257-iot-device

## Description
The thermostat on auto won't stop heating after reaching the target temp!

## Steps to Reproduce
1. Compile with `g++ -o device main.cpp`
2. Run `./device`
3. Observe the results in the terminal (Second entry)
4. Thermostat Status:
  Current Temp: 72°F
  Target Temp: 72°F
  Mode: off
  Heating: OFF
  Cooling: OFF
Mode changed to auto
Target temperature set to 75°F
Thermostat Status:
  Current Temp: 77°F
  Target Temp: 75°F
  Mode: auto
  Heating: ON
  Cooling: OFF

## Expected Behavior
Upon exceeding target temp by 2 degrees the thermostat should redirect its effort to cooling the room back down and disabling heating.

## Actual Behavior
Upon exceeding the target temp by 2 the thermostat doesn't stop heating the room and begin trying to cool the room. Resulting in temprature continuing to rise which makes auto useless.
Needs to be fixed asap or else we'll be shipping broken smart thermostats.

## Environment
- OS: Ubuntu 22.04
- Compiler: g++ 11.4.0

## Possible Solution
Some issue in if else branches relating to target temp?

## Test Case

