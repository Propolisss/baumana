#include "Atom.hpp"
#include <vector>
#include <iostream>

int main() {
//  std::vector<Atom> atoms;
//  std::string nameOfMolecula;
//  std::string tempNameOfAtom;
//  int countOfAtom = 0;
//  double massOfMolecula = 0.0;
//
//  while (tempNameOfAtom != "end") {
//    std::cout << "Enter your atom and amount of him or end: ";
//    std::cin >> tempNameOfAtom;
//    if (tempNameOfAtom != "end") {
//      std::cin >> countOfAtom;
//      if (!(countOfAtom <= 0 || Atom::mendeleev.find(tempNameOfAtom) == Atom::mendeleev.end())) {
//        atoms.emplace_back<Atom>(tempNameOfAtom);
//        nameOfMolecula += (countOfAtom > 1) ? tempNameOfAtom + std::to_string(countOfAtom) : tempNameOfAtom;
//        massOfMolecula += Atom::mendeleev.at(tempNameOfAtom) * countOfAtom;
//      } else {
//        std::cout << "Try again. Wrong name or non nalural number" << std::endl;
//      }
//    }
//  }
//
//  std::cout << nameOfMolecula << ' ' << massOfMolecula;


  std::string tempNameOfAtom;
  int countOfAtom = 0;
  Molecule molecule;

  while (tempNameOfAtom != "end") {
    std::cout << "Enter your atom and amount of him or end: ";
    std::cin >> tempNameOfAtom;
    if (tempNameOfAtom != "end") {
      std::cin >> countOfAtom;
      if (countOfAtom >= 1 && Molecule::CheckAtom(tempNameOfAtom)) {
        molecule.AddAtom(tempNameOfAtom, countOfAtom);
      } else {
        std::cout << "Try again. Wrong name or non nalural number" << std::endl;
      }
    }
  }
  molecule.PrintInfo();
  std::cout << molecule.CalcMass() << std::endl;
  return 0;
}