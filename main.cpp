//
// Created by Erik Peterson on 7/27/20.
//
#include <iostream>
#include <assert.h>
#include "LinkedList.h"
#include "LinkedListItem.h"
#include "LinkedListException.h"

using namespace std;

//---------------------------------------------------------
// Tests adding things to the beginning of the list
//----------------------------------------------------------
void testAddingToBeginning() {
    LinkedList myLinkedList;

    try {
        myLinkedList.addItemToFront(nullptr);
        cerr << "Able to add null to the front?" << endl;
        exit(1);
    } catch ( LinkedListException e) {
        // Expected
    }

    LinkedListItem* firstItem = new LinkedListItem(20);
    myLinkedList.addItemToFront(firstItem);
    assert(myLinkedList.getLength() == 1);
    assert(myLinkedList.getFirstItem() == myLinkedList.getLastItem());

    LinkedListItem* newFirstItem = new LinkedListItem(10);
    myLinkedList.addItemToFront(newFirstItem);
    assert(myLinkedList.getLength() == 2);
    assert(myLinkedList.getFirstItem() != myLinkedList.getLastItem());
    assert(myLinkedList.getFirstItem()->getItem() == 10);

    myLinkedList.printList();
    myLinkedList.printListBackwards();

    // Yes, there are more here than we have items. It's to make sure that
    // we get
    assert(myLinkedList.removeFirstItem()->getItem() == 10);
    assert(myLinkedList.removeFirstItem()->getItem() == 20);
    assert(myLinkedList.removeFirstItem() == nullptr);
    assert(myLinkedList.getFirstItem() == nullptr);
    assert(myLinkedList.getLastItem() == nullptr);
    assert(myLinkedList.getLength() == 0);
}

//---------------------------------------------------------
// Tests adding things to the middle of the list
//----------------------------------------------------------
    void testAddingToMiddle() {
    LinkedList myLinkedList;

    try {
        myLinkedList.addItemAt(0, nullptr);
        cerr << "Able to add null to the front?" << endl;
        exit(1);
    } catch ( LinkedListException e) {
        // Expected
    }

    LinkedListItem* firstItem = new LinkedListItem(20);
    try {
        myLinkedList.addItemAt(1, firstItem);
        cerr << "Able to add to an invalid location" << endl;
        exit(1);
    } catch ( LinkedListException e) {
        // Expected
    }

    myLinkedList.addItemAt(0, firstItem);
    assert(myLinkedList.getLength() == 1);
    assert(myLinkedList.getFirstItem() == myLinkedList.getLastItem());

    LinkedListItem* lastItem = new LinkedListItem(10);
    myLinkedList.addItemAt(1, lastItem);
    assert(myLinkedList.getLength() == 2);
    assert(myLinkedList.getFirstItem() != myLinkedList.getLastItem());
    assert(myLinkedList.getItemAt(1)->getItem() == 10);


    LinkedListItem* middleItem = new LinkedListItem(15);
    myLinkedList.addItemAt(1, middleItem);
    assert(myLinkedList.getLength() == 3);
    assert(myLinkedList.getItemAt(1) != myLinkedList.getLastItem());
    assert(myLinkedList.getItemAt(1)->getItem() == 15);

    try {
        myLinkedList.getItemAt(3);
        cerr << "Able to get an out-of-bounds item!";
        exit(-1);
    } catch ( LinkedListException e) {
        // Expected
    }

    // Try traversing the list
    LinkedListItem* node = myLinkedList.getFirstItem();
    assert(node->getItem() == 20);
    assert(node->getNextItem()->getItem() == 15);
    assert(node->getNextItem()->getNextItem()->getItem() == 10);

    // Now go backwards
    node = myLinkedList.getLastItem();
    assert(node->getItem() == 10);
    assert(node->getPreviousItem()->getItem() == 15);
    assert(node->getPreviousItem()->getPreviousItem()->getItem() == 20);

    assert(myLinkedList.removeItemAt(1)->getItem() == 15);
    assert(myLinkedList.removeItemAt(1)->getItem() == 10);
    assert(myLinkedList.removeItemAt(0)->getItem() == 20);
    assert(myLinkedList.removeFirstItem() == nullptr);
    assert(myLinkedList.getFirstItem() == nullptr);
    assert(myLinkedList.getLastItem() == nullptr);
    assert(myLinkedList.getLength() == 0);
}

//---------------------------------------------------------
// Tests adding things to the end of the list
//----------------------------------------------------------
    void testAddingToEnd() {
    LinkedList myLinkedList;

    try {
        myLinkedList.addItemToBack(nullptr);
        cerr << "Able to add null to the back?" << endl;
        exit(1);
    } catch ( LinkedListException e) {
        // Expected
    }

    LinkedListItem* firstItem = new LinkedListItem(10);
    myLinkedList.addItemToBack(firstItem);
    assert(myLinkedList.getLength() == 1);
    assert(myLinkedList.getFirstItem() == myLinkedList.getLastItem());

    LinkedListItem* newFirstItem = new LinkedListItem(20);
    myLinkedList.addItemToBack(newFirstItem);
    assert(myLinkedList.getLength() == 2);
    assert(myLinkedList.getFirstItem() != myLinkedList.getLastItem());
    assert(myLinkedList.getLastItem()->getItem() == 20);

    myLinkedList.printList();
    myLinkedList.printListBackwards();

    // Yes, there are more here than we have items. It's to make sure that
    // we get
    assert(myLinkedList.removeLastItem()->getItem() == 20);
    assert(myLinkedList.removeLastItem()->getItem() == 10);
    assert(myLinkedList.removeLastItem() == nullptr);
    assert(myLinkedList.getFirstItem() == nullptr);
    assert(myLinkedList.getLastItem() == nullptr);
    assert(myLinkedList.getLength() == 0);
}

int main(int argc, char** argv) {
    testAddingToBeginning();
    testAddingToMiddle();
    testAddingToEnd();
}
