#include "drv_gpio.h"

#include "defines.h"

static volatile uint8_t fpv_init_done = 0;

void gpio_init(void) {

// clocks on to all ports
#ifdef F4
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOC | RCC_AHB1Periph_GPIOD, ENABLE);
#endif
#ifdef F0
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA | RCC_AHBPeriph_GPIOB | RCC_AHBENR_GPIOFEN, ENABLE);
#endif

  GPIO_InitTypeDef GPIO_InitStructure;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

#ifdef ENABLE_VREG_PIN
  gpio_pin_init(&GPIO_InitStructure, VREG_PIN_1);
  gpio_pin_set(VREG_PIN_1);
#endif

#if (LED_NUMBER > 0)
  gpio_pin_init(&GPIO_InitStructure, LED1PIN);
#if (LED_NUMBER > 1)
  gpio_pin_init(&GPIO_InitStructure, LED2PIN);
#if (LED_NUMBER > 2)
  gpio_pin_init(&GPIO_InitStructure, LED3PIN);
#if (LED_NUMBER > 3)
  gpio_pin_init(&GPIO_InitStructure, LED4PIN);
#endif
#endif
#endif
#endif

#if (AUX_LED_NUMBER > 0)
  gpio_pin_init(&GPIO_InitStructure, AUX_LED1PIN);
#endif
#if (AUX_LED_NUMBER > 1)
  gpio_pin_init(&GPIO_InitStructure, AUX_LED2PIN);
#endif

#if defined(FPV_ON) && defined(FPV_PORT) && defined(FPV_PIN)
  if (FPV_PORT == GPIOA && (FPV_PIN == GPIO_Pin_13 || FPV_PIN == GPIO_Pin_14)) {
    //skip repurpose of swd pin @boot
  } else {
    GPIO_InitStructure.GPIO_Pin = FPV_PIN;
    GPIO_Init(FPV_PORT, &GPIO_InitStructure);
    GPIO_WriteBit(FPV_PORT, FPV_PIN, Bit_RESET);
    fpv_init_done = 1;
  }
#endif
}

void gpio_pin_init(GPIO_InitTypeDef *init, gpio_pins_t pin) {
  init->GPIO_Pin = gpio_pin_defs[pin].pin;
  GPIO_Init(gpio_pin_defs[pin].port, init);
}

void gpio_pin_set(gpio_pins_t pin) {
  GPIO_WriteBit(gpio_pin_defs[pin].port, gpio_pin_defs[pin].pin, Bit_SET);
}

void gpio_pin_reset(gpio_pins_t pin) {
  GPIO_WriteBit(gpio_pin_defs[pin].port, gpio_pin_defs[pin].pin, Bit_RESET);
}

// init fpv pin separately because it may use SWDAT/SWCLK don't want to enable it right away
int gpio_init_fpv(uint8_t mode) {
#if defined(FPV_ON) && defined(FPV_PORT) && defined(FPV_PIN)
  // only repurpose the pin after rx/tx have bound if it is swd
  // common settings to set ports
  GPIO_InitTypeDef GPIO_InitStructure;
  GPIO_InitStructure.GPIO_Pin = FPV_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  if (mode == 1 && fpv_init_done == 0) {
    // set gpio pin as output no matter what
    GPIO_Init(FPV_PORT, &GPIO_InitStructure);
    return 1;
  }
  if (mode == 1 && fpv_init_done == 1) {
    return 1;
  }
#endif
  return 0;
}

#define GPIO_PIN(port_num, num) MAKE_PIN_DEF(port_num, num),

const volatile gpio_pin_def_t gpio_pin_defs[GPIO_PINS_MAX] = {
    {},
    GPIO_PINS};

#undef GPIO_PIN
