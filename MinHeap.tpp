#include "MinHeap.tpp"

template <typename T>
void MinHeap<T>:: swap(const T& v1, const T& v2){
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