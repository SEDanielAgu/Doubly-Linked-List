//
// Created by Daniel Agu on 10/20/2020.
//

#ifndef PROJECT_1_DOUBLY_LINKED_LIST_CS2337DANIELAGU_LINKEDLIST_H
#define PROJECT_1_DOUBLY_LINKED_LIST_CS2337DANIELAGU_LINKEDLIST_H


#include <iostream>
#include "LinkedListItem.h"

using namespace std;

class LinkedList {
public:
    int length;
    LinkedListItem *head;
    LinkedListItem *tail;

    LinkedList();

    void addItemToFront(LinkedListItem *newItem);
    void addItemToBack(LinkedListItem *newItem);
    void addItemAt(int index, LinkedListItem* newItem);

    int getLength();
    LinkedListItem *getFirstItem();
    LinkedListItem *getLastItem();
    LinkedListItem *getItemAt(int index);

    LinkedListItem *removeFirstItem();
    LinkedListItem *removeLastItem();
    LinkedListItem *removeItemAt(int index);

    void printList();
    void printListBackwards();

};

#endif //PROJECT_1_DOUBLY_LINKED_LIST_CS2337DANIELAGU_LINKEDLIST_H