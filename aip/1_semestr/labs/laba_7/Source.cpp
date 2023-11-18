#include "Elevator.hpp"
#include <iostream>
#include <string>

bool isDigit(const std::string& tempStr) {
    bool isAllDigit = false;
    if (!tempStr.empty() && std::isdigit(tempStr[0]) || tempStr[0] == '-') {
        isAllDigit = tempStr.length() > 1 || std::isdigit(tempStr[0]);
        for (size_t i = 1; i < tempStr.size(); ++i) {
            if (!std::isdigit(tempStr[i])) {
                isAllDigit = false;
            }
        }
    }

	return isAllDigit;
}

int main()
{
	bool isBreak = false;
	char userChoice = '\0';
	bool isCreatedElevator = false;
	Elevator elevator;
	while (!isBreak) {
		std::cout << "Choose command:" << std::endl
		<< "1) Create new elevator" << std::endl
		<< "2) Set floor for your elevator" << std::endl
		<< "3) Print info about your elevator" << std::endl
		<< "4) End" << std::endl << std::endl;
		std::cin >> userChoice;

		switch (userChoice)
		{
		case '1': {
			std::string ans;
			std::cout << "Enter your floor for elevator: ";
			std::cin >> ans;
			while (!isDigit(ans)) {
				std::cout << "Wrong characters. Only digits. Enter again: ";
				std::cin >> ans;
			}
			std::cout << std::endl;
			elevator.SetFloor(std::stoi(ans));
			isCreatedElevator = true;
			break;
		}
		case '2': {
			if (!isCreatedElevator) {
				std::cout << "Create your elevator first." << std::endl << std::endl;
			}
			else {
				std::string ans;
				std::cout << "Enter your floor for elevator: ";
				std::cin >> ans;
				while (!isDigit(ans)) {
					std::cout << "Wrong characters. Only digits. Enter again: ";
					std::cin >> ans;
				}
				elevator.SetFloor(std::stoi(ans));
			}
			std::cout << std::endl;
			break;
		}
		case '3': {
			if (isCreatedElevator) {
				elevator.PrintInfo();
			}
			else {
				std::cout << "Create your elevator first." << std::endl << std::endl;
			}
			break;
		}
		case '4': {
			isBreak = true;
			break;
		}
		default:
			std::cout << "Wrong command. Try again" << std::endl << std::endl;
			break;
		}
	}
	return 0;
}
