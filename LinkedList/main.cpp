#include <iostream>
#include "LinkedList.cpp"
using namespace std;

int main() {
    //LinkedList* myList = new LinkedList();

    LinkedList myList;

    cout << myList.getLength() << endl;
    myList.createNode(6);
    myList.createNode(3);
    myList.createNode(4);


    //cout << myList.getLength() << endl;
    myList.insertStart(1);
    myList.insertStart(2);
    myList.insertStart(7);
    //myList.display();
    myList.insertPosition(8,3);
    //myList.display();
    //myList.deleteFirst();
    //myList.display();
    //myList.deleteLast();
    //myList.display();
    //myList.deletePosition(3);
    myList.display();
    myList.reverse();
    //cout<<myList.getLength()<<endl;


    //delete myList;
    return 0;
}