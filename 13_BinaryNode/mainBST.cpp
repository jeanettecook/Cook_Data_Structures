//create BST, insert nodes, check contain method
#include <iostream>
#include <string>
#include "BST.tpp"


using namespace std;

int main() {
    BST<int> tree;

    cout<< "Empty tree contains 10?"<<  tree.contains(10)<< endl;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);

cout<< "Contains 50?" << tree.contains(50) << endl;
cout<< "Contains 20?" << tree.contains(20) << endl;
cout<< "Contains 40?" << tree.contains(40) << endl;

cout<< "Contains 99?" << tree.contains(99)<< endl;
cout<< "Contains 35?"<< tree.contains(35) << endl;


auto node = tree.search("zoo");
if(node)
return 0;
}