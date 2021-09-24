#include <stdio.h>
#include "brick.h"
#include <unistd.h>

#define Sleep( msec ) usleep(( msec ) * 1000 )

#define MOTOR_RIGHT    	OUTA
#define MOTOR_LEFT    	OUTB
#define MOTOR_C    		OUTC
#define MOTOR_D    		OUTD

#define SENSOR_TOUCH	IN1
#define SENSOR_2		IN2
#define SENSOR_3		IN3
#define SENSOR_4		IN4

#define MOTOR_BOTH     	( MOTOR_LEFT | MOTOR_RIGHT )

int max_speed;      
POOL_T touchSensor;

int main( void )
{  
	
	
	touchSensor = sensor_search( LEGO_EV3_TOUCH ); 
	touch_set_mode_touch(touchSensor); 

	tacho_set_speed_sp( MOTOR_BOTH, max_speed * 0.2 ); 
	
	tacho_run_forever(  MOTOR_BOTH );
	Sleep( 1000 );  

	tacho_stop( MOTOR_LEFT );
	Sleep( 2000 ); 
	
	tacho_stop( MOTOR_RIGHT );
	Sleep( 2000 );
	
	tacho_run_forever( MOTOR_BOTH );
	while(!sensor_get_value(0, touchSensor, 0)); //Så länge touch-sensorn inte är intryckt kommer while-loopen köras
	tacho_stop( MOTOR_BOTH );

	brick_uninit();
	printf( "dying...\n" );
    return ( 0 );

}
