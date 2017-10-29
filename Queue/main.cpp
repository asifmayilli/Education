#include <iostream>
#include "Queue.cpp"
#include "QueueArray.cpp"

using namespace std;


int main() {

    /*
    Queue myQueue;
    cout << myQueue.empty() << endl;

    myQueue.display();

    myQueue.enqueue(3);
    myQueue.enqueue(34);
    myQueue.enqueue(7);

    myQueue.display();

    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.display();*/

    QueueArray arrayQueue;
    arrayQueue.enqueue(4);
    arrayQueue.enqueue(7);
    arrayQueue.enqueue(8);
    arrayQueue.enqueue(9);
    arrayQueue.enqueue(1);
    arrayQueue.enqueue(3); // is full
    arrayQueue.display();

    arrayQueue.dequeue();
    arrayQueue.display();

    arrayQueue.dequeue();
    arrayQueue.display();

    arrayQueue.dequeue();
    arrayQueue.display();

    arrayQueue.dequeue();
    arrayQueue.display();
    //arrayQueue.dequeue();
    arrayQueue.display();
    //arrayQueue.dequeue();
    arrayQueue.display();

    arrayQueue.enqueue(7);
    arrayQueue.enqueue(8);
    arrayQueue.enqueue(9);
    arrayQueue.enqueue(4);

    arrayQueue.enqueue(4);

    arrayQueue.display();



    return 0;
}