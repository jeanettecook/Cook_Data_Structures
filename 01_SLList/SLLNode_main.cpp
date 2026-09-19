#include <iostream>
#include <SLLNode.hpp>

// make all my nodes

SLLNode * n1 = new SLLNode(1)
SLLNode * n2 = new SLLNode(2)
SLLNode * n3 = new SLLNode(3)
SLLNode * n4 = new SLLNode(4)

//link all of the nodes

n1 -> next = n2;
n2 -> next = n3;
n3 -> next = n4;

std::cout<< n1;
std::cout <<n2;
std::cout<< n3;
std::cout<< n4;

//traverse through the list

SLLNode * cur = n1; 
while (cur!= nullptr){
    std::cout << cur;

}