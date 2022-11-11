#include <stdio.h>
#include "brick.h"
#include <unistd.h> 

#define Sleep( msec ) usleep((msec)* 1000)

#define MOTOR_RIGHT        OUTA
#define MOTOR_LEFT         OUTB
#define MOTOR_BOOK         OUTC

#define SENSOR_TOUCH       IN1
#define SENSOR_USONAR      IN2
#define SENSOR_GYRO        IN3
#define SENSOR_COLOUR      IN4  

#define MOTOR_BOTH     ( MOTOR_LEFT | MOTOR_RIGHT )

int motor_speed
POOL_T touchSensor
POOL_T usonarSensor
POOL_T gyroSensor
POOL_T colourSensor

int main(void)

if (!brick_init()) return( 1 );
Sleep( 2000 );

touchSensor = sensor_search( LEGO_EV3_TOUCH );
touch_set_mode_touch( touchSensor );

usonarSensor = sensor_search( LEGO_EV3_US );