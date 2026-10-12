//create BST, insert nodes, check contain method
#include <iostream>
#include <string>
#include "BST.tpp"


using namespace std;

void check(BST<int>& tree, int val, const std::string& expected){
    const BTNode<int>* p = tree.search_parent(val);
    std::cout<< "parent of " << val << ": " ;
    if (p == nullptr){
        std::cout << "none";
    }
    else{
        std::cout << p -> data;
    }
    std::cout << "    (expected" << expected << ")\n";
}

int main(){
    BST<int> tree;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v: values){
        tree.insert(v);
    }
    check(tree, 50, "none");
    check(tree, 30, "50");
    check(tree, 40, "30");
    check(tree, 80, "70");
    check(tree, 45, "40");
    

BST<int> emptyTree;
check(emptyTree, 10, "none");

return 0;
}



//int main() {
    //BST<std::string> tree;

    //tree.insert("hello");
    //tree.insert("apple");
   // tree.insert("zoo");
    //tree.insert("carrot");

//cout<< "Has apple" << tree.contains("apple") << endl;
//cout<< "Has cat" << tree.contains("cat")<< endl;

//auto node = tree.search("zoo");
//if(node)
//return 0;
//}