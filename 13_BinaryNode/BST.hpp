#ifndef BST_HPP
#define BST_HPP

template <typename T>

class BST{

public: 
    BST();
    bool empty();
    

    void insert(const T& val); // need to put data in here
    bool contains(const T& val) const; //need to implemnt 
private: 
BTNode<T>* root; //points to the top




};

#include "BST.tpp"
#endif