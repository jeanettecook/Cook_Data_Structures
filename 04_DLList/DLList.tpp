#include "DLList.hpp"
#include <iostream>

template <typename T>
DLList<T>::DLList() {
    head = new DLLNode<T>; // Sentinal Node
    tail = new DLLNode<T>; // Sentinal Node
    // Connecting head and tail
    head->next = tail;
    tail->prev = head;
    list_size = 0;
}

template <typename T>
DLList<T>::~DLList() {
    clear();
}

template <typename T> 
DLList<T>::DLList(const DLList& other) {
    head = new DLLNode<T>; // Sentinal Node
    tail = new DLLNode<T>; // Sentinal Node
    // Connecting head and tail
    head->next = tail;
    tail->prev = head;
    list_size = 0;
    DLLNode<T>* cur = other.head;
    while (cur) {
        push_back(cur->data);
        cur = cur->next;
    }
}

template <typename T> 
DLList<T>& DLList<T>::operator=(const DLList& other) {
    if (this != &other) {
        clear();
        head = new DLLNode<T>; // Sentinal Node
        tail = new DLLNode<T>; // Sentinal Node
        head->next = tail;
        tail->prev = head;
        list_size = 0;
        DLLNode<T>* cur = other.head;
        while (cur) {
            push_back(cur->data);
            cur = cur->next;
        }
    }
    return *this;
}

template <typename T>
void DLList<T>::push_front(const T& val) {
    head->next = new DLLNode<T>(val, head, head->next);
    head->next->next->prev = head->next;
    list_size++;
}

template <typename T>
void DLList<T>::push_back(const T& val) {
    tail->prev = new DLLNode<T>(val, tail->prev, tail);
    tail->prev->prev->next = tail->prev;
    list_size++;
}

template <typename T>
void DLList<T>::print() const {
    DLLNode<T>* cur = head->next;
    while (cur != tail) {
        std::cout << cur->data;
        cur = cur->next;
    }
    std::cout << std::endl;
}

template <typename T>
unsigned DLList<T>::size() const{
    return list_size;
}

template <typename T>
bool DLList<T>::empty() const {
    return(size() == 0);
}

template <typename T>
void DLList<T>::pop_front(void) {
    if (!empty()) {
        DLLNode<T>* old_front = head->next;
        head->next = old_front->next;
        old_front->next->prev = head;
        delete old_front;
        list_size--;
    }
}

template <typename T>
void DLList<T>::pop_back(void) {
    if (!empty()) {
        DLLNode<T>* old_back = tail->prev;
        tail->prev = old_back->prev;
        old_back->prev->next = tail;
        delete old_back;
        list_size--;
    }
}

template <typename T>
void DLList<T>::clear(void) {
    while(!empty()) {
        pop_front();
    }
}

template <typename T>
T& DLList<T>::at(unsigned index) {
    DLLNode<T>* cur = head->next;
    for (int i = 0; i < index; i++) {
        cur = cur->next;
    }
    return cur->data;
}