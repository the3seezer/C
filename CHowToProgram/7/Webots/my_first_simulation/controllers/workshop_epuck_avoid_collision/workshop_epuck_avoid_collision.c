/*
theBitRiddler
1/8/2024
9:46 AM
avoid collision
*/
#include <webots/robot.h>
#include <webots/motor.h>
#include <webots/distance_sensor.h>

#define TIME_STEP 64
#define MAX_SPEED 6.28
#define SIZE 8

int main( int argc, char ** argv ) {
  wb_robot_init();
  
  int i = 0;
  WbDeviceTag ds[ SIZE ];
  char ds_names[ SIZE ][ 4 ] = {
    "ps0", "ps1", "ps2", "ps3", "ps4", "ps5", "ps6", "ps7"
  };
  for ( i = 0; i < SIZE; i++ ) {
    ds[ i ] = wb_robot_get_device( ds_names[ i ] );
    wb_distance_sensor_enable( ds[ i ], TIME_STEP );
  } // end for
  
  WbDeviceTag right_motor = wb_robot_get_device( "right wheel motor" );
  WbDeviceTag left_motor = wb_robot_get_device( "left wheel motor" );
  wb_motor_set_position( right_motor, INFINITY );
  wb_motor_set_position( left_motor, INFINITY );
  wb_motor_set_velocity( right_motor, 0 );
  wb_motor_set_velocity( left_motor, 0 );

  while ( wb_robot_step( TIME_STEP ) != -1 ) {
  // Read sensors
  double ds_value[ SIZE ];
  for ( i = 0; i < SIZE; i++ ) {
    ds_value[ i ] = wb_distance_sensor_get_value( ds[ i ] );
  } // end for
  
  // Process behaviour
  double right_speed = 0.5 * MAX_SPEED;
  double left_speed = 0.5 * MAX_SPEED;
  
  bool turn_right = ds_value[ 5 ] > 80 || ds_value[ 6 ] > 80 || ds_value[ 7 ] > 80;
  bool turn_left = ds_value[ 0 ] > 80 || ds_value[ 1 ] > 80 || ds_value[ 2 ] > 80;
  
  if ( turn_right ) {
    right_speed = -0.5 * MAX_SPEED;
    left_speed = 0.5 * MAX_SPEED;
  } // end if
  else if ( turn_left ) {
    right_speed = 0.5 * MAX_SPEED;
    left_speed = -0.5 * MAX_SPEED;
  } // end else if
  
  // Write actuator inputs
  wb_motor_set_velocity( right_motor, right_speed );
  wb_motor_set_velocity( left_motor, left_speed );
  } // end while
  
  wb_robot_cleanup();
  return 0;
} // end main