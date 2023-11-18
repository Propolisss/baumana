#include "Node.h"

Node::Node() : symb('\0'), next(nullptr), prev(nullptr) {}

Node::Node(char symb_, Node* next_, Node* prev_) :
	symb(symb_), next(next_), prev(prev_) {}

Node::~Node() {
	symb = '\0';
	prev = nullptr;
	delete next;
}
