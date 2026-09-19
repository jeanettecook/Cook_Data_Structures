#include "QueueList.hpp"
#include <iostream>

using namespace std;

int main() {
    QueueList<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.print();

    cout << "Front: " << q.front() << endl;
    cout << "Size: " << q.size() << endl;

    q.dequeue();

    cout << "After dequeue:" << endl;
    q.print();

    return 0;
}