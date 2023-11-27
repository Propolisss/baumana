#include <cstdio>
#include <iostream>
#include <string>

#include "List.hpp"

int main() {

//  double temp = 0.0;
//  List list;
//  size_t n = 0;
//  std::cout << "Enter amount of your nums: ";
//  std::cin >> n;
//
//  for (size_t i = 0; i < n; ++i) {
//    std::cin >> temp;
//    list.AddElement(temp);
//  }
//  std::cout << "List with odds element: ";
//  list.PrintList();
//  std::cout << std::endl;
//  std::cout << "List without odds element: ";
//  list.DeleteOdds();
//  list.PrintList();

    FILE *toRead;
    FILE *toWrite;
    toRead = fopen("..//F.txt", "r");
    toWrite = fopen("..//G.txt", "w");
    std::string temp;
    char symb = ' ';

    while (symb = fgetc(toRead), symb != EOF) {
        if (symb == ' ' && !temp.empty()) {
            if (temp.length() > 3) {
                for (size_t i = 0; i < temp.length(); ++i) {
                    fputc(temp[i], toWrite);
                }
                fputc(' ', toWrite);
            }
            temp.clear();
        } else if (std::isalpha(symb)) {
            temp += symb;
        }
    }

    if (temp.length() > 3) {
        for (size_t i = 0; i < temp.length(); ++i) {
            fputc(temp[i], toWrite);
        }
    }
    fclose(toRead);
    fclose(toWrite);
  return 0;
}
