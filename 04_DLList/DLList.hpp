#ifndef DLLNODE_HPP
#define DLLNODE_HPP

template <typename T> 
class DLLNode {
public:
    DLLNode(const T& d = T(), DLLNOde<T>* p = nullptr, DLLNode<T>* n = nullptr))
        : data(d), prev(p), next(n) {
            
        }

private:
    T data; 
    DLLNode<T>* prev;
    DLLNode<T>* next;
};


#endif