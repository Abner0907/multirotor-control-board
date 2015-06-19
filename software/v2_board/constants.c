#include "constants.h"
#include "packets.h"

ADDRESST ADDRESS;
TELEMETRIEST TELEMETRIES;
ONOFFT ONOFF;
CONTROLLERST CONTROLLERS;
LANDINGT LANDING;
COMMANDST COMMANDS;
unsigned char GET_STATUS;

void constInit(){
	adr64Setter(ADDRESS.COORDINATOR,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00);
	adr64Setter(ADDRESS.KC1,0x00,0x13,0xA2,0x00,0x40,0xB5,0x99,0xB9);
	adr64Setter(ADDRESS.K1,0x00,0x13,0xA2,0x00,0x40,0xB5,0x99,0xBF);
	adr64Setter(ADDRESS.K2,0x00,0x13,0xA2,0x00,0x40,0xB5,0x99,0xBD);
	adr64Setter(ADDRESS.K3,0x00,0x13,0xA2,0x00,0x40,0xB5,0x99,0xB8);
	adr64Setter(ADDRESS.BROADCAST,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF);
	ADDRESS.UNKNOWN16[0] = 0xFF;
	ADDRESS.UNKNOWN16[1] = 0xFE;

	TELEMETRIES.ALTITUDE_ESTIMATED = 0x00;
	TELEMETRIES.ALTITUDE = 0x01;
	TELEMETRIES.ELEVATOR_SPEED = 0x02;
	TELEMETRIES.AILERON_SPEED = 0x03;
	TELEMETRIES.ELEVATOR_SPEED_ESTIMATED=0x04;
	TELEMETRIES.AILERON_SPEED_ESTIMATED=0x05;
	TELEMETRIES.ELEVATOR_POSITION=0x06;
	TELEMETRIES.AILERON_POSITION=0x07;
	TELEMETRIES.ALTITUDE_CONTROLLER_OUTPUT=0x08;
	TELEMETRIES.ALTITUDE_SPEED=0x09;
	TELEMETRIES.AILERON_CONTROLLER_OUTPUT=0x0A;
	TELEMETRIES.ELEVATOR_CONTROLLER_OUTPUT=0x0B;
	TELEMETRIES.ALTITUDE_SETPOINT=0x0C;
	TELEMETRIES.ELEVATOR_POS_SETPOINT=0x0D;
	TELEMETRIES.AILERON_POS_SETPOINT=0x0E;
	TELEMETRIES.ELEVATOR_ACC=0x0F;
	TELEMETRIES.AILERON_ACC=0x10;
	TELEMETRIES.VALID_GUMSTIX=0x11;
	TELEMETRIES.OUTPUT_THROTTLE=0x12;
	TELEMETRIES.OUTPUT_ELEVATOR=0x13;
	TELEMETRIES.OUTPUT_AILERON=0x14;
	TELEMETRIES.OUTPUT_RUDDER=0x15;
	TELEMETRIES.BLOB_ELEVATOR=0x16;
	TELEMETRIES.BLOB_AILERON=0x17;
	TELEMETRIES.BLOB_ALTITUDE=0x18;
	TELEMETRIES.PITCH_ANGLE=0x19;
	TELEMETRIES.ROLL_ANGLE=0x1A;
	TELEMETRIES.ELEVATOR_SHIFT=0x1B;
	TELEMETRIES.AILERON_SHIFT=0x1C;
	TELEMETRIES.ELEVATOR_ACC_INPUT=0x1D;
	TELEMETRIES.ELEVATOR_ACC_ERROR=0x1E;
	TELEMETRIES.AILERON_ACC_INPUT=0x1F;
	TELEMETRIES.AILERON_ACC_ERROR=0x20;	
	
	
	ONOFF.OFF=0x00;
	ONOFF.ON=0x01;
	
	CONTROLLERS.OFF=0x01;
	CONTROLLERS.ALTITUDE=0x02;
	CONTROLLERS.MPC=0x03;
	
	LANDING.ON_GROUND=0x00;
	LANDING.LANDING=0x01;
	LANDING.STABILIZATION=0x02;
	LANDING.TAKE_OFF=0x03;
	LANDING.FLIGHT=0x04;
	
	COMMANDS.TELEMETRY_COORDINATOR=0x01;
	COMMANDS.LANDING=0x02;
	COMMANDS.CONTROLLERS=0x03;
	COMMANDS.TRAJECTORY_POINTS=0x04;
	COMMANDS.POSITION_SLAVE_SET=0x05;
	COMMANDS.TIME=0x06;
	COMMANDS.POSITION_SET=0x07;
	
	GET_STATUS=0xFF;
	
	//telemetryToCoordinatorArr[TELEMETRIES.ELEVATOR_SHIFT]=1;	
	//telemetryToCoordinatorArr[TELEMETRIES.AILERON_SHIFT]=1;	
}