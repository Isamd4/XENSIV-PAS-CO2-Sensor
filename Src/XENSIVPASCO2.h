/*
 * XENSIVPASCO2.h
 *
 *  Created on: Sep 28, 2024
 *      Author: Muhammad Isa Hassan
 */

#ifndef SRC_XENSIVPASCO2_H_
#define SRC_XENSIVPASCO2_H_
#define PROD_ID        0x00
#define SENS_STS       0x01
#define MEAS_RATE_H    0x02
#define MEAS_RATE_L    0x03
#define MEAS_CFG       0x04
#define CO2PPM_H       0x05
#define CO2PPM_L       0x06
#define MEAS_STS       0x07
#define INT_CFG        0x08
#define ALARM_TH_H     0x09
#define ALARM_TH_L     0x0A
#define PRES_REF_H     0x0B
#define PRES_REF_L     0x0C
#define CALIB_REF_H    0x0D
#define CALIB_REF_L    0x0E
#define SCRATCH_PAD    0x0F
#define SENS_RST       0x10

#define READ_ACTIVATE 0x01
#define WRITE_ACTIVEATE 0x00

#ifdef __cplusplus
extern "C" {
#endif
#include "stm32f4xx_hal.h"   // Adjust this based on your specific STM32 series
#include "stm32f4xx_hal_i2c.h"
#include "stm32f4xx_hal_uart.h"
#include "stm32f4xx_hal_def.h"
#ifdef __cplusplus
}
#endif
class XENSIV_PAS_CO2 {

private:
	const uint8_t SLAVE_ADDRESS;
	I2C_HandleTypeDef *i2cHandle;    // I2C Handle
	UART_HandleTypeDef *uartHandle;// UART Handle
public:
	XENSIV_PAS_CO2(const uint8_t SLAVE_ADDRESS,UART_HandleTypeDef* uartHandle,I2C_HandleTypeDef *i2cHandle);
	int init();
	HAL_StatusTypeDef write_data(uint8_t& data);
	HAL_StatusTypeDef read_data(uint8_t& data);
	int get_co2_measurement();
	int get_pressure_measurement();

};

#endif /* SRC_XENSIVPASCO2_H_ */

