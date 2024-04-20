/*
 * app.h
 *
 *      Author: amir
 */

//file guard to avoid duplicated definition
#ifndef APP_H_
#define APP_H_

/**
 * Here a Macro that indicates to use any feature in the code related to the Engine temp controller
 * 1 >> Enable
 * 0 >> Disable
 */

#define WITH_ENGINE_TEMP_CONTROLLER 1

/**
 * Enum of On (1) and off (0) to increase the readability of the code
 */

typedef enum state {

	OFF, ON
} state_t;
//enum for the system_state
typedef enum system_state {
	System_OFF, System_ON
} system_state_t;
/**
 *struct contains all the variables that related to the car system
 *int engine :  1 or  0 indicates the car (on) or (off)
 *int AC     :  1 or  0 indicates the AC (on) or (off)
 *int engine_temp_controller  :  1 or  0 indicates the engine temp controller (on) or (off)
 *int speed  :  indicates the car speed
 *float room_temp:  indicates the room temperature and it is float due to the equation used
 *float engine_temp:  indicates the engine temperature and it is float due to the equation used
 */
typedef struct car {
	int engine;
	int AC;
	int engine_temp_controller;
	int speed;
	float room_temp;
	float engine_temp;
} car;

/*
 * app function takes a pointer to structure of the car and display the main menu that
 * makes the user choose if he wants to turn on or off the car or quit the whole system
 * system_state_t is returns data type which return system is off or on which makes the main
 * loop takes decision whether to terminate the program or call app function again

 * @param amircar  is  a pointer to structure of type car which contains informations about the car speed
 * and condition and temprature of the room and the engine
 */
system_state_t app(car *amircar);

/*
 * turn on function takes a pointer to structure of the car and display the menu that
 * makes the user choose what to do during the car is on
 *
 * @param amircar  is  a pointer to structure of type car which contains informations about the car speed
 * and condition and temprature of the room and the engine
 */

void turnOn(car *amircar);
/*
 * SetTrafficLightColor function takes a pointer to structure of the car and display the menu that
 * makes the user choose which color traffic light is to takes decision about config the options
 * of the car
 *
 * @param amircar  is  a pointer to structure of type car which contains informations about the car speed
 * and condition and temprature of the room and the engine
 */
void SetTrafficLightColor(car *amircar);

/*
 * displayCarState function takes a pointer to structure of the car and display the states
 * of the car by print the variables of the struct car by address
 *
 * @param amircar  is  a pointer to const structure of type car which contains informations about the car speed
 * and condition and temperature of the room and the engine
 * we make it const to avoid modify it by mistake
 */
void displayCarState(const car *amircar);
/*
 * SetRoomTemp function takes a pointer to structure of the car and display the menu that
 * makes the user enter estimated room temperature so it configures the car
 * options and how the system will act to this temperature
 *
 * @param amircar  is  a pointer to structure of type car which contains informations about the car speed
 * and condition and temprature of the room and the engine
 */
void SetRoomTemp(car *amircar);
/*
 * SetEngineTemp function takes a pointer to structure of the car and display the menu that
 * makes the user enter estimated engine temperature so it configures the car
 * options and how the system will act to this temperature
 *
 * @param amircar  is  a pointer to structure of type car which contains informations about the car speed
 * and condition and temprature of the room and the engine
 */
void SetEngineTemp(car *amircar);

#endif /* APP_H_ */
