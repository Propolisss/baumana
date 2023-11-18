#include "Node.hpp"

Node::Node(const double num_) : next(nullptr), num(num_) {}

Node::~Node() {
    delete next;
}