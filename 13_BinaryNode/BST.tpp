#ifndef BST_TPP
#define BST_TPP

#include "BTNode.hpp"
#include "BST.hpp"


template <typename T>
BST<T>::BST() : root(nullptr){

}

template <typename T>
bool BST<T>::empty() const{
    return root == nullptr; //root will be equal to nullptr
}


template <typename T>
void BST<T>::insert(const T& val) {
    if(empty()){
        root = new BTNode<T>(val);
        return;
    } 

    BTNode<T>* cur = root;
    BTNode<T>* parent = root; 
    

    while(cur){
        parent= cur;

        if (val < cur-> data){
            cur = cur-> left;
        }
        else{
            cur = cur -> right;
        }
    }

    if(val < parent -> data){
        parent -> left = new BTNode<T>(val);
    }
    else {
        parent -> right = new BTNode<T>(val);
    }

}

template <typename T>
bool BST<T>::contains(const T& val) const{

    BTNode<T> * cur = root; // start by making the current point to the root

while (cur){
    if(val == cur -> data){ // if you found the current data, then it is true
        return true;
    }
    else if(val < cur -> data){// val < cur then go left
    cur = cur -> left;
    }
    else{
        cur = cur -> right; // else go right
    }
}
return false;
}

template <typename T>
const BTNode<T>* BST<T>::search(const BTNode<T>* node, const T& val){
    //Base case: fell off the tree, or found it

    if (!node || node -> data == val){
        return node;

    }
    if(val < node-> data){ 
        return search(node -> left, val); // go left
    }
    else{
        return search (node -> right, val);
    }
}
template <typename T>
const BTNode<T>* BST<T>::search(const T& val){
    return search(root,val);
}

template <typename T>
const BTNode<T>* BST<T>::search_parent(const T& val){
   if (root == nullptr){
    return nullptr;
   }

const BTNode<T>* parent = nullptr;
const BTNode<T>*  current = root;

while(current !=nullptr){
    if(val == current -> value){
         return parent;
        }

    parent = current; //needs to remember this node before moving down

    if (val < current -> data){ // then search the tree
    current = current -> left;
    } else{
    current = current -> right;
    }
}
return parent;
}
#endif

