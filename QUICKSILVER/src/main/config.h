

//Universal pids are already loaded for 5" brushless by default.  Adjust pids in pid.c file for your build.

//**********************************************************************************************************************
//***********************************************HARDWARE SELECTION*****************************************************

// *************DEFINE FLIGHT CONTROLLER MOTOR OUTPUT - *****warning*****  GETTING THIS WRONG CAN SMOKE YOUR BOARD :)
//#define BRUSHLESS_TARGET
#define BRUSHED_TARGET

//**********************************************************************************************************************
//***********************************************NEW STUFF TO PLAY WITH*****************************************************

// Select filter cut 25hz for SBUS, 67hz for CRSF, 40hz for DSMX, 20hz for DSM2, 90hz for bayang   Formula is [(1/rx framerate)/2] * 0.9
#define RX_SMOOTHING_HZ 90

//Select (only one) source variable for PID VBAT Compensation
//#define EXACT_VOLTS     //origional method - responds to exact moment to moment sag
//#define FILTERED_VOLTS  // responds to some sag
#define FUELGAUGE_VOLTS // ignores sag

//**********************************************************************************************************************
//***********************************************RATES & EXPO SETTINGS**************************************************

// *************Select your preffered rate calculation format (define only one)
#define SILVERWARE_RATES
//#define BETAFLIGHT_RATES

#ifdef SILVERWARE_RATES
// *************rate in deg/sec
// *************for acro mode
#define MAX_RATE 860.0    //Roll & Pitch axis
#define MAX_RATEYAW 500.0 //Yaw axis (used in acro and leveling modes)

// *************EXPO from 0.00 to 1.00 , 0 = no exp
// *************positive = less sensitive near center
#define ACRO_EXPO_ROLL 0.80
#define ACRO_EXPO_PITCH 0.80
#define ACRO_EXPO_YAW 0.60

#define ANGLE_EXPO_ROLL 0.55
#define ANGLE_EXPO_PITCH 0.0
#define ANGLE_EXPO_YAW 0.55
#endif

#ifdef BETAFLIGHT_RATES
#define BF_RC_RATE_ROLL 1.30
#define BF_RC_RATE_PITCH 1.30
#define BF_RC_RATE_YAW 1.30
#define BF_SUPER_RATE_ROLL 0.70
#define BF_SUPER_RATE_PITCH 0.70
#define BF_SUPER_RATE_YAW 0.70
#define BF_EXPO_ROLL 0.40
#define BF_EXPO_PITCH 0.40
#define BF_EXPO_YAW 0.40
#endif

// *************max angle for level mode
#define LEVEL_MAX_ANGLE 65.0f

// ************* low rates multiplier if rates are assigned to a channel
#define LOW_RATES_MULTI 0.5f

// *************transmitter stick adjustable deadband for roll/pitch/yaw
// *************.01f = 1% of stick range - comment out to disable
#define STICKS_DEADBAND .01f

//**********************************************************************************************************************
//***********************************************RECEIVER SETTINGS******************************************************

// *************Receiver protocol selection									//todo:  add missing radio protocols from bobnova and make them all jive with new rx_init function in drv_rx_serial.c
#define RX_SBUS
//#define RX_CRSF                                           //Requires tbs firmware v2.88 or newer for failsafe to operate properly
//#define RX_IBUS
//#define RX_FPORT
//#define RX_DSMX_2048																				//  Only fport, sbus, ibus, and dsm protocols are working on F4 right now
//#define RX_DSM2_1024
//#define RX_NRF24_BAYANG_TELEMETRY
//#define RX_BAYANG_PROTOCOL_BLE_BEACON
//#define RX_BAYANG_PROTOCOL_TELEMETRY_AUTOBIND

// *************Serial Receiver UART Selection (uncomment all if using spi receiver)																		//todo:  Many missing usart AF setups, So plenty more to do here
//#define UART_1
#define UART_2
//#define UART_3
//#define UART_4
//#define UART_6

// *************Serial Receiver Inversion Selection  (Normally true for SBUS and FPORT)
//#define INVERT_UART

// *************Type Selection For Bayang Protocol Only
#define USE_DEVO
//#define USE_MULTI

//#define RADIO_XN297L
#define RADIO_XN297

//#define SOFTSPI_3WIRE
#define SOFTSPI_4WIRE

// *******************************SWITCH SELECTION*****************************
#define ARMING CHAN_5
#define IDLE_UP CHAN_5
#define LEVELMODE CHAN_OFF
#define RACEMODE CHAN_OFF
#define HORIZON CHAN_OFF
#define PIDPROFILE CHAN_9
#define RATES CHAN_ON
#define LEDS_ON CHAN_OFF

// *************switch for fpv / other, requires fet
// *************comment out to disable
//#define FPV_ON CHAN_ON

// *************enable buzzer functionality
// *************external buzzer requires pin assignment in hardware.h before defining below
// *************change channel assignment from CHAN_OFF to a numbered aux switch if you want switch control
// *************if no channel is assigned but buzzer is set to CHAN_ON - buzzer will activate on LVC and FAILSAFE.
//#define BUZZER_ENABLE CHAN_OFF

// *************RRD/LLD stick gesture aux start up state.
//#define AUX1_START_ON

//**********************************************************************************************************************
//***********************************************VOLTAGE SETTINGS*******************************************************

// ************* This disables all voltage related logic by returning 4.2V/cell at all times.
// ************* (some targets without voltage dividers may have this already set in targets.h)
//#define DISABLE_ADC

// ************* Set your lipo cell count to override auto cell count detect logic
//#define LIPO_CELL_COUNT 1

// ************* Raises pids automatically as battery voltage drops in flight.  **CRITICAL** Ensure voltage is calibrated before use.
#define PID_VOLTAGE_COMPENSATION
#define LEVELMODE_PID_ATTENUATION 0.90f //used to prevent oscillations in angle modes with pid_voltage_compensation enabled due to high pids

// *************compensation for battery voltage vs throttle drop
#define VDROP_FACTOR 0.7
// *************calculate above factor automatically
#define AUTO_VDROP_FACTOR

// *************lower throttle when battery below threshold - forced landing low voltage cutoff
// *************THIS FEATURE WILL BE OFF BY DEFAULT EVEN WHEN DEFINED - USE STICK GESTURE LEFT-LEFT-LEFT TO ACTIVATE THEN DOWN-DOWN-DOWN TO SAVE AS ON
// *************Led light will blink once when LVC forced landing is turned on, blink twice when turned off, and will blink multiple times upon save command
//#define LVC_LOWER_THROTTLE
#define LVC_LOWER_THROTTLE_VOLTAGE 3.30
#define LVC_LOWER_THROTTLE_VOLTAGE_RAW 2.70
#define LVC_LOWER_THROTTLE_KP 3.0

// *************do not start software if battery is too low (below 3.3v)  - only works on 1s lipos
// *************flashes 2 times repeatedly at startup
//#define STOP_LOWBATTERY

// *************voltage/cell to start warning led blinking
#define VBATTLOW 3.3

// *************voltage hysteresis in volts
#define HYST 0.10

// *************automatic voltage telemetry correction/calibration factor - change the values below if voltage telemetry is inaccurate
// *************Corrects for an offset error in the telemetry measurement (same offset across the battery voltage range)
// *************Enter values in total battery volts.  This is factor is used in all voltage related calculations - ensure your transmitter is not mucking with telemetry scale before adjusting
#define ACTUAL_BATTERY_VOLTAGE 4.20
#define REPORTED_TELEMETRY_VOLTAGE 4.20

//**********************************************************************************************************************
//***********************************************FILTER SETTINGS********************************************************

//#define WEAK_FILTERING
//#define STRONG_FILTERING
//#define VERY_STRONG_FILTERING
//#define ALIENWHOOP_ZERO_FILTERING
#define BETA_FILTERING

#ifdef BETA_FILTERING //*** ABOVE 100 ADJUST IN INCRIMENTS OF 20, BELOW 100 ADJUST IN INCRIMENTS OF 10, nothing coded beyond 500hz

//Select Gyro Filter Type *** Select Only One type
//#define KALMAN_GYRO
#define PT1_GYRO

//Select Gyro Filter Cut Frequency
#define GYRO_FILTER_PASS1 HZ_90
#define GYRO_FILTER_PASS2 HZ_120

//Select D Term Filter Cut Frequency *** Select Only one
//#define  DTERM_LPF_2ND_HZ 100
#define DTERM_LPF_1ST_HZ 120

//Select Motor Filter Type  (last resort filtering stage)
//#define MOTOR_FILTER2_ALPHA MFILT1_HZ_90

#endif

//**********************************************************************************************************************
//***********************************************MOTOR OUTPUT SETTINGS**************************************************

// *************brushed motor minimum idle percent / dshot digital idle
#define DIGITAL_IDLE 4.5

// *************invert yaw pid for "PROPS OUT" configuration - This feature is switchable to "PROPS IN" when active with stick gesture DOWN-UP-DOWN, Save selection with DOWN-DOWN-DOWN
#define INVERT_YAW_PID

// *************throttle boost - can intensify small throttle imbalances visible in FPV if factor is set too high
//#define THROTTLE_TRANSIENT_COMPENSATION
//#define THROTTLE_TRANSIENT_COMPENSATION_FACTOR 4.0

// *************torque boost is a highly eperimental feature and can smoke brushless motors fast.  it is a lpf D term on motor outputs that will accelerate the response
// *************of the motors when the command to the motors is changing by increasing or decreasing the voltage thats sent.  It differs
// *************from throttle transient compensation in that it acts on all motor commands - not just throttle changes.  this feature
// *************is very noise sensative so D term specifically has to be lowered and gyro/d filtering may need to be increased.
// *************reccomendation right now is to leave boost at or below 2, drop your p gains a few points, then cut your D in half and
// *************retune it back up to where it feels good.  I'm finding about 60 to 65% of my previous D value seems to work.
//#define TORQUE_BOOST 1.0

// *************pwm frequency for motor control
// *************a higher frequency makes the motors more linear
// *************in Hz
#define PWMFREQ 32000

// *************throttle angle compensation in level mode
//#define AUTO_THROTTLE

// *************BRUSHED TARGET MIXER SETTINGS
// *************MIX_THROTTLE_REDUCTION_PERCENT reduces thrust imbalances by reducing throttle proportionally to the adjustable reduction percent to the limit set by MIX_THROTTLE_REDUCTION_MAX
// *************MIX_THROTTLE_INCREASE_MAX increases the authority of the pid controller at lowest throttle values like airmode when combined with idle up
// *************BRUSHLESS_MIX_SCALING define disables the default brushed mixer and applies the default brushless mixer
//#define MIX_THROTTLE_REDUCTION_PERCENT 10
//#define MIX_THROTTLE_INCREASE_MAX 0.2f
//#define MIX_THROTTLE_REDUCTION_MAX 0.5f
//#define BRUSHLESS_MIX_SCALING

// *************BRUSHLESS TARGET MIXER SETTINGS
// *************AIRMODE_STRENGTH is the amount of authority AIRMODE is given over throttle
// *************Decrease CLIPPING_LIMIT to force clipping in place of mix scaling to
// *************restore lost power on "promblem quads" by allowing some thrust imbalances to pass through the mixer
//	#define AIRMODE_STRENGTH  1.0f
//	#define CLIPPING_LIMIT  1.0f

//**************joelucid's yaw fix
#define YAW_FIX

//**************I-term relax.  Removes roll and pitch bounce back after flips
#define I_TERM_RELAX
//#define RELAX_FACTOR 10
//#define RELAX_FREQUENCY_HZ 20

//**********************************************************************************************************************
//***********************************************ADDITIONAL FEATURES****************************************************

