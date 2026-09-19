#define QUEUE_ARRAY_HPP
#include "../04_DLList/DLList.hpp"


template <typename T>
class QueueList {
    public:
    QueueList():

    bool empty() const;
    bool full() const;
    void print() const;
    void enqueue(const T&)

    const T& dequeue();

    //TO DO
    const T&  front(); //return the first element in the queue
    void  clear(); // remove all the elements from the queue
    int    size();  //return the size of the queue

    private:
        DLList<T> list;

};


#include "QueueList.tpp"
#endif