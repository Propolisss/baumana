#ifndef DZ_4__ATOM_HPP_
#define DZ_4__ATOM_HPP_

#include "Molecule.hpp"
#include <string>
#include <unordered_map>

//class Atom {
class Molecule::Atom {
 public:
  Atom();
  Atom(const std::string&);
  void PrintInfo();
  std::string GetName();
  double GetMass();
  const static std::unordered_map<std::string, double> mendeleev;

 private:
  std::string name;
  double mass;
};

#endif //DZ_4__ATOM_HPP_
