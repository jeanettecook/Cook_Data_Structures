#include "MinHeap.hpp"
#include <iostream>


template <typename T>
void MinHeap<T>::swap(T& v1, T& v2){
    T temp = v1;
    v1 = v2;
    v2 = temp;
}
template <typename T>
void MinHeap<T>::print() const{
    for (const T& val : data){
        std::cout<< val<< " ";
    }
    std::cout<< '\n';
}

template <typename T>
void MinHeap<T>::insert(const T& val){
    data.push_back(val);            //put it at the back
    int index = data.size() - 1;
    percolateUp(index);
}

//TO DO implement three methods (Return -1 if the index doesn't exist) 
template <typename T>
int MinHeap<T>::getParent(int index) const{
    if (index <= 0){
        return -1;
    }
    return index = (index - 1) / 2; 
}
template <typename T>
int MinHeap<T>::getLeftChild(int index) const{

if (index < 0){
    return -1;
}
return (2 * index) + 1;
}
template <typename T>
int MinHeap<T>::getRightChild(int index) const{
if (index < 0){
    return -1;
}
return (2 * index) + 2;

}

template <typename T>
void MinHeap<T>::percolateUp(int index) {
    if (index < 0 || index >= data.size()){
        std::cout << "percolateUp:: incorrect index\n";
        return;
    }
        while (true){
            int parent_idx = getParent(index);

            if (parent_idx == -1){
                break;
            }
            //compare current value w/ parent value
            if (data[index] < data[parent_idx]){
                swap(data[index], data[parent_idx]);
                index = parent_idx;
            }
            else{
                break;
            }
        }   

    }


template <typename T>
T MinHeap<T>::deleteMin() {
    if (data.empty()){
        throw std::out_of_range("deleteMin: empty heap");
    }
    T res = data[0];
    int last_idx  = data.size() - 1;
    data[0] = data[last_idx];
    data.pop_back();

    percolateDown(0);
}



template <typename T>
    void MinHeap<T>::percolateDown(int index) {
    //start from the root

    while (true){
    //find children of the current node 
    int left = 2 * index + 1;

    if (left > data.size() - 1){
        break;
    }
    int right = 2 * index + 2;
    
    int smallest = left;
    if (right <= data.size() - 1 && data [right]< data[left]){
        smallest = right;
    }
   
    if (data[index] > data[smallest]){
        swap(data[index], data [smallest]);
        index = smallest;
    }
    else{
    break;
        }
    }
 }