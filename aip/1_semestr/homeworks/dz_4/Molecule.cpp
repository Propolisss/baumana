#include "Molecule.hpp"
#include "Atom.hpp"
#include <utility>
#include <iostream>

void Molecule::AddAtom(const std::string& name_, size_t count) {
  atoms.emplace_back(std::move(std::make_pair(Molecule::Atom(name_), count)));
}

void Molecule::PrintInfo() {
  for (auto& atom : atoms) {
    std::cout << ((atom.second > 1) ? atom.first.GetName() + std::to_string(atom.second) : atom.first.GetName());
  }
  std::cout << std::endl;
}

double Molecule::CalcMass() {
  double mass = 0.0;
  for (auto& atom : atoms) {
    mass += atom.first.GetMass() * atom.second;
  }
  return mass;
}

bool Molecule::CheckAtom(const std::string& name_) {
  return Molecule::Atom::mendeleev.find(name_) != Molecule::Atom::mendeleev.end();
}