#include <iostream>

#define SIZE 5

class QueueArray{
    private:
        int front = -1;
        int back = -1;
        int array[SIZE];

    public:
        QueueArray(){
        }

        void enqueue(int value){

            if((back + 1) % SIZE == front)
            {
                std::cout << "Queue is full! You cannot add any element to queue! \n";
                return;
            }

            if(empty()) // empty queue
            {
                front++;
            }

            back = (back + 1) % SIZE;
            array[back] = value;

            // std::cout << front << "\n" << back << "\n";

        }

        bool empty() {
            if (front == -1 && back == -1)
            {
                return true;
            }
            return false;
        }

        void display(){
            //std::cout << front << "\t" << back << "\n\n\n";
            if(empty())
            {
                std::cout<< "Queue is empty!\n";
                return;
            }

            if(front == back)
            {
                std::cout << array[front] << "\n";
                return;
            }

            if(front < back)
            {
                for (int i = front; i <= back; ++i) {
                    std::cout << array[i] << "\t";
                }
                std::cout<<"\n";
            }
            else
            {
                for (int i = front; i < SIZE; ++i) {
                    std::cout << array[i] << "\t";
                }
                for (int j = 0; j <= back; ++j) {
                    std::cout << array[j] << "\t";
                }
                std::cout<<"\n";
            }

        }

        int dequeue()
        {

            //std::cout << front << "\t" << back << "\n\n\n";


            if(empty())
            {
                std::cout<< "Queue is empty!\n";
                exit(1);
            }

            int temp = array[front];

            if(front == back)
            {
                front = -1;
                back = -1;
                return temp;
            }

            front = (front + 1) % SIZE;
            return temp;
        }
};