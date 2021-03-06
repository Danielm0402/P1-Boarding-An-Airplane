#pragma once

#include <stdbool.h>

typedef enum _XAxis {
	Col_a, Col_b, Col_c, Col_d, 
	Col_e, Col_f, Col_g, Col_h, 
	Col_i, Col_j, Col_k, Col_l, 
	Col_m, Col_n, Col_o, Col_p, 
	Col_q, Col_r, Col_s, Col_t,
	Col_u, Col_v, Col_w, Col_x,
	Col_y, Col_z
} XAxis;

typedef enum _BoardingGroup {
	BoardingGroup_Padding = -3,
	BoardingGroup_Walkway = -2,
	BoardingGroup_Door = -1,
	BoardingGroup_Undefined = 0
} BoardingGroup;

typedef struct _Point
{
	XAxis X;
	int Y;
} Point;

typedef struct _Person
{
	int WalkingSpeed;
	Point CurrentPos;
	Point Target;
	bool IsSeated;
	int StartingDoorID;
	char PersonCharacter;
	int LuggageCount;
	bool IsDoneWithSeatInterference;
	int SeatInterferenceDelayCount;
	int CrossDelayCount;
	bool MovedLastTurn;
	Point NextMove;
	int BoardingGroup;
} Person;

typedef struct _ValueStatistic
{
	int Value;
	int Possibility;
} ValueStatistic;

typedef struct _SimulationConfig
{
	int SeatInterferenceDelay;
	int CrossDelay;
	ValueStatistic* LuggageGenerationValues;
	int LuggageGenerationValuesLength;
	ValueStatistic* WalkingspeedGenerationValues;
	int WalkingspeedGenerationValuesLength;
	bool AssignToNearestDoor;
	char** MultipleMaps;
	int MultipleMapsLength;
} SimulationConfig;

typedef struct _Location {
	Point Point;
	int BoardingGroup;
	bool IsTaken;
} Location;

typedef struct _Map {
	Location** Locations;
	int Width;
	int Height;
	Point* Doors;
	int DoorCount;
	int NumberOfSeats;
	int LongestNumber;
} Map;