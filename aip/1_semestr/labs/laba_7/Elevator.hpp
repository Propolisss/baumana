#pragma once

class Elevator
{
public:
	Elevator();
	Elevator(const long long int);
	~Elevator();
	
	void SetFloor(const long long int);
	long long int GetFloor();
	void PrintInfo();

private:
	long long int floor;
};