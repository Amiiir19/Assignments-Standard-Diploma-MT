/*
 ============================================================================
 Name        : Vehicle_Control_system.c
 Author      : Amir
 Version     :
 Description : Vehicle Control System Project
 ============================================================================
 */
#include "app.h"

int main(void) {
	/**
	 * Here I initialize the car struct with initial values
	 * we can also put it as global but in our code design we pass the struct by address through
	 * the entire code parts so there is no need to make it global
	 * car >> typedef struct  definition in app.h
	 */
	car amircar = { OFF, OFF, OFF, 0, 20, 125 };
	/**
	 * Super Loop that the whole process will take place where the only option to quit it is to
	 * user to enter option c so we return from the whole function not only break the loop and
	 * Terminate the program
	 */
	for (;;) {
		/**
		 *  if app() function of return type enum returns
		 *  off that's mean we need to off the system
		 */
		if (app(&amircar) == System_OFF) {
			return 0;
		}
	}
	return 0;
}