// *************lost quad beeps using motors (30 sec timeout) - pulses motors after timeout period to help find a lost model
//#define MOTOR_BEEPS

// *************enable inverted flight code ( brushless only )
//#define INVERTED_ENABLE
//#define FN_INVERTED CH_OFF //for brushless only

// *************SPECIAL TEST MODE TO CHECK TRANSMITTER STICK THROWS
// *************This define will allow you to check if your radio is reaching 100% throws entering <RIGHT-RIGHT-DOWN> gesture
// ************* will disable throttle and will rapid blink the led when sticks are moved to 100% throws
// *************entering <LEFT-LEFT-DOWN> will return the quad to normal operation.
#define STICK_TRAVEL_CHECK

//#############################################################################################################################
//#############################################################################################################################
// debug / other things
// this should not be usually changed or still need work
//#############################################################################################################################
//#############################################################################################################################

// failsafe time in uS
#define FAILSAFETIME 1000000 // one second

// debug things ( debug struct and other)
#define DEBUG

// disable motors for testing
//#define NOMOTORS

// throttle direct to motors for thrust measure
//#define MOTORS_TO_THROTTLE

//***********************************************************TODO LIST************************************************************

//MAINTAIN THIS LIST (probably the most important thing on this list)

//investigate dynamic airmode strength adjustment as a potential benefit - felt uneasy in early tests on 75mm brushless whoop

//establish a "profiles.h" include behind config where users can save build default configs to make quick setup easier when updating

//dma support in driver for f4 and F0 gyro - interrupt driven gyro sync fired control()

//8k f4 loop support - examine all filtering time constants - mostly done - still need accelerometer filters and ADC filters adjusted

//moar TARGETS TODO stuff is in hardware.h like buzzer pin assignment and rgb led pin assignment

//audit and add all recent updates from NFE_Silverware that are missing

//audit code for any remaining toy tx features and remove

//fix the core of rx channel assignments to lose the stupid bayang labels or trim features

//port of buzzer function has not been investigated for f4

//rgb led port to f4

//OSD Support

// Interject variables into define hell

//USB Support & Passthrough Support for F0 (repurpose swd clk pin as half duplex serial) and F4 (investigate USB detect pin)

//USB Confgurator & Serial protocol for variable configuration

//SETUP WIZARD

//investigate softserial driver - is it working?, what is it being used for?, can we develop it into a useful feature?

//softserial not throwing errors anymore but needs review for proper configuration - i think I mixed up BSRRH and BSRRL

//find other places I mixed up BSRRH and BSRRL like all the i2c drivers

//reorganize control() in control.c to call functions from new files intuitively named for said functions

// BOBNOVA Section -------- BOBNOVA Section -------- BOBNOVA Section -------- BOBNOVA Section -------- BOBNOVA Section

//FPORT Debug Telemetry is in. Add a "You're on this axis" feature? If you're at all familiar with Quicksilver PIDs the D is a dead giveaway for pitchRoll vs yaw

// There were other things on my list that I don't remember now. I'll add them.

// throttle direct to motors for thrust measure as a flight mode							//***************** this needs to maybe go away after osd?  not safe - encourages running props with craft in in hand
//#define MOTORS_TO_THROTTLE_MODE MULTI_CHAN_8

#define DISABLE_FLIP_SEQUENCER //****************need to turn this into crashflip recovery - will require bidirectional esc setting

#define STARTFLIP CHAN_OFF //****************this would be the aux trigger

// *************motor curve to use - select one																//***************This could become something like tpa
// *************the pwm frequency has to be set independently
#define MOTOR_CURVE_NONE

// rxdebug structure																													//**************** Does this even work???
//#define RXDEBUG

// enable motors if pitch / roll controls off center (at zero throttle)				//**************** This needs to get surgically removed
// possible values: 0 / 1
// use in acro build only
#define ENABLESTIX 0
#define ENABLESTIX_TRESHOLD 0.3
#define ENABLESTIX_TIMEOUT 1e6