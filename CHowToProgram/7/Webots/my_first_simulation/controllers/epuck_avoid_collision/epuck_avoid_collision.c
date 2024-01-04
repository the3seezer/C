/* 
  theBitRiddler
  12/24/2023
  12:27 PM
  Avoiding collisions
*/
#include <webots/motor.h>
#include <webots/distance_sensor.h>
#include <webots/robot.h>

// define macros
#define MAX_SPEED 6.28 
#define TIME_STEP 64
#define SENSORS 8

int main( int argc, char ** argv ) {
  // start webots API
  wb_robot_init();
  
  // get devices
  // internal declaration
  int i = 0;
  WbDeviceTag ps[SENSORS];
  char ps_names[SENSORS][4] = {
    "ps0", "ps1", "ps2", "ps3", "ps4", "ps5", "ps6", "ps7"
  };
  
  // initilize distance sensors and enable them
  for ( i = 0; i < SENSORS; i++ ) {
    ps[i] = wb_robot_get_device( ps_names[i] );
    wb_distance_sensor_enable( ps[i], TIME_STEP );
  } // end for
  
  // initilise other devices
  WbDeviceTag right_motor = wb_robot_get_device( "right wheel motor" );
  WbDeviceTag left_motor = wb_robot_get_device( "left wheel motor" );
  wb_motor_set_position( right_motor, INFINITY );
  wb_motor_set_position( left_motor, INFINITY );
  wb_motor_set_velocity( right_motor, 0.0 );
  wb_motor_set_velocity( left_motor, 0.0 );
  
  // simulation step
  while ( wb_robot_step( TIME_STEP ) != -1 ) {
    // read sensors
    double ps_values[SENSORS] = { 0 };
    
    for ( i = 0; i < SENSORS; i++ ) {
      ps_values[i] = wb_distance_sensor_get_value( ps[i] );
    } // end for
    
    // process behaviour
    bool right_obstacle = ps_values[0] > 80.0 || ps_values[1] > 80.0 || ps_values[2] > 80.0;
    bool left_obstacle = ps_values[5] > 80.0 || ps_values[6] > 80.0 || ps_values[7] > 80.0;
    
    double right_speed = 0.5 * MAX_SPEED;
    double left_speed = 0.5 * MAX_SPEED;
    
    if ( right_obstacle ) {
      right_speed = 0.5 * MAX_SPEED;
      left_speed = -0.5 * MAX_SPEED;
    } // end if
    else if ( left_obstacle ) {
      right_speed = -0.5 * MAX_SPEED;
      left_speed = 0.5 * MAX_SPEED;
    } // end else if
    
    // write actuators' inputs
    wb_motor_set_velocity( right_motor, right_speed );
    wb_motor_set_velocity( left_motor, left_speed );  
    
  } // end while
  
  // cleanup robot resources
  wb_robot_cleanup();
  return 0;
} /* end main */