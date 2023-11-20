#ifndef DZ_3_NODE_HPP
#define DZ_3_NODE_HPP

class Node
{
public:
    Node(long long int int_, double fract_);
    ~Node();
    friend class List;

private:
    double fract;
    long long int integer;
    Node* next;
};


#endif//DZ_3_NODE_HPP
