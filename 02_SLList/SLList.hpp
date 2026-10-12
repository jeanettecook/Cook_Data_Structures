#ifndef SLLIST_HPP
#include "SLLNode.hpp"

class SLList {
public:

    //no- arg constructo
    SLList();

    unsigned size () const;
    bool empty() const;
    void push_fron(int_val);
    void print(list);



private:
    SLLNode* head; 
    unsigned list_size;



}
#endif