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
int getParent(int index) const;

template <typename T>
int getLeftChild(int index) const;

template <typename T>
int getRightChild(int index) const;