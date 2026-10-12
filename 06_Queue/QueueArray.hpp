#ifndef QUEUE_ARRAY_HPP
#define QUEUE_ARRAY_HPP


template <typename T, int size =100>
class QueueArray {
public:
    QueueArray():

    bool empty() const;
    bool full()  const;
    void print() const;
    void enqueue(const T& val);
    const T& dequeue();

private: 
    T data [size];
    int front_idx, back_idx;
    int queue_size;
    //TO DO
    const T&  front (); //return the first element in the queue
    void  clear (); // remove all the elements from the queue
    int    size();  //return the size of the queue

};

#include "QueueArray.tpp"
#endif