//
// Created by Daniel Agu on 10/20/2020.
//

#ifndef PROJECT_1_DOUBLY_LINKED_LIST_CS2337DANIELAGU_LINKEDLISTITEM_H
#define PROJECT_1_DOUBLY_LINKED_LIST_CS2337DANIELAGU_LINKEDLISTITEM_H



#include <iostream>
using namespace std;

class LinkedListItem {
public:
    int data;
    LinkedListItem* next;
    LinkedListItem* prev;

    LinkedListItem(int a);

    int getItem();
    LinkedListItem* getNextItem();
    LinkedListItem* getPreviousItem();

    void printInfo();
};

#endif //PROJECT_1_DOUBLY_LINKED_LIST_CS2337DANIELAGU_LINKEDLISTITEM_H