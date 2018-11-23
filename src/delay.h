#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void delay_setup(void);

void delay_us(uint16_t us);
void delay_ms(uint16_t ms);

#ifdef __cplusplus
}
#endif