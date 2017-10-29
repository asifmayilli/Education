//
// Created by Asif Mayilli on 10/29/17.
//


#include <iostream>

struct node {
    int data;
    node* next;
};

class Queue{
    private:
    node* head;
    node* tail;
    public:
    Queue(){
        head = tail = NULL;
        std::cout << "Queue was created!\n";
    }

    ~Queue(){
        node* temp = head;
        while(temp != NULL){
            node* current = temp->next;
            delete temp;
            temp = current;
        }
        delete temp;
        std::cout << "Queue was deleted! \n";

    }
    void enqueue(int value){

        node* temp = new node();
        temp->data = value;
        temp->next = NULL;

        if(head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    void display(){

        if(head == NULL)
        {
            std::cout<< "Queue is empty!\n";
        }

        node* temp = head;
        while(temp != NULL){
            std::cout<< temp->data << "\t";
            temp = temp->next;
        }
        std::cout << "\n";
    }
    int dequeue(){

        if(head == NULL)
        {
            std::cout << "Queue is empty! You cannot delete!\n";
            exit(1);
        }

        node* temp = head;
        int value = temp->data;
        head = head->next;
        delete temp;

        return value;
    }

    bool empty() {
        if (head == NULL)
        {
            return true;
        }
        return false;
    }

};