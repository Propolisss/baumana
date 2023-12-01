#ifndef DZ_4__MOLECULE_HPP_
#define DZ_4__MOLECULE_HPP_

#include <vector>
#include <string>

class Molecule {
 public:
  void AddAtom(const std::string&, size_t);
  void PrintInfo();
  double CalcMass();
  static bool CheckAtom(const std::string&);

 private:
  class Atom;
  std::vector<std::pair<Atom, size_t>> atoms;
};

#endif //DZ_4__MOLECULE_HPP_
