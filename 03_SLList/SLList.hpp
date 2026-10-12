#ifndef SLLIST_HPP
#include "SLLNode.hpp"
#include <stdexcept>

class SLList {
public:

    //no- arg constructor
    SLList();

    unsigned size () const; // return true if is empty

    bool empty() const; // print the list

    void push_front(int val); //

    void print(const);

    void push_back(int val);

    void pop_front(void);
    //TO DO
    void pop_back(void);

    void clear(void);


    //TO DO:
    //void push_back(int_val)
    //to do: the copy constructor
    //assignment operator(=)

    SLList& operator (const SLList & othe)

    int& at(unsigned index){
        if (index >= size()){
            throw std::logic_error("at: incorrect index"):

        }
        SLLNode * cur = head;
        for(int i = 0; i < index; i++){
            cur = cur -> next;
        }
    }
 
    //return the value of the node at the index 

    //int.at(0) = 2
    


//erase positiion

//use pop_front

//doubly linked lists

//A DLL can be reversed in both forward and back position 

//sentinel nodes 

//these extra nodes (header node)


private:
    SLLNode* head; 
    SLLNode* tail; //last node in the linked list
    unsigned list_size;



}

void SLList::clear(void){
    while(!empty()){
        pop_front();
    }
}
#endif

=
