//create BST, insert nodes, check contain method
#include <iostream>
#include <string>
#include "BST.tpp"


using namespace std;

int main() {
    BST<std::string> tree;

    tree.insert("hello");
    tree.insert("apple");
    tree.insert("zoo");
    tree.insert("carrot");

cout<< "Has apple" << tree.contains("apple") << endl;
cout<< "Has cat" << tree.contains("cat")<< endl;

auto node = tree.search("zoo");
if(node)
return 0;
}