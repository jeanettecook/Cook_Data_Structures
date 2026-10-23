#ifndef MIN_HEAP_HPP
#define MIN_HEAP_HPP
#include <vector> 

//store the elements as an array
template <typename T>
class MinHeap{
    public:

    void insert(const T& val);
    void print() const;

    bool empty() const;

    T deleteMin();


private: 
std::vector<T> data;


int getParent(int index) const;
int getLeftChild(int index) const;
int getRightChild(int index) const;

void percolateUp(int index) ;

void percolateDown(int index);

void swap(T& v1, T& v2);
};

#include "MinHeap.tpp"
#endif