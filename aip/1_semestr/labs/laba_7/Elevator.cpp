#include "Elevator.hpp"
#include <iostream>

Elevator::Elevator() : floor(0) {}
Elevator::Elevator(const long long floor_) : floor(floor_) {}
Elevator::~Elevator() { floor = 0; }
void Elevator::SetFloor(const long long floor_) {  floor = floor_; }
long long int Elevator::GetFloor() { return floor; }
void Elevator::PrintInfo() {
	std::cout << "Your elevator on " << floor << " floor" << std::endl << std::endl;
}