/*
 ============================================================================
 Name        : Vehicle_Control_system.c
 Author      : Amir
 Version     :
 Description : Vehicle Control System Project
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#define WITH_ENGINE_TEMP_CONTROLLER 1
typedef enum state {
	OFF, ON
} state_t;
typedef struct car {
	int engine;
	int AC;
	int speed;
	float room_temp;
	float engine_temp;
	int engine_temp_controller;

} car;

void turnOn(car *amircar);
void SetTrafficLightColor(car *amircar);
void displayCarState(car *amircar);
void SetRoomTemp(car *amircar);
void SetEngineTemp(car *amircar);

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	char input;
	car amircar = { OFF, OFF, 0, 20, 125, OFF };
	while (1) {
		amircar.engine = OFF;
		printf("**************************************\n");
		printf("*  Welcome To Vehicle Control Panel  *\n");
		printf("**************************************\n");
		printf(" a. Turn on the vehicle engine       \n");
		printf(" b. Turn off the vehicle engine      \n");
		printf(" c. Quit the system                  \n");
		printf("**************************************\n");
		printf("Please Enter Your Option Here : ");
		scanf(" %c", &input);
		switch (input) {
		case 'a':
			turnOn(&amircar);
			break;
		case 'b':
			continue;
		case 'c':
			printf("Good Bye\n");
			return 0;
		}
	}
	return 0;
}
void turnOn(car *amircar) {
	amircar->engine = ON;
	while (1) {
		char inputON = 0;
		printf("--------------------------------------\n");
		printf("*           Vehicle ON Menu          *\n");
		printf("--------------------------------------\n");
		printf("a. Turn off the engine\n");
		printf("b. Set the traffic light color.\n");
		printf("c. Set the room temperature (Temperature Sensor)\n");
#if (WITH_ENGINE_TEMP_CONTROLLER)
		printf("d. Set the engine temperature (Engine Temperature Sensor)\n");
#endif
		printf("--------------------------------------\n");
		printf("Please Enter Your Option Here : ");
		scanf(" %c", &inputON);
		printf("--------------------------------------\n");
		switch (inputON) {
		case 'a':
			return;
		case 'b':
			SetTrafficLightColor(amircar);
			break;
		case 'c':
			SetRoomTemp(amircar);
			break;
		case 'd':
#if (WITH_ENGINE_TEMP_CONTROLLER)
			SetEngineTemp(amircar);
#endif
			break;
		}
	}
}
void SetTrafficLightColor(car *amircar) {
	char input;
	printf("Please Enter the Traffic Light Color (R - O - G) : ");
	scanf(" %c", &input);
	switch (input) {
	case 'R':
		amircar->speed = 0;
		break;
	case 'G':
		amircar->speed = 100;
		break;
	case 'O':
		amircar->speed = 30;
		amircar->AC = ON;
		amircar->engine_temp_controller = ON;
		amircar->room_temp *= ((5 / 4) + 1);
#if (WITH_ENGINE_TEMP_CONTROLLER)
		amircar->engine_temp *= ((5 / 4) + 1);
#endif
		break;
	}
	displayCarState(amircar);
}
void SetRoomTemp(car *amircar) {
	float input;
	printf("Please Enter the Room Temperature : ");
	scanf(" %f", &input);
	if (input < 10 || input > 30) {
		amircar->AC = ON;
		amircar->room_temp = 20;
	} else {
		amircar->AC = OFF;
	}
	displayCarState(amircar);

}
void SetEngineTemp(car *amircar) {
	float input;
	printf("Please Enter the Engine Temperature : ");
	scanf(" %f", &input);
	if ((input < 100) || (input > 150)) {
		amircar->engine_temp_controller = ON;
		amircar->engine_temp = 125;
	} else {
		amircar->engine_temp_controller = OFF;
	}
	displayCarState(amircar);

}
void displayCarState(car *amircar) {
	printf("--------------------------------------\n");
	printf("    	      Car State     	 	  \n");
	printf("--------------------------------------\n");
	if (amircar->engine == ON) {
		printf(" Engine Condition   |        %s  \n", "ON");
	} else {
		printf(" Engine Condition   |        %s  \n", "OFF");
	}
	printf("--------------------|-----------------\n");
	if (amircar->AC == ON) {
		printf(" AC Condition       |        %s \n", "ON");
	} else {
		printf(" AC Condition       |        %s \n", "OFF");
	}
	printf("--------------------|-----------------\n");
	printf(" Vehicle speed      |        %d                 \n",
			amircar->speed);
	printf("--------------------|-----------------\n");
	printf(" Room Temperature   |        %.1f \n", amircar->room_temp);
#if (WITH_ENGINE_TEMP_CONTROLLER)
	printf("--------------------|-----------------\n");
	printf(" Engine Temperature |        %.1f           \n",
			amircar->engine_temp);
	printf("--------------------|-----------------\n");
	if (amircar->engine_temp_controller == ON) {
		printf(" Engine Temperature |\n Controller         |         %s \n",
				"ON");
	} else {
		printf(" Engine Temperature |\n Controller         |         %s \n",
				"OFF");
	}
	printf("--------------------------------------\n");
#endif
}

