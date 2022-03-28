/*
 * util.c
 *
 *  Created on: Feb 15, 2022
 *      Author: pudja
 */
#include "./util.h"

/**
 * @brief Get GPIO pin number index
 * @param pin_num Pointer to destination pin buffer
 * @param GPIO_Pin The GPIO pin
 * @return HAL Status
 */
HAL_StatusTypeDef UTIL_PinGetNumber(uint8_t *pin_num, uint16_t GPIO_Pin)
{
  uint8_t i;

  /* Find the pin number */
  for (i = 0; i < GPIO_PIN_CNT; i++) {
    if (GPIO_Pin >> i == 0x01) {
      *pin_num = i;
      return (HAL_OK);
    }
  }

  return (HAL_ERROR);
}

/**
 * @brief Get related IRQ number based on GPIO pin
 * @param IRQn Pointer to destination IRQ buffer
 * @param pin_num The GPIO pin number
 * @return The IRQ number
 */
HAL_StatusTypeDef UTIL_PinGetIrqNumber(IRQn_Type *IRQn, uint8_t pin_num)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Select appropriate EXTI pin IRQ number */
  if (pin_num >= 10 && pin_num <= 15)
    *IRQn = EXTI15_10_IRQn;
  else if (pin_num >= 5 && pin_num <= 9)
    *IRQn = EXTI9_5_IRQn;
  else if (pin_num == 4)
    *IRQn = EXTI4_IRQn;
  else if (pin_num == 3)
    *IRQn = EXTI3_IRQn;
  else if (pin_num == 2)
    *IRQn = EXTI2_IRQn;
  else if (pin_num == 1)
    *IRQn = EXTI1_IRQn;
  else if (pin_num == 0)
    *IRQn = EXTI0_IRQn;
  else
    status = HAL_ERROR;

  return (status);
}

/**
 * @brief Enable GPIO clock
 * @param port Port to be enabled
 */
void UTIL_PortEnableClock(GPIO_TypeDef *port)
{
  assert_param(IS_GPIO_ALL_INSTANCE(port));

  /* Enable appropriate GPIO clock */
  if (port == GPIOH)
    __HAL_RCC_GPIOH_CLK_ENABLE();
  else if (port == GPIOG)
    __HAL_RCC_GPIOG_CLK_ENABLE();
  else if (port == GPIOF)
    __HAL_RCC_GPIOF_CLK_ENABLE();
  else if (port == GPIOE)
    __HAL_RCC_GPIOE_CLK_ENABLE();
  else if (port == GPIOD)
    __HAL_RCC_GPIOD_CLK_ENABLE();
  else if (port == GPIOC)
    __HAL_RCC_GPIOC_CLK_ENABLE();
  else if (port == GPIOB)
    __HAL_RCC_GPIOB_CLK_ENABLE();
  else if (port == GPIOA)
    __HAL_RCC_GPIOA_CLK_ENABLE();
}

/**
 * @brief Disable GPIO clock
 * @param port Port to be disabled
 */
void UTIL_PortDisableClock(GPIO_TypeDef *port)
{
  assert_param(IS_GPIO_ALL_INSTANCE(port));

  /* Disable appropriate GPIO clock */
  if (port == GPIOH)
    __HAL_RCC_GPIOH_CLK_DISABLE();
  else if (port == GPIOG)
    __HAL_RCC_GPIOG_CLK_DISABLE();
  else if (port == GPIOF)
    __HAL_RCC_GPIOF_CLK_DISABLE();
  else if (port == GPIOE)
    __HAL_RCC_GPIOE_CLK_DISABLE();
  else if (port == GPIOD)
    __HAL_RCC_GPIOD_CLK_DISABLE();
  else if (port == GPIOC)
    __HAL_RCC_GPIOC_CLK_DISABLE();
  else if (port == GPIOB)
    __HAL_RCC_GPIOB_CLK_DISABLE();
  else if (port == GPIOA)
    __HAL_RCC_GPIOA_CLK_DISABLE();
}

