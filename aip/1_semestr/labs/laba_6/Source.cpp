#include <iostream>
#include "List.hpp"

int main()
{
	List str;
	bool isWantContinue = true;
	bool isSetted = false;
	bool isRemoved = false;
	while (isWantContinue) {
		char ans = '\0';
		std::cout << "What do you want to do?" << std::endl
		<< "1) Enter string" << std::endl
		<< "2) Remove symbol" << std::endl
		<< "3) Print string" << std::endl
		<< "4) Check for palindrome" << std::endl
		<< "5) End" << std::endl << std::endl;
		std::cin >> ans;
        switch (ans)
		{
		case '1': {
			str.SetList();
			isSetted = true;
            isRemoved = false;
			break;
		}
		case '2': {
			if (!isSetted) {
				std::cout << "Your string is not setted. Set your string first" << std::endl << std::endl;
			}
			else {
				isRemoved = str.RemoveElement();
			}
			break;
		}
		case '3': {
			str.PrintList();
			break;
		}
		case '4': {
			if (!isSetted) {
				std::cout << "Your string is not setted. Set your string first" << std::endl << std::endl;
			}
			else if (isRemoved) {
                std::cout << "Can not check for palindrome, "
                          << "because can check only not removed strings. (check your task)"
                          << std::endl << std::endl;
            }
            else {
                str.EqualsHalf();
            }
			break;
		}
		case '5': {
			isWantContinue = false;
			break;
		}
		default:
			std::cout << "Wrong command. Try again" << std::endl << std::endl;
			break;
		}
	}

	return 0;
}
