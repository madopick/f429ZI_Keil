/*
 * data.h
 *
 *  Created on: Mar 23, 2022
 *      Author: pudja
 */

#ifndef SRC_MODULES_DATA_H_
#define SRC_MODULES_DATA_H_

#include <stdint.h>

#define RX_LEN 30
#define TX_LEN 16

extern const uint8_t u8_curvefitCompare[TX_LEN][RX_LEN];
extern const int16_t s16_reconstructed[TX_LEN][RX_LEN];
extern const float f32_curvefitLineRef[TX_LEN][RX_LEN];

uint64_t u64Func_GetBitmap(const uint8_t *u8p_curfitComp, uint8_t u8_len);
void vFunc_ConvertS16toFloat(const int16_t *s16p_src, float *f32p_dst, uint8_t u8_len);

#endif /* SRC_MODULES_DATA_H_ */
