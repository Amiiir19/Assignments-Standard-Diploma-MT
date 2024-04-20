/*
 * app.c
 *
 *      Author: amir
 */
#include <stdio.h>
#include <stdlib.h>
#include "app.h"
system_state_t app(car *amircar) {
	//variable to take the user input in the  menu
	char input;

	/**
	 * Here we must identify the car as OFF
	 * As the user didn't turn it on yet
	 */
	amircar->engine = OFF;
	printf("**************************************\n");
	printf("*  Welcome To Vehicle Control Panel  *\n");
	printf("**************************************\n");
	printf(" a. Turn on the vehicle engine       \n");
	printf(" b. Turn off the vehicle engine      \n");
	printf(" c. Quit the system                  \n");
	printf("**************************************\n");
	printf("Please Enter Your Option Here : ");
	//take option from the user
	scanf(" %c", &input);
	/*
	 * Here to avoid bugs  i put the small and the capital option of the letter in cases
	 * after each other without break to allow user to enter both of them
	 */
	switch (input) {
	case 'a':
	case 'A':
		/**
		 * the user chooses to turn on the car so we pass the struct car address
		 * pass it by address to the function that deal with the process of
		 * turning on the car
		 */
		turnOn(amircar);
		break;
	case 'b':
	case 'B':
		/**
		 * Here the User choose to turn off the car but actually the car is off so we
		 * display the menu again by doing nothing and the
		 * fuction will back to main and then  call app()
		 * again which will display the  menu
		 */
		break;
	case 'c':
	case 'C':
		/*
		 * Here the user choose to quit
		 * so we return from the whole app function to the main function which will terminate
		 * and end the program
		 */
		printf("Good Bye\n");
		return System_OFF;
	}
	return System_ON;
}
void turnOn(car *amircar) {
	/**
	 * Here we must identify the car as ON
	 * As the user turn it on by entering this function
	 */
	amircar->engine = ON;
	/**
	 * Another super loop that allow the program to show the menu repeatly after each order
	 * and also there is the option to quit it when the user ask to turn off the car
	 * so we return from the whole turnon function
	 */
	while (1) {
		//variable to take the user input in the turn on menu
		char inputON = 0;
		printf("______________________________________\n\n");
		printf("*           Vehicle ON Menu          *\n");
		printf("______________________________________\n");
		printf("a. Turn off the engine\n");
		printf("b. Set the traffic light color.\n");
		printf("c. Set the room temperature (Temperature Sensor)\n");
#if (WITH_ENGINE_TEMP_CONTROLLER)
		printf("d. Set the engine temperature (Engine Temperature Sensor)\n");
#endif
		printf("______________________________________\n");
		printf("Please Enter Your Option Here : ");
		scanf(" %c", &inputON);
		printf("______________________________________\n");
		/*
		 * Here to avoid bugs  i put the small and the capital option of the letter in cases
		 * after each other without break to allow user to enter both of them
		 */
		switch (inputON) {
		case 'a':
		case 'A':
			/**
			 * the user choose to turn off the car so we will exit from turn on function and
			 * get back to the app function where the motor will turned off and show the main menu
			 */
			return;
		case 'b':
		case 'B':
			/*
			 * User chooses to set the traffic light color so we goes to the SetTrafficLightColor function
			 * which will deals with this operation
			 *  passing to it struct by address
			 */
			SetTrafficLightColor(amircar);
			break;
		case 'c':
		case 'C':
			/*
			 * User chooses to set the room temp so we goes to the SetRoomTemp function
			 * which will deals with this operation
			 *  passing to it struct by address
			 */
			SetRoomTemp(amircar);
			break;
		case 'd':
		case 'D':
			/**
			 * user chooses to set the engine temp , first we check if the macro is enabled or not
			 * if so we goes to the SetEngineTemp function which will deals with this operation
			 * passing to it struct by address
			 */
#if (WITH_ENGINE_TEMP_CONTROLLER)
			SetEngineTemp(amircar);
#endif
			break;
		}
	}
}

void SetTrafficLightColor(car *amircar) {
	//Take the input color from the user
	char input;
	printf("Please Enter the Traffic Light Color (R - O - G) : ");
	scanf(" %c", &input);
	/*
	 * Here to avoid bugs  i put the small and the capital option of the letter in cases
	 * after each other without break to allow user to enter both of them
	 */
	switch (input) {
	case 'R':
	case 'r':
		// according to requirements we access the speed variable and set it by new value
		amircar->speed = 0;
		break;
	case 'G':
	case 'g':
		// according to requirements we access the speed variable and set it by new value
		amircar->speed = 100;
		break;
	case 'O':
	case 'o':
		// according to requirements we access the variables of struct and set it by new values
		amircar->speed = 30;
		amircar->AC = ON;
		amircar->engine_temp_controller = ON;
		amircar->room_temp = amircar->room_temp * (5.0 / 4.0) + 1.0;
#if (WITH_ENGINE_TEMP_CONTROLLER)
		amircar->engine_temp = amircar->engine_temp * (5.0 / 4.0) + 1.0;
#endif
		break;
	}
	// By the end of the function we display the values after modifications
	displayCarState(amircar);
}
void SetRoomTemp(car *amircar) {
	float input;
	printf("Please Enter the Room Temperature : ");
	scanf(" %f", &input);
	//according to requirments  we check conditions and access car struct and modify variables
	if ((input < 10) || (input > 30)) {
		amircar->AC = ON;
		amircar->room_temp = 20;
	} else {
		amircar->AC = OFF;
	}
	// By the end of the function we display the values after modifications
	displayCarState(amircar);

}
void SetEngineTemp(car *amircar) {
	float input;
	printf("Please Enter the Engine Temperature : ");
	scanf(" %f", &input);
	//according to requirements  we check conditions and access car struct and modify variables
	if ((input < 100) || (input > 150)) {
		amircar->engine_temp_controller = ON;
		amircar->engine_temp = 125;
	} else {
		amircar->engine_temp_controller = OFF;
	}
	// By the end of the function we display the values after modifications
	displayCarState(amircar);

}

void displayCarState(const car *amircar) {
	/*
	 * Function used to display the states of the car by print the
	 * variables of the struct car by address
	 */

	printf("______________________________________\n\n");
	printf("    	      Car State     	 	  \n");
	printf("______________________________________\n");
	/**
	 * in condition variables of struct we check by if just to print on or off as string
	 * just for more clear print message
	 */
	if (amircar->engine == ON) {
		printf(" Engine Condition   |        %s  \n", "ON");
	} else {
		printf(" Engine Condition   |        %s  \n", "OFF");
	}
	printf("____________________|_________________\n");
	if (amircar->AC == ON) {
		printf(" AC Condition       |        %s \n", "ON");
	} else {
		printf(" AC Condition       |        %s \n", "OFF");
	}
	printf("____________________|_________________\n");
	printf(" Vehicle speed      |        %d                 \n",
			amircar->speed);
	printf("____________________|_________________\n");
	printf(" Room Temperature   |        %.1f \n", amircar->room_temp);
#if (WITH_ENGINE_TEMP_CONTROLLER)
	printf("____________________|_________________\n");
	printf(" Engine Temperature |        %.1f           \n",
			amircar->engine_temp);
	printf("____________________|_________________\n");
	if (amircar->engine_temp_controller == ON) {
		printf(" Engine Temperature |\n Controller         |         %s \n",
				"ON");
	} else {
		printf(" Engine Temperature |\n Controller         |         %s \n",
				"OFF");
	}
	printf("____________________|_________________\n");
#endif
}

