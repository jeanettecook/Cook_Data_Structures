#ifndef BST_HPP
#define BST_HPP

template <typename T>

class BST{

public: 
    BST();
    bool empty() const;
    

    void insert(const T& val); // need to put data in here
    bool contains(const T& val) const; //need to implemnt 
    void remove(const T& val); 


    const BTNode<T>* search(const T& val);
    //TODO
    const BTNode<T>* search_parent(const T& val);
    
    void preorder() const;
    void print() const {print("", root, false);}
    
private: 
BTNode<T>* root; //points to the top

const BTNode<T>* search(const BTNode<T>* node, const T& val);

const BTNode<T> * preorder(const BTNode<T>* node) const;

 void print(const std::string& prefix, const BTNode<T>* node, bool isRight) const;

    // remove helpers
void deleteLeaf(BTNode<T>* node, BTNode<T>* parent);
void deleteNodeWithOneChild(BTNode<T>* node, BTNode<T>* parent);
void deleteNodeWithTwoChildren(BTNode<T>* node);
int height(const BTNode<T>* node) const;
int getBalance(const BTNode<T>* node) const;


};

#include "BST.tpp"
#endif