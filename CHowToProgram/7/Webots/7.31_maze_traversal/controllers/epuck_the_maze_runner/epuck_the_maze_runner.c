/*
 * File:          the_maze_runner.c
 * Date:          12/26/2023
 * Description:   e-puck the maze runner
 * Author:        theBitRiddler
 * Modifications:
 */

/*
 * You may need to add include files like <webots/distance_sensor.h> or
 * <webots/motor.h>, etc.
 */
#include <webots/robot.h>
#include <webots/motor.h>
#include <webots/distance_sensor.h>

/*
 * You may want to add macros here.
 */
#define TIME_STEP 64
#define MAX_SPEED 6.28
#define SENSORS 8

/*
 * This is the main program.
 * The arguments of the main function can be specified by the
 * "controllerArgs" field of the Robot node
 */
int main(int argc, char **argv) {
  /* necessary to initialize webots stuff */
  wb_robot_init();

  /*
   * You should declare here WbDeviceTag variables for storing
   * robot devices like this:
   *  WbDeviceTag my_sensor = wb_robot_get_device("my_sensor");
   *  WbDeviceTag my_actuator = wb_robot_get_device("my_actuator");
   */
  int i = 0;
  WbDeviceTag ps[SENSORS] = { 0 };  
  char ps_names[ SENSORS ][ 4 ] = { 
    "ps0", "ps1", "ps2", "ps3",
    "ps4", "ps5", "ps6", "ps7"
   };
  
  for ( i = 5; i < SENSORS; i++ ) {
    ps[ i ] = wb_robot_get_device( ps_names[ i ] );
    wb_distance_sensor_enable( ps[ i ], TIME_STEP );
  } // end for
  
  WbDeviceTag right_motor = wb_robot_get_device( "right wheel motor" );
  WbDeviceTag left_motor = wb_robot_get_device( "left wheel motor" );
  wb_motor_set_position( right_motor, INFINITY );
  wb_motor_set_position( left_motor, INFINITY );
  wb_motor_set_velocity( right_motor, 0.0 );
  wb_motor_set_velocity( left_motor, 0.0 );

  /* main loop
   * Perform simulation steps of TIME_STEP milliseconds
   * and leave the loop when the simulation is over
   */
  while (wb_robot_step(TIME_STEP) != -1) {
    /*
     * Read the sensors :
     * Enter here functions to read sensor data, like:
     *  double val = wb_distance_sensor_get_value(my_sensor);
     */
    double ps_values[SENSORS] = { 0 };
    for ( i = 5; i < SENSORS; i++ ) {
      ps_values[ i ] = wb_distance_sensor_get_value( ps[ i ] );
    } // end for

    /* Process sensor data here */
    bool right = ( ps_values[ 5 ] > 80 && ps_values[ 7 ] > 80 ) ||
                 ( ps_values[ 5 ] < 80 && ps_values[ 7 ] > 80 );
    bool left = ps_values[ 5 ] < 80 && ps_values[ 7 ] < 80;
    bool forward = ps_values[ 5 ] > 80 && ps_values[ 7 ] < 80;
    bool regulator = ps_values[ 6 ] > 80;

    double right_speed = 0.5 * MAX_SPEED;
    double left_speed = 0.5 * MAX_SPEED;  
    
    if ( right ) { // take a hard right
      right_speed = -0.5 * MAX_SPEED;
      left_speed = 0.5 * MAX_SPEED;
    } // end if
    else if ( left ) { // take a left
      right_speed += 0.5 * MAX_SPEED;
      left_speed -= 0.24 * MAX_SPEED;
    } // end else if
    else if ( forward ) {
      right_speed = 0.5 * MAX_SPEED;
      left_speed = 0.5 * MAX_SPEED;
    } // end else if
    
    if ( regulator ) {
      right_speed = -0.5 * MAX_SPEED;
      left_speed = 0.5 * MAX_SPEED;
    } // end if

    /*
     * Enter here functions to send actuator commands, like:
     * wb_motor_set_position(my_actuator, 10.0);
     */
    wb_motor_set_velocity( right_motor, right_speed );
    wb_motor_set_velocity( left_motor, left_speed );
  }; // end while

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}
