// clang-format off
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>

#include <delay.h>
// clang-format on

/**
 * @brief Inicia los componentes GPIO necesarios
 * 
 */
static void gpio_setup(void) {
  rcc_periph_clock_enable(RCC_GPIOC);
  gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);
}

int main(void) {
  // Establece la velocidad del reloj en 72mhz
  rcc_clock_setup_in_hse_8mhz_out_72mhz();

  // Inicia el TIM4 para gestión de los delay
  delay_setup();

  // Inicia GPIO
  gpio_setup();

  // Bucle infinito del programa principal
  while (1) {
    // Cambia el estado del GPIO13
    gpio_toggle(GPIOC, GPIO13);
    // Realiza una pausa de 500ms
    delay_ms(500);
  }
  return 0;
}