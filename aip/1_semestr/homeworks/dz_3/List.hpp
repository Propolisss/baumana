#ifndef DZ_3_LIST_HPP
#define DZ_3_LIST_HPP
#include "Node.hpp"

class List
{
public:
    List();
    ~List();
    void AddElement(double);
    void DeleteOdds();
    void PrintList();

private:
    Node* head;
    Node* tail;
};


#endif//DZ_3_LIST_HPP
