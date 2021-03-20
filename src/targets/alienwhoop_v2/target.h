#include "config.h"
#include "config_helper.h"

#define F4
#define F405
#define Alienwhoop_V2

//PORTS
#define SPI_PORTS   \
  SPI1_PA5PA6PA7    \
  SPI2_PB13PB14PB15 \
  SPI3_PB3PB4PB5

#define USART_PORTS \
  USART2_PA3PA2     \
  USART3_PC11PC10

//LEDS
#define LED_NUMBER 2
#define LED1PIN PIN_C12
#define LED2PIN PIN_D2
#define LED2_INVERT
#define BUZZER_PIN GPIO_Pin_2
#define BUZZER_PIN_PORT GPIOA
#define BUZZER_INVERT
#define FPV_PIN GPIO_Pin_13
#define FPV_PORT GPIOA

//GYRO
#define MPU6XXX_SPI_PORT SPI_PORT1
#define MPU6XXX_NSS PIN_A4
#define MPU6XXX_INT PIN_C4
#define USE_DUMMY_I2C
#define GYRO_ID_1 0x70
#define GYRO_ID_2 0x73
#define GYRO_ID_3 0x71
#define GYRO_ID_4 0x72
#define SENSOR_ROTATE_90_CW

#define USE_M25P16
#define M25P16_SPI_PORT SPI_PORT3
#define M25P16_NSS_PIN PIN_A15

//RADIO
#ifdef SERIAL_RX
#define RX_USART USART_PORT2
#define SOFTSPI_NONE
#endif

#ifndef SOFTSPI_NONE
#define RADIO_CHECK
#define SPI_MISO_PIN GPIO_Pin_3
#define SPI_MISO_PORT GPIOA
#define SPI_MOSI_PIN GPIO_Pin_2
#define SPI_MOSI_PORT GPIOA
#define SPI_CLK_PIN GPIO_Pin_11
#define SPI_CLK_PORT GPIOC
#define SPI_SS_PIN GPIO_Pin_10
#define SPI_SS_PORT GPIOC
#endif

//VOLTAGE DIVIDER
#define DISABLE_ADC

// MOTOR PINS
#define MOTOR_PIN0 MOTOR_PIN_PC7
#define MOTOR_PIN1 MOTOR_PIN_PC6
#define MOTOR_PIN2 MOTOR_PIN_PC9
#define MOTOR_PIN3 MOTOR_PIN_PC8
