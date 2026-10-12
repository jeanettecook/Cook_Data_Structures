#ifndef DLLIST_HPP
#define DLLIST_HPP

#include "DLLNode.hpp"

template <typename T>
class DLList{
    public:
    DLList();
    ~DLList();
    DLList(const DLList& other);
    DLList& operator=(const DLList& other);
    unsigned    size() const; // Return the size of the list
    bool        empty() const; // Return true if list is empty
    void        push_front(const T& val); // Insert the node at the beginning
    void        print() const; // Print the list
    void        push_back(const T& val);
    void        pop_front(void); // Remove the first node from the list 
    void        pop_back(void); // Remove the last node from the list
    void        clear(void);
    T& at(unsigned index); // Return the value of the node at index

    private: 
    DLLNode<T>* head; // First node in the linked list
    DLLNode<T>* tail; // Last node in the linked list
    unsigned list_size; // The nmber of nodes in the linked list
};

#include "DLList.tpp"

#endif