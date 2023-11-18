#include <iostream>
#include "List.hpp"
#include <string>
#include <cctype>

bool isDigitString(const std::string& st) {
    bool isDigit = !st.empty();
    for (const auto symb : st) {
        if (!std::isdigit(symb)) {
            isDigit = false;
        }
    }
    return isDigit;
}



int main()
{
    List list;
    std::string num;
    size_t count = 0;
    std::cout << "Enter your nums, amount of them should be a multiple of 3 or end: " << std::endl;


    while (std::cin >> num) {
        if (count % 3 == 0 && num == "end") {
           break;
        } else if (count % 3 != 0 && num == "end") {
           std::cout << "amount of them should be a multiple of 3" << std::endl;
        }
        else if (!isDigitString(num)) {
            std::cout << "Enter again" << std::endl;
        } else {
            list.append(std::stod(num));
            ++count;
        }
    }

    list.printList();
    list.addZeroes();
    list.printList();

    return 0;
}
