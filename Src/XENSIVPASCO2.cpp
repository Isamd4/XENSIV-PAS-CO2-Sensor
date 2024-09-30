/*
 * XENSIVPASCO2.cpp
 *
 *  Created on: Sep 28, 2024
 *      Author: Muhammad Isa Hassan
 */

#include "XENSIVPASCO2.h"
#include <string.h>
#include <stdio.h>

/*
 * Constructor for the XENSIV_PAS_CO2 class
 * Initializes the I2C slave address and the UART/I2C handles
 */
XENSIV_PAS_CO2::XENSIV_PAS_CO2(const uint8_t SLAVE_ADDRESS,
		UART_HandleTypeDef *uartHandle, I2C_HandleTypeDef *i2cHandle) :
		SLAVE_ADDRESS(SLAVE_ADDRESS << 1), uartHandle(uartHandle), i2cHandle(
				i2cHandle) {
	char buf[] = "Welcome \r\n";
	HAL_UART_Transmit(this->uartHandle, (uint8_t*) buf, strlen(buf),
			HAL_MAX_DELAY);

	delete buf;
}
/*
 * Initializes the CO2 sensor and its configuration
 * Returns Sensor Status if successful, or -1
 */
int XENSIV_PAS_CO2::init() {
	HAL_StatusTypeDef ret;
	uint8_t register_data = SENS_STS;
	uint8_t data_received;
	uint8_t buf[30];
	ret = write_data(register_data);
	if (ret != HAL_OK) {
		strcpy((char*) buf, "Error Transmitting\r\n");
		HAL_UART_Transmit(this->uartHandle, buf, 30, HAL_MAX_DELAY);
		return -1;
	}
	ret = read_data(data_received);
	if (ret != HAL_OK) {
		strcpy((char*) buf, "Error Transmitting\r\n");
		HAL_UART_Transmit(this->uartHandle, buf, 30, HAL_MAX_DELAY);
		return -1;
	}
	HAL_Delay(1000);
	return data_received;

}

/*
 * Writes data to the CO2 sensor over I2C
 * @param data: The data byte to be sent to the sensor which is usually register address
 * @return HAL_StatusTypeDef: Status of the transmission (HAL_OK or error)
 */
HAL_StatusTypeDef XENSIV_PAS_CO2::write_data(uint8_t &data) {
	HAL_StatusTypeDef ret;
	ret = HAL_I2C_Master_Transmit(this->i2cHandle,
			this->SLAVE_ADDRESS | ((uint8_t) WRITE_ACTIVEATE), &data, 1, 50);
	return ret;
}

 /*
  * Reads data from the CO2 sensor over I2C
  * @param data: Reference to store the received data byte
  * @return HAL_StatusTypeDef: Status of the reception (HAL_OK or error)
 */
HAL_StatusTypeDef XENSIV_PAS_CO2::read_data(uint8_t &data) {
	HAL_StatusTypeDef ret;
	ret = HAL_I2C_Master_Receive(this->i2cHandle,
			this->SLAVE_ADDRESS | ((uint8_t) READ_ACTIVATE), &data, 1, 50);
	return ret;
}

/*
 * Retrieves the pressure measurement from the sensor
 * @return int: The pressure measurement value or -1
 *
 */
int XENSIV_PAS_CO2::get_pressure_measurement() {
	HAL_StatusTypeDef ret;
	uint8_t buf[30];
	uint8_t register_data[2] = { PRES_REF_H, PRES_REF_L };
	uint8_t data[2];
	ret = write_data(register_data[0]);
	if (ret != HAL_OK) {
		strcpy((char*) buf, "Error Transmitting\r\n");
		HAL_UART_Transmit(this->uartHandle, buf, 20, HAL_MAX_DELAY);
		return -1;
	}
	ret = read_data(data[0]);
	if (ret != HAL_OK) {
		strcpy((char*) buf, "Error Reading LOW\r\n");
		HAL_UART_Transmit(this->uartHandle, buf, 20, HAL_MAX_DELAY);
		return -1;
	}
	ret = write_data(register_data[1]);
	if (ret != HAL_OK) {
		strcpy((char*) buf, "Error Transmitting\r\n");
		HAL_UART_Transmit(this->uartHandle, buf, 20, HAL_MAX_DELAY);
		return -1;
	}
	ret = read_data(data[1]);
	if (ret != HAL_OK) {
		strcpy((char*) buf, "Error Reading HIGH\r\n");
		HAL_UART_Transmit(this->uartHandle, buf, 20, HAL_MAX_DELAY);
		return -1;
	}

	return ((data[0] << 8) | data[1]);

}
/*
 * Retrieves the CO2 concentration measurement from the sensor
 * @return int: The CO2 measurement value or -1
 */
int XENSIV_PAS_CO2::get_co2_measurement() {
	HAL_StatusTypeDef ret;
	uint8_t buf[30];
	uint8_t register_data[2] = { CO2PPM_H, CO2PPM_L };
	uint8_t data[2];
	ret = write_data(register_data[0]);
	if (ret != HAL_OK) {
		strcpy((char*) buf, "Error Transmitting\r\n");
		HAL_UART_Transmit(this->uartHandle, buf, 20, HAL_MAX_DELAY);
		return -1;
	}
	ret = read_data(data[0]);
	if (ret != HAL_OK) {
		strcpy((char*) buf, "Error Reading LOW\r\n");
		HAL_UART_Transmit(this->uartHandle, buf, 20, HAL_MAX_DELAY);
		return -1;
	}
	ret = write_data(register_data[1]);
	if (ret != HAL_OK) {
		strcpy((char*) buf, "Error Transmitting\r\n");
		HAL_UART_Transmit(this->uartHandle, buf, 20, HAL_MAX_DELAY);
		return -1;
	}
	ret = read_data(data[1]);
	if (ret != HAL_OK) {
		strcpy((char*) buf, "Error Reading HIGH\r\n");
		HAL_UART_Transmit(this->uartHandle, buf, 20, HAL_MAX_DELAY);
		return -1;
	}

	return ((data[0] << 8) | data[1]);

}
