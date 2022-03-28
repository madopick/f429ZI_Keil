/*
 * util.h
 *
 *  Created on: Feb 15, 2022
 *      Author: pudja
 */

#ifndef STM32F4XX_HAL_UTIL_UTIL_H_
#define STM32F4XX_HAL_UTIL_UTIL_H_

#include "stm32f4xx_hal.h"

/* Public macros */
#define GPIO_PIN_CNT            (16)

#define GPIO_PIN(__X__)         (1 << (__X__))
#define DELAY_MS(__X__)         (HAL_Delay(__X__))

/* Public function declarations */
HAL_StatusTypeDef UTIL_PinGetNumber(uint8_t *pin_num, uint16_t GPIO_Pin);
HAL_StatusTypeDef UTIL_PinGetIrqNumber(IRQn_Type *IRQn, uint8_t pin_num);
void UTIL_PortEnableClock(GPIO_TypeDef *port);
void UTIL_PortDisableClock(GPIO_TypeDef *port);

#endif /* STM32F4XX_HAL_UTIL_UTIL_H_ */

