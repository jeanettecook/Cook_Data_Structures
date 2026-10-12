#include "QueueArray.hpp"

int main(void){
    QueueArray<int, 20> q; //20 element array of ints

    q.enqueue(5);
    q.enqueue(15);
    q.enqueue(25);

    q.print();

    while(!q.empty()){
        q.dequeue() 
    }
    return 0;
    
    
}