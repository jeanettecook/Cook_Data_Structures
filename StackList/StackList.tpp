#include "StackList.hpp"
#include <stdexcept>
#include <iostream>

//constructor
template <typename T>
StackList<T>::StackList() {
    top_node = nullptr;
}

//destructor
template <typename T>
StackList<T>::~StackList() {
    while(!empty){
        pop();
    }
}

template <typename T>
void        StackList<T>::push(const T& val) 

            //make the new node with the value
            SLLNode * newNode = new SLLNode(val);

            newNode -> next = head;
            //what does head become?

            head = newNode; 

            list_size++;
                
            }
}


template <typename T>
bool        StackList<T>::empty() const {
]           return(size()== 0);
            }
}

template <typename T>
void        StackList<T>::print() const {
            SLLNode* cur = head;

            while(cur){
                std::cout << cur -> data;
                if (cur -> next){
                    std::cout << "->";
                }
                cur = cur -> next;
            }
std::cout << "}";
}

template <typename T>
T           StackList<T>::pop() {
            if (head == null){
                return;           
            }
            list_size --;
}

template <typename T>
const T&    StackList<T>::top() const {
    if (head == nullptr){
        throw std::out_of_range("Stack is empty!")
    }
}
    