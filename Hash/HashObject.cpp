//
// Created by Asif Mayilli on 10/31/17.
//
#include <stddef.h>
#include <iosfwd>
#include <string>
#include <iostream>
#include <math.h>

#define MAX_SIZE 10
#define alpha 26

using namespace std;

struct node{
    std::string key;
    int value;
};

class HashTable{
    private:
        node* arr[MAX_SIZE];
        int size = 0;
    public:
        HashTable(){
            for (int i = 0; i <MAX_SIZE ; ++i){
               //arr[i] = new node;
               arr[i] = NULL;
            }
        }

    ~HashTable(){
        for (int i = 0; i <MAX_SIZE ; ++i) {
            delete arr[i];
        }
        cout<<"destroyed hashtable\n";
    }

    int hash_func(std::string key){
        long long int hash = 0;

        for(int i = 0; i < key.size(); i++) {
            int k = key.size() - (i + 1);

            hash = hash + (int)pow(alpha,k)*key[i];
        }

        return hash % MAX_SIZE;
    }

    void add(std::string key, int value) {
        int hash = hash_func(key);
        int temp = hash;

        if(exists(key))
        {
            cout << "Key already exists in Hash Table!";
            return;
        }

        while (arr[hash] != NULL && hash < MAX_SIZE) {
            hash++;
        }

        if (arr[hash] != NULL) {
            hash = 0;
        }

        while (arr[hash] != NULL && hash < temp) {
            hash++;
        }

        if (arr[hash] == NULL) {
            arr[hash] = new node;

            arr[hash]->value = value;
            arr[hash]->key = key;
        }
        else
        {
            std::cout << "There's no place in hashtable\n";
        }
    }

    void display(){
        for (int i = 0; i < MAX_SIZE; ++i) {
            if(arr[i] != NULL)
                std::cout << arr[i]->key << " -> " << arr[i]->value << "\n";
        }
    }

    bool exists(std::string key) {
        int hash = hash_func(key);
        for(int i=hash;i<MAX_SIZE;i++){
            if(arr[i]!=NULL){
                if(arr[i]->key==key)
                    return true;
            }
        }
        for(int i=0;i<hash;i++){
            if(arr[i]!=NULL){
                if(arr[i]->key==key)
                    return true;
            }
        }

        return false;
    }

    int get(std::string key){
        int hash = hash_func(key);
        for(int i=hash;i<MAX_SIZE;i++){
            if(arr[i]!=NULL){
                if(arr[i]->key==key)
                    return arr[i]->value;
            }
        }
        for(int i=0;i<hash;i++){
            if(arr[i]!=NULL){
                if(arr[i]->key==key)
                    return arr[i]->value;
            }
        }

        cout<<"Key not found\n";
        exit(1);
    }

    void remove(string key) {
        int hash = hash_func(key);

        for(int i=hash;i<MAX_SIZE;i++){
            if(arr[i]!=NULL){
                if(arr[i]->key==key){
                    arr[i] = NULL;
                    return;
                }
            }
        }
        for(int i=0;i<hash;i++){
            if(arr[i]!=NULL){
                if(arr[i]->key==key){
                    arr[i] = NULL;
                    return;
                }
            }
        }

        cout<<"Key not found in Hash Table\n";
        return;
    }

};