package com.company;

/**
 * Created by asifmayilli on 7/18/17.
 */
class Node{
    int key;
    int value; // property
    Node pre;
    Node next;

    public Node(int key, int value){
        this.key = key;
        this.value = value;
    }

}