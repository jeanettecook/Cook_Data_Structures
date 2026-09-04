#include <iostream>
#include "SLLNode.hpp"
int main(void) {
// Create SLLNodes
SLLNode* n1 = new SLLNode(1);
SLLNode* n2 = new SLLNode(2);
SLLNode* n3 = new SLLNode(3);
SLLNode* n4 = new SLLNode(4);
// Link the nodes
n1->next = n2;
n2->next = n3;
n3->next = n4;
// Print the value of the first node
std::cout << n1->data << std::endl;
// Print the value of the second node
std::cout << n2->data << std::endl;
// or through n1
std::cout << n1->next->data << std::endl;
// Iterate throught the nodes
SLLNode* cur = n1;
while (cur != nullptr) {
std::cout << cur->data << " "; // access the data of the current node
cur = cur->next;
}
return 0;
}


//Node * cur = node;

//while (cur -> next){
//cur = cur -> next}