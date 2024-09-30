# XENSIV PAS CO2 Sensor

This repository contains firmware and drivers for interfacing with the XENSIV PAS CO2 sensor using STM32 microcontrollers. The project provides functions for reading CO2 and pressure measurements via I2C.

## Table of Contents
- [Features](#features)
- [Getting Started](#getting-started)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [References](#references)

## Features
- Initialize the XENSIV PAS CO2 sensor
- Read CO2 concentration and atmospheric pressure
- I2C communication interface
- UART communication for data output

## Getting Started
To get started with this project, you will need:
- An STM32 microcontroller
- XENSIV PAS CO2 sensor
- I2C and UART peripherals configured
- Development environment set up for STM32 (e.g., STM32CubeIDE)

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/Isamd4/XENSIV-PAS-CO2-Sensor.git
2. Open the project in your preferred IDE.
3. Build the project and upload it to your STM32 microcontroller.
## Usage
To use the library:

1. Include the header file in your source code:
   ```cpp
   #include "XENSIV_PAS_CO2.h"
2. Create an instance of the XENSIV_PAS_CO2 class:
   ```cpp
   XENSIV_PAS_CO2 co2Sensor(SLAVE_ADDRESS, &huart3, &hi2c1);
3. Initialize the Sensor:
   ```cpp
   co2Sensor.init();
4. Read Measurements:
   ```cpp
   int co2Value = co2Sensor.get_co2_measurement();
   int pressureValue = co2Sensor.get_pressure_measurement();

## Contributing
Contributions are welcome! Please feel free to submit a pull request or open an issue for suggestions.

## References
1. [Programming guide for XENSIVTM PAS CO2](https://www.infineon.com/dgdl/Infineon-programming_guide_PAS_CO2_evaluationkit-ApplicationNotes-v02_00-EN.pdf?fileId=5546d4627600a6bc0176041139e77780)
2. [Register Map Description of the XENSIV PAS CO2](https://www.infineon.com/dgdl/Infineon-Registermap_description_PASCO2_MA2-ApplicationNotes-v02_00-EN.pdf?fileId=5546d4627600a6bc017604238d967785)
3. [Quick-start guide for XENSIVTM PAS CO2 Shield2Go](https://docs.rs-online.com/128c/A700000009317321.pdf)

