#ifndef RK_3_NODE_HPP
#define RK_3_NODE_HPP


class Node
{
public:
    Node(const double num_);
    ~Node();
    friend class List;
private:
    double num;
    Node* next;
};


#endif//RK_3_NODE_HPP
