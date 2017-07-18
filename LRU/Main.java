package com.company;

import java.util.HashMap;

public class Main {

    public static void main(String[] args) {
        LRUCache lr=new LRUCache(5);
        lr.set(1, 1);
        lr.set(2,2);
        lr.set(3, 3);
        lr.set(4, 4);
        lr.set(5, 5);
        // queue 5 4 3 2 1
        // hash 1 2 3 4 5
        int val=lr.get(1);
        // queue 1 5 4 3 2
        // hash 1 2 3 4 5
        System.out.println(""+val); // 1

        lr.set(6, 6);
        // 2 deleted cause cache is full
        // queue 6 1 5 4 3
        // hash 1 3 4 5 6
        int val2=lr.get(2);
        // -1 cause 2 is not in cache
        if(val2 == -1)
            System.out.println("element " + val2 +  " not found");
        int val3 = lr.get(6);
        System.out.println(""+val3); // return 6
        System.out.print(lr.capacity);

    }
}



