#include "List.hpp"
#include <iostream>

List::List() : head(nullptr), tail(nullptr) {}
List::~List() {
    delete head;
}

void List::AddElement(double num) {
    if (tail == nullptr) {
        tail = new Node(static_cast<long long int>(num), num - static_cast<long long int>(num));
        head = tail;
    } else {
        tail->next = new Node(static_cast<long long int>(num), num - static_cast<long long int>(num));
        tail = tail->next;
    }
}


void List::PrintList() {
    Node* currELem = head;

    while (currELem) {
        std::cout << currELem->integer << " + " << currELem->fract << " | ";
        currELem = currELem->next;
    }
    std::cout << std::endl;
}

void List::DeleteOdds() {
    Node* currElem = head;
    Node* prev = currElem;
    size_t count = 0;

    while (currElem) {
        ++count;
        if (count == 1) {
            currElem = currElem->next;
            prev->next = nullptr;
            delete prev;
            prev = currElem;
            head = currElem;
        } else if (count & 1) {
            prev->next = currElem->next;
            currElem->next = nullptr;
            delete currElem;
            currElem = prev->next;
        } else {
            prev = currElem;
            currElem = currElem->next;
        }
    }
}