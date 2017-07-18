package com.company;

import java.util.HashMap;

/**
 * Created by asifmayilli on 7/18/17.
 */
public class LRUCache {
    int capacity;
    HashMap<Integer, Node> map = new HashMap<Integer, Node>();
    Node head = null;
    Node end = null;

    // constructor
    public LRUCache(int capacity) {
        this.capacity = capacity;
    }


    public int get(int key) {
        if (map.containsKey(key)) {
            Node n = map.get(key); // get value = node
            remove(n);
            setHead(n);
            return n.value;
        }

        return -1;
    }

    public void remove(Node n) {
        if (n.pre != null) {
            n.pre.next = n.next;
        } else { // remove first element from queue
            head = n.next;
        }

        if (n.next != null) { // remove element
            n.next.pre = n.pre;
        } else { // remove last element (from end of queue)
            end = n.pre;
        }
        // System.out.println("3 pre = " + n.pre.value);

    }

    public void setHead(Node n) { // move element to head of queue
        n.next = head;
        n.pre = null;

        if (head != null)
            head.pre = n;

        head = n;

        // if queue is empty
        if (end == null)
            end = head;
    }

    public void set(int key, int value) {
        if (map.containsKey(key)) {
            Node old = map.get(key);
            old.value = value;
            if(old != head)
            {
                remove(old);
                setHead(old);
            }

        } else { // if elmeent doesnt exist
            Node created = new Node(key, value);
            if (map.size() >= capacity) { // if queue is full
                map.remove(end.key);
                remove(end);
                setHead(created);
            } else {
                setHead(created);
            }

            map.put(key, created); // add element to hash
        }
    }
}