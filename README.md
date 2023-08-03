# Coffee Art Printer Project

## Overview
The Coffee Art Printer project is a state-of-the-art invention that is designed to enhance your coffee experience by creating beautiful foam art in your cup. The printer's printhead consists of a needle that can extract foam at programmatically defined locations, creating stunning pictures on the foam surface.

## Implementation
The coffee printer consists of three movable axes: a rotating platform, a vector along which the printhead moves, and vertical needle movement. It's controlled by an Android application over USB that includes predefined pictures and basic movement commands.

The entire system is driven by stepper motors and an STM32L431RCT6 microcontroller. It's equipped with two end-stop switches in the form of slot photocouplers and a foam surface sensor. The stepper motors are managed by TMC2209 drivers.

A custom library for managing the StepperMotor was written for the project.

## Project Structure

- Coffee Art Printer Project
    - Android Application
        - Predefined Pictures
        - Basic Movement Commands
    - STM32L431RCT6 Controller
        - StepperMotor Library
        - Movement Commands
    - Mechanical Structure
        - Rotating Platform
        - Printhead Vector Movement
        - Vertical Needle Movement
    - Sensors
        - End-stop switches
        - Foam surface sensor
    - README.md


## Setup and Installation
Detailed instructions on how to setup and install the Coffee Art Printer will be added shortly.

## Contributions
This is an open-source project and we welcome contributions. If you're interested in contributing, please read through our Contribution Guidelines before making a pull request.

## Contact
If you have any questions or suggestions, feel free to email feodosiy2404@gmail.com

**Enjoy your coffee with a touch of art!**