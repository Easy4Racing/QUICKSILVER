#pragma once

#include "config.h"
#include <stdint.h>

#ifdef RX_FRSKY
typedef union {
  struct {
    int8_t offset;
    uint8_t idx;
    uint8_t tx_id[2];
    uint8_t hop_data[50];
    uint8_t rx_num;
    uint8_t _pad;
  };
  uint32_t raw[14];
} frsky_bind_data;
#endif

typedef enum {
  RX_PROTOCOL_INVALID,
  RX_PROTOCOL_UNIFIED_SERIAL,
  RX_PROTOCOL_SBUS,
  RX_PROTOCOL_CRSF,
  RX_PROTOCOL_IBUS,
  RX_PROTOCOL_FPORT,
  RX_PROTOCOL_DSMX_2048,
  RX_PROTOCOL_DSM2_1024,
  RX_PROTOCOL_NRF24_BAYANG_TELEMETRY,
  RX_PROTOCOL_BAYANG_PROTOCOL_BLE_BEACON,
  RX_PROTOCOL_BAYANG_PROTOCOL_TELEMETRY_AUTOBIND,
  RX_PROTOCOL_FRSKY,
  RX_PROTOCOL_MAX,
} rx_protocol_t;

typedef enum {
  AUX_CHANNEL_0,
  AUX_CHANNEL_1,
  AUX_CHANNEL_2,
  AUX_CHANNEL_3,
  AUX_CHANNEL_4,
  AUX_CHANNEL_5,
  AUX_CHANNEL_6,
  AUX_CHANNEL_7,
  AUX_CHANNEL_8,
  AUX_CHANNEL_9,
  AUX_CHANNEL_10,
  AUX_CHANNEL_11,
  AUX_CHANNEL_OFF,
  AUX_CHANNEL_ON,
  AUX_CHANNEL_GESTURE,

  AUX_CHANNEL_MAX
} aux_channel_t;

typedef enum {
  AUX_ARMING,
  AUX_IDLE_UP,
  AUX_LEVELMODE,
  AUX_RACEMODE,
  AUX_HORIZON,
  AUX_STICK_BOOST_PROFILE,
  AUX_TRAVEL_CHECK,
  AUX_HIGH_RATES,
  AUX_LEDS_ON,
  AUX_BUZZER_ENABLE,
  AUX_TURTLE,
  AUX_MOTORS_TO_THROTTLE_MODE,
  AUX_RSSI,
  AUX_FPV_ON,

  AUX_FUNCTION_MAX
} aux_function_t;

uint8_t rx_aux_on(aux_function_t function);
uint8_t rx_auxchange(aux_function_t function);

void rx_init(void);
void rx_serial_init(void);

void rx_precalc();
void rx_check(void);

void rx_serial_find_protocol(void);

void rx_serial_process_dsmx(void);
void rx_serial_process_sbus(void);
void rx_serial_process_ibus(void);
void rx_serial_process_fport(void);
void rx_serial_process_crsf(void);

void rx_serial_send_fport_telemetry(void);

float rx_expo(float x, float exp);
float rx_smoothing_hz(rx_protocol_t proto);

void rx_apply_expo(void);

#if defined(RX_DSMX_2048) || defined(RX_DSM2_1024) || defined(RX_UNIFIED_SERIAL)
void rx_spektrum_bind(void);
#endif
void usart_invert(void);