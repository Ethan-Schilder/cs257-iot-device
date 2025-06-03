# cs257-iot-device

## Description
The thermostat won't stop heating after reaching the target temp!

## Steps to Reproduce
1. Compile with `g++ -o device main.cpp`
2. Run `./device`
3. Observe the results in the terminal (Second entry)

## Expected Behavior
Upon exceeding target temp by 2 degrees the thermostat should redirect its effort to cooling the room back down and disabling heating.

## Actual Behavior
Upon exceeding the target temp by 2 the thermostat doesn't stop heating the room and begin trying to cool the room. Resulting in temprature continuing to rise

## Environment
- OS: Ubuntu 22.04
- Compiler: g++ 11.4.0

## Possible Solution
Some issue in if else branches relating to target temp?

## Test Case

