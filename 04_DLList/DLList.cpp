##include "DLList.hpp"

template <typename T>
DLList<T>::DLList() {
    head = new DLNode<T>; // Sentinal Node
    tail = new DLNode<T>; // Sentinal Node
    // Connecting head and tail
    head->next = tail;
    tail->prev = head;
    list_size = 0;
}

template <typename T>
void DLList<T>::push_front(const T& val) {
    head->next = new DLLNode<T>(val, head, head->next);
    head->next->next->prev - head->next;
    list_size++;
}

// todo make pring and text 