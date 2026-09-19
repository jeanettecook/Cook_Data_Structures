#include <iostream>
#include "StackArray.hpp"

int main(void){

    // 1. create a stack of integers with a max capacity of 100

    StackArray < int, 100> myStack;

    std::cout<< "test empty stack ---\n";
    myStack.print();

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    
    //need to call print again
    std::cout<< "current stack top to bottom\n";
    myStack.pop();
    myStack.pop();
    myStack.print();
    return 0;

    //myStack.top();

}

