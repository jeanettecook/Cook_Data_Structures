#include "QueueArray.hpp"
#include <iostream>
#include <stdexcept>

template <typename T, int size> 
QueueArray<T, size>::QueueArray() {
    front_idx = back_idx = queue_size = 0;
}


template <typename T, int size >
bool      QueueArray<T, size>::empty() const{
    return queue_size == 0;
}


template <typename T, int size>
bool       QueueArray<T, size>::full() const{
   return queue_size == size;
}

template <typename T, int size >
void       QueueArray<T, size::print() const {
    std::cout<< "[";
    int i = front_inx;
    while (i != back_idx){
        std::cout << data [i] << "";
        i = (i + 1 ) % size; // go to the next element
    }
    std::cout << "]\n"
}

template <typename T, int size = 100 >{
void      QueueArray<T, size:: enqueue(const T& val){
    if(!full()){
        data[back_idx] = val;
        back_idx = (back_idx + 1) % size;
        queue_size++;
    }
}
template <typename T, int size = 100 >
const T& QueueArray<T, size::dequeue(){
    if (empty()){
        throw std::out_of_range("dequeue:Empty queue");
    
    }
    int old_front = front_idx;
    front_idx = (front_idx + 1) % size;
    queue_size --;
    return data[old_front];
    }
}

template <typename T, int size>
const T& QueueArray<T, size>::front() {
    return data[front_idx];
}

template <typename T, int size>
const T& QueueArray<T, size> :: front() {
    return data [front_idx];
}

template <typename T, int size> 
void QueueArray<T, size> :: clear(){ 
    while(!empty()) {
        dequeue();
    }
}
template <typenmae T, int size> 
int QueueArray<T, size>::size(){
    return queue_size;
}
}