#include "QueueList.hpp"

template <typename T>
bool QueueList<T>::empty() const {
    return list.empty(); 
}

template <typename T> 
bool QueueList<T>::full() const {
    return false;
}

template<typename T>
bool QueueList<T>::print() const{
    list.print(); // from my DLL 
}
template<typename T>
void QueueList<T>::enqueue(const T& val){
    list.push_back(val);
}

template<typename T>
const T& QueueList<T>::dequeue(){
    const T& QueueList::front()
    list.pop_front();
    return value; // could become a dangling reference
}

template <typename T>
int QueueList<T>::size(){ 
    return list.size();
}


