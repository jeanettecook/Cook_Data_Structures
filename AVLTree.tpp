#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>

#include "AVLTree.hpp"

// ==================================================
// Constructor and Destructor
// ==================================================

template <typename T>
AVLTree<T>::AVLTree() : root(nullptr) {

}

template <typename T>
AVLTree<T>::~AVLTree() {
    clear(root);
}

template <typename T>
void AVLTree<T>::clear(AVLNode<T>* node) {
    if (!node) {
        return;
    }

    clear(node->left);
    clear(node->right);
    delete node;
}

// ==================================================
// Basic BST Operations
// ==================================================

template <typename T>
bool AVLTree<T>::empty() const {
    return root == nullptr;
}

template <typename T>
bool AVLTree<T>::contains(const T& val) const {
    return search(root, val) != nullptr;
}

template <typename T>
const AVLNode<T>* AVLTree<T>::search(const AVLNode<T>* node, const T& val) const {
    if (!node || node->data == val) {
        return node;
    }

    if (val < node->data) {
        return search(node->left, val);
    }

    return search(node->right, val);
}

template <typename T>
const AVLNode<T>* AVLTree<T>::getMinNode(const AVLNode<T>* node) const {
    if (!node) {
        return nullptr;
    }

    while (node->left) {
        node = node->left;
    }

    return node;
}

// ==================================================
// Traversal
// ==================================================

template <typename T>
void AVLTree<T>::inorder() const {
    inorder(root);
}

template <typename T>
void AVLTree<T>::inorder(const AVLNode<T>* node) const {
    if (!node) {
        return;
    }

    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
}

// ==================================================
// Printing
// ==================================================

template <typename T>
void AVLTree<T>::print() const {
    std::cout << "===============================\n";
    print("", root, false);
    std::cout << "===============================\n";
}

template <typename T>
void AVLTree<T>::print(const std::string& prefix, const AVLNode<T>* node, bool isRight) const {
    if (!node) {
        return;
    }

    std::cout << prefix;

    if (node != root) {
        std::cout << (isRight ? "R--" : "L--");
    }
    else {
        std::cout << "---";
    }

    std::cout << node->data
              << ", " << getBalance(node)
              << std::endl;

    print(prefix + "   ", node->right, true);
    print(prefix + "   ", node->left, false);
}

// ==================================================
// Rotations (Previous Lecture)
// ==================================================

template <typename T>
void AVLTree<T>::rotateRight(AVLNode<T>*& node) {
    if (!node || !node->left) {
        return;
    }

    AVLNode<T>* left_kid = node->left;

    node->left = left_kid->right;
    left_kid->right = node;

    //update the height;
    updateHeight(node);
    updateHeight(left_kid);


    node = left_kid;
}

template <typename T>
void AVLTree<T>::rotateLeft(AVLNode<T>*& node) {
    if (!node || !node->right) {
        return;
    }

    AVLNode<T>* right_kid = node->right;

    node->right = right_kid->left;
    right_kid->left = node;


    //update the heights

    updateHeight(node);
    updateHeight(right_kid);
    node = right_kid;
}

template <typename T>
void AVLTree<T>::rotateLeftRight(AVLNode<T>*& node) {
    if (!node || !node->left || !node->left->right) {
        return;
    }

    rotateLeft(node->left);
    rotateRight(node);
}

template <typename T>
void AVLTree<T>::rotateRightLeft(AVLNode<T>*& node) {
    if (!node || !node->right || !node->right->left) {
        return;
    }

    rotateRight(node->right);
    rotateLeft(node);
}

// ==================================================
// AVL Height Management (TODO)
// ==================================================

template <typename T>
int AVLTree<T>::getHeight(const AVLNode<T>* node) const {
    return (node) ? node -> height : 0; 

    }

template <typename T>
int AVLTree<T>::getBalance(const AVLNode<T>* node) const {

    if (!node){
        return 0;
    }
    return getHeight(node-> left) - getHeight(node -> right);
}

template <typename T>
void AVLTree<T>::updateHeight(AVLNode<T>* node) {
    if(!node){
        return;
    }
    int height_left = getHeight(node -> left);
    int height_right = getHeight(node -> right);
    node -> height = (height_left > height_right) ? height_left +1 : height_right +1 ;
}

// ==================================================
// Automatic Balancing (TODO)
// ==================================================

template <typename T>
void AVLTree<T>::rebalance(AVLNode<T>*& node) {
    // TODO: Restore AVL balance using rotations // double rotations
    if(!node){
        return;
    }
    int bf = getBalance(node);
    //LEFT HEAVY
    if (bf > 1){
        if(getBalance(node -> left) < 0){ // checks if the left side is right heavy
            rotateLeft(node -> left);
        }
        rotateRight(node);
    }
    if (bf < -1){
        if (getBalance(node -> right) > 0){
            rotateRight(node -> right);
        }
        rotateLeft(node);
    }
}

// ==================================================
// Insertion (TODO)
// ==================================================

template <typename T>
void AVLTree<T>::insert(const T& val) {
    // TODO: Call recursive insert
    insert(val, root);
}

template <typename T>
void AVLTree<T>::insert(const T& val, AVLNode<T>*& node) {
if(!node){
    node = new AVLNode<T> (val);
    return;
}
if (val < node -> data){
    insert(val, node -> left);
}
else{
    insert(val, node -> right);
}
//update the height
updateHeight(node);

//update the balance
rebalance(node);
    // TODO: Implement recursive AVL insertion
}

