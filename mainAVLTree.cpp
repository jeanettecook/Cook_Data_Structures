#include "AVLTree.hpp"

int main(void){
    AVLTree<int> tree;
    
    for(int i = 0; i < 10; i++){
        tree.insert(i);
    }
    tree.print();
    return 0;
}