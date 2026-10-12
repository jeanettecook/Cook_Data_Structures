#include "SLList.hpp"

SLList :: SLList(): head(nullptr), list_size(0){


}

unsigned SLList::size() const{
    return list_size;

}

bool SLList::empty() const{
    return (size == 0);
}

void SLList::push_front(int_val) {
    SLLNode* new_node = new SLLNode(val);
    new_node -> next = head;
    head = new_node;

    list_size++;

}

void SLList:print() const{
    std::cout<< '{';

    SLLNode* cur = head;

    while(cur) {
        std::cout << cur -> data;
        if (cur -> next) { //if not the last node
            std::cout << "->"
        }
        cur = cur -> next;
    }
    std::cout << "}";
}

void SLList::push_back(int val){
    //push back adds new items to the end of the list
    SLLnode* cur = head;
    if (head == nullptr){ // looking for if the list 
        SLLNode * new_node = new SLLNode(val);
        head = new_node;
        list_size++;
        return;

    }

    while (cur -> next != nullptr){
        cur = cur -> next;
    }
    SLLNode* new_node = new SLLNode(val);
    cur -> next = new_node;
    list_size ++;
}