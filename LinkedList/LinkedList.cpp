#include <iostream>
#import "LinkedList.h"

class LinkedList {
    private:
        node* tail;
        node* head;
        int length=0;
    public:
        LinkedList(){
            head = NULL;
            tail = NULL;
            std::cout << " new list created!\n";
        }

       int getLength(){
           return length;
       }

       //inserts element to tail of List
       void createNode(int value){
           node* temp = new node;
           temp->data = value;

           temp->next = NULL;
           if(head==NULL){
               head = temp;
               tail = temp;
               temp = NULL;
           } else{
               tail->next=temp;
               tail=temp;
           }
           length++;
       }

       void display() {
           node* temp = new node;
           temp = head;

           while(temp != NULL)
           {
               std::cout << temp->data << " \t ";
               temp = temp->next;
           }
           std::cout << "\n";
       }

       void insertStart(int value){
           node* temp = new node;
           temp->data = value;
           temp->next = head;
           head = temp;
           length++;
       }

       void insertPosition(int value, int position) {
           node* prev;
           node* ptr;
           node* temp = new node;

           if(position > length || position <= 0)
           {
               std::cout << "Out of bounds! \n";
               exit(1);
           }

           prev = NULL;
           ptr = head;
           int curr = 1;
           while(curr != position)
           {
               prev = ptr;
               ptr = ptr->next;
               curr++;
           }

           temp->data = value;
           temp->next = ptr;
           prev->next = temp;
           length++;
       }

       void deleteFirst(){
           node* temp = head;
           head = head->next;
           length--;
           delete temp;
       }

       void deleteLast() {
           node* temp = head;
           node* prev = new node;

           while (temp->next != NULL)
           {
               prev = temp;
               temp = temp->next;

           }
           tail = prev;
           prev->next = NULL;

           length--;
           delete temp;
       }

       void deletePosition(int position){
           node* current=head;
           node* previous;

           if(position>length||position<=0){
               std::cout<<"Out of bounds\n";
               exit(1);
           }

           for(int i=1;i<position;i++){
               previous = current;
               current = current->next;
           }

           previous->next = current->next;
           length--;
           delete current;
       }

       bool empty(){
           if(head==NULL)
               return true;
           return false;
       }

       int valuePosition(int position){
           node* temp = head;
           if(position>length||position<=0){
               std::cout<<"Out of boundaries!\n";
               exit(1);
           }
           for(int i = 1;i<position;i++){
               temp = temp->next;
           }
           return temp->data;
       }

       int frontValue(){
        if(head == NULL)
        {
            std::cout << "Linked list is empty! \n";
            exit(1);
        }
        return head->data;
    }

       int tailValue(){
        if(tail == NULL)
        {
            std::cout << "Linked list is empty! \n";
            exit(1);
        }
        return tail->data;
    }

       void reverse(node* curr = NULL) {
           if(curr == NULL)
           {
               curr = head;
           }

           node* temp = curr;

           if(temp->next == NULL)
           {
               std::cout << temp->data << "\t";
               return;
           }

           reverse(temp->next);
           std::cout << temp->data << "\t";
       }


};