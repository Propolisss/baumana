#include "List.hpp"
#include <iostream>

List::List() : head(nullptr), tail(nullptr) {}

List::~List() {
    delete head;
}

void List::append(const double elem) {
    if (tail == nullptr) {
        tail = new Node(elem);
        head = tail;
    } else {
        tail->next = new Node(elem);
        tail = tail->next;
    }
}

void List::printList() {
    Node* currElem = head;

    while (currElem) {
        std::cout << currElem->num << ' ';
        currElem = currElem->next;
    }
    std::cout << std::endl;
}

void List::addZeroes() {
    size_t count = 0;
    Node* currElem = head;
    Node* prev;

    while (currElem) {
        ++count;
        if (count % 3 == 0) {
            prev->next = new Node(0);
            prev->next->next = currElem;
        }
        prev = currElem;
        currElem = currElem->next;
    }
}
