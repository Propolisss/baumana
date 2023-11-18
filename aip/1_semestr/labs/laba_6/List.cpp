#include "List.hpp"
#include <string>
#include <iostream>


List::List() : head(nullptr), tail(nullptr) {}

List::~List() {
	delete head;
}

void List::SetList() {
	std::string tempStr;
	if (head != nullptr) {
		delete head;
	}
	head = new Node();
	std::cout << "Enter your string, length should be even: ";
	std::getline(std::cin, tempStr);
	while (tempStr.length() & 1 || tempStr.length() == 0) {
		std::getline(std::cin, tempStr);
		if (tempStr.length() & 1 || tempStr.length() == 0) {
			std::cout << "Wrong string, try again: ";
		}
	}
	Node* currElem = head;

	for (size_t i = 0; i < tempStr.length(); ++i) {
		currElem->symb = tempStr[i];
		currElem->next = new Node('\0', nullptr, currElem);
		if (i == 0) {
			currElem->prev = nullptr;
		}
		if (i == tempStr.length() - 1) {
			delete currElem->next;
			currElem->next = nullptr;
		}
		tail = currElem;
		currElem = currElem->next;
	}
	std::cout << std::endl;
}



bool List::RemoveElement() {
	std::cout << "Enter your char, that will be removed"
	<< "(if you enter a string the first symbol will be deleted) : ";
	char symbToRemove = '\0';
	std::cin >> symbToRemove;
	bool isRemoved = false;
	Node* currElem = head;
	Node* toDelete;
	while (currElem) {
		if (currElem->symb == symbToRemove) {
			isRemoved = true;
			toDelete = currElem;
			if (currElem->prev != nullptr) {
				currElem->prev->next = currElem->next;
			}
			if (currElem->next != nullptr) {
				currElem->next->prev = currElem->prev;
			}
			if (currElem == head) {
				head = currElem->next;
			}
			if (currElem == tail) {
				tail = currElem->prev;
			}
			currElem = currElem->next;
			toDelete->next = nullptr;
			delete toDelete;
		}
		else {
			currElem = currElem->next;
		}
	}

	if (isRemoved) {
		std::cout << "Successfully removed " << symbToRemove << std::endl << std::endl;
	}
	else {
		std::cout << "Your symbol isn't in your string" << std::endl << std::endl;
	}
	return isRemoved;
}

void List::PrintList() {
	Node* currElem = head;
	if (currElem == nullptr) {
		std::cout << "Your string is empty" << std::endl << std::endl;
	}
	else {
		std::cout << "Your string: ";
		while (currElem) {
			std::cout << currElem->symb;
			currElem = currElem->next;
		}
		std::cout << std::endl << std::endl;
	}
}


void List::EqualsHalf() {
	Node* left = head;
	Node* right = tail;
	bool isEqual = true;
	while (left->next != right && isEqual) {
		if (left->symb != right->symb) {
			isEqual = false;
		}
		left = left->next;
		right = right->prev;
	}
	if (isEqual) {
		std::cout << "Your string is a palindrome" << std::endl << std::endl;
	}
	else {
		std::cout << "Your string is not a palindrome" << std::endl << std::endl;
	}
}
