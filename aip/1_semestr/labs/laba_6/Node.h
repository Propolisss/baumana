#pragma once

class Node {
public:
	friend class List;
	Node();
	Node(char symb_, Node* next_, Node* prev_);
	~Node();

private:
	char symb;
	Node* next;
	Node* prev;
};
