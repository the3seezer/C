/*
 * File:          workshop_four_wheels_collision_avoidance.c
 * Date:
 * Description:
 * Author:
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
#define MOTORS 4
#define SENSORS 2

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
  bool collision_avoidance_counter = 0;
  WbDeviceTag wheels[ MOTORS ];
  char* wheels_names[ MOTORS ] = {
    "wheel1", "wheel2", "wheel3", "wheel4"
  };
  WbDeviceTag ds[ SENSORS ];
  char *ds_names[ SENSORS ] = {
    "ds1", "ds2"
  };

  for ( i = 0; i < MOTORS; i++ ) {
    wheels[ i ] = wb_robot_get_device( wheels_names[ i ] );
    wb_motor_set_position( wheels[ i ], INFINITY );
  } // end for
  for ( i = 0; i < SENSORS; i++ ) {
    ds[ i ] = wb_robot_get_device( ds_names[ i ] );
    wb_distance_sensor_enable( ds[ i ], TIME_STEP );
  } // end for

  /* main loop
   * Perform simulation steps of TIME_STEP milliseconds
   * and leave the loop when the simulation is over
   */
  while (wb_robot_step(TIME_STEP) != -1) {
    /*
     * Read the sensors :
     * Enter here functions to read sensor data, like:
     *  double val = wb_distance_sensor_get_value(my_sensor);
     *//* Process sensor data here */
    double right_speed = 0.5 * MAX_SPEED;
    double left_speed = 0.5 * MAX_SPEED;
    double ds_value[ SENSORS ];

    if ( collision_avoidance_counter > 0 ) {
      right_speed = 1;
      left_speed = -1;
      collision_avoidance_counter--;
    } // end if
    else {
      
      for ( i = 0; i < SENSORS; i++ ) {
        ds_value[ i ] = wb_distance_sensor_get_value( ds[ i ] );
      } // end for

      if ( ds_value[ 0 ] < 950 || ds_value[ 1 ] < 950 ) {
        collision_avoidance_counter = 100;
      } // end if

    } // end else
    /*
     * Enter here functions to send actuator commands, like:
     * wb_motor_set_position(my_actuator, 10.0);
     */
    wb_motor_set_velocity( wheels[ 0 ], left_speed );
    wb_motor_set_velocity( wheels[ 1 ], right_speed );
    wb_motor_set_velocity( wheels[ 2 ], left_speed );
    wb_motor_set_velocity( wheels[ 3 ], right_speed );

  };

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}
