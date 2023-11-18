#ifndef RK_3_LIST_HPP
#define RK_3_LIST_HPP
#include "Node.hpp"

class List
{
public:
    List();
    ~List();
    void append(const double elem);
    void printList();
    void addZeroes();

private:
    Node* head;
    Node* tail;
};


#endif//RK_3_LIST_HPP
