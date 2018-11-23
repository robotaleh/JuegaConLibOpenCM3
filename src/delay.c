// clang-format off
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/timer.h>
#include <stdint.h>

#include "delay.h"
// clang-format on

void delay_setup(void) {
  rcc_periph_clock_enable(RCC_TIM4);
  timer_set_prescaler(TIM4, rcc_apb1_frequency / 1e6 - 1);
  timer_set_period(TIM4, 0xffff);
  timer_one_shot_mode(TIM4);
}

void delay_us(uint16_t us) {
  TIM_ARR(TIM4) = us;
  TIM_EGR(TIM4) = TIM_EGR_UG;
  TIM_CR1(TIM4) |= TIM_CR1_CEN;
  while (TIM_CR1(TIM4) & TIM_CR1_CEN) {
  };
}

void delay_ms(uint16_t ms) {
  for (uint16_t i = 0; i < ms; i++) {
    delay_us(1000);
  }
}
