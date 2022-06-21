#include "config.h"
#include "config_helper.h"

#define CrazyBee_F4

// PORTS
#define SPI_PORTS   \
  SPI1_PA5PA6PA7    \
  SPI2_PB13PB14PB15 \
  SPI3_PB3PB4PB5

#define USART_PORTS \
  USART1_PA10PA9    \
  USART2_PA3PA2

// LEDS
#define LED_NUMBER 1
#define LED1PIN PIN_C13
#define LED1_INVERT
#define BUZZER_PIN PIN_C15

//#define FPV_PIN LL_GPIO_PIN_13
//#define FPV_PORT GPIOA

// GYRO
#define GYRO_SPI_PORT SPI_PORT1
#define GYRO_NSS PIN_A4
#define GYRO_INT PIN_A1

// RADIO
#define USE_SX128X
#define USE_SX128X_BUSY_EXTI
#define SX12XX_SPI_PORT SPI_PORT3
#define SX12XX_NSS_PIN PIN_A15
#define SX12XX_DIO0_PIN PIN_C14
#define SX12XX_BUSY_PIN PIN_A13
#define SX12XX_RESET_PIN PIN_A8

#ifdef SERIAL_RX
#define RX_USART USART_PORT2
#endif

// OSD
#define ENABLE_OSD
#define MAX7456_SPI_PORT SPI_PORT2
#define MAX7456_NSS PIN_B12

// VOLTAGE DIVIDER
#define VBAT_PIN PIN_B0
#define VBAT_DIVIDER_R1 10000
#define VBAT_DIVIDER_R2 1000

#define IBAT_PIN PIN_B1

// MOTOR PINS
#define MOTOR_PIN0 MOTOR_PIN_PB7
#define MOTOR_PIN1 MOTOR_PIN_PB8
#define MOTOR_PIN2 MOTOR_PIN_PB10
#define MOTOR_PIN3 MOTOR_PIN_PB6