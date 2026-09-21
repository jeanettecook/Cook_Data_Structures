#include <iostream>

class Node{
    public: 
    int data;
    Node * next ;
    Node(int d = 0, Node * n = nullptr) : data(d), next(n){
    
    //void printList(head);
    //std::cout<< "Size" << getListSize(head) <<std::endl;
    }
};
void printList(const Node* node);
int getListSize(const Node * node);
Node * reverseList(Node* node);


//TO DO
//printListReverse(const Node * node);
//int getListSize(const Node* node);
//Node * reverseList(Node* node);


int main(void){
    //create linked list
    Node* head = new Node(1);
    head -> next = new Node(2);
    head -> next -> next = new Node (3);
    head -> next -> next -> next = new Node(4);

    std::cout<< "Original List:";
    printList(head);
    std::cout << "Size:" << getListSize(head)<< std::endl;

    head = reverseList(head);
    std::cout<< "Reversed List:";
    printList(head);

    return 0;
}

void printList(const Node* node){
    if (!node){
        std::cout<< "\n";
        return;
    }
    std::cout << node -> data << " ";
    printList(node -> next);

}

int getListSize(const Node* node){
    if(!node){
        return 0;
    }
    return 1 + getListSize(node -> next); //adds head to it every time

//head = reverseList(head); // update the head, then it will print the last node
//printList(head);
}
Node*  reverseList(Node* node){
    if (!node || node != node -> next){
        return node;
    }
    Node* new_head = reverseList(node -> next);
    node -> next -> next = node;
    node -> next = nullptr;

    return new_head;
}