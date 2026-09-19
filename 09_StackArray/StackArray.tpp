 #include "StackArray.hpp"
 #include <iostream>
 #include <stdexcept>

 template <typename T, int capacity> 
 StackArray <T, capacity>::StackArray(): top_idx(-1){

 }
 
template <typename T, int capacity> 
void    StackArray <T, capacity>::push(const T& val){
    if(full()){
        throw std::out_of_range("push: Full Stack");
    }
    else {
        data [++top_idx] = val; //top idx +1 is the size
    }

 }

 template <typename T, int capacity> 
 T        StackArray<T, capacity>::pop (){ 

    if (empty()){
        throw std::out_of_range("pop: Empty Stack");
    }
    else {
        return data [top_idx--];
    }
}
template <typename T, int capacity> 
bool        StackArray<T, capacity>::full () const{ 
    return top_idx  == capacity  - 1;
}


template <typename T, int capacity> 
bool    StackArray<T, capacity>:: empty() const { 
        return top_idx == -1;
}

template <typename T, int capacity>
const T&   StackArray<T, capacity> :: top () const{
    if (empty()){
        throw std::out_of_range("top :Empty Stack");
}
else {
    return data[top_idx];
    }
}

template <typename T, int capacity>
void     StackArray<T, capacity> :: print() const{
    if (empty()){
        std::cout << "list is empty";
        return;
    }
    for (int i = top_idx; i>= 0; --i){
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}