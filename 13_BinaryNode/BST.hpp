#ifndef BST_HPP
#define BST_HPP

template <typename T>

class BST{

public: 
    BST();
    bool empty() const;
    

    void insert(const T& val); // need to put data in here
    bool contains(const T& val) const; //need to implemnt 
    const BTNode<T>* search(const T& val);
    //TODO
    const BTNode<T>* search_parent(const T& val);
private: 
BTNode<T>* root; //points to the top

const BTNode<T>* search(const BTNode<T>* node, const T& val);





};

#include "BST.tpp"
#endif