#pragma once

#include "Node.h"

class List
{
public:
	List();
	~List();

	void SetList();
	bool RemoveElement();
	void EqualsHalf();
	void PrintList();

private:
	Node* head;
	Node* tail;
};
