//
// Created by Daniel Agu on 10/20/2020.
//

#include <iostream>
#include "LinkedListItem.h"
using namespace std;

LinkedListItem::LinkedListItem(int a) {
    data = a;
}

int LinkedListItem::getItem() {
    return data;
}

LinkedListItem* LinkedListItem::getNextItem() {
    return next;
}

LinkedListItem* LinkedListItem::getPreviousItem() {
    return prev;
}

void LinkedListItem::printInfo() {
    cout << data << endl;
}