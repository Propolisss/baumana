#include "Node.hpp"

Node::Node(long long int_, double fract_) : fract(fract_), integer(int_), next(nullptr) {}

Node::~Node() {
    integer = 0;
    fract = 0.0;
    delete next;
}