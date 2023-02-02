//
// Created by Daniel Agu on 10/20/2020.
//

#include <iostream>
#include "LinkedList.h"
#include "LinkedListException.h"

using namespace std;

LinkedList::LinkedList() {
    length = 0;
    head = nullptr;
    tail = nullptr;
}

void LinkedList::addItemToFront(LinkedListItem *newItem) {
    if (newItem == nullptr) {
        throw LinkedListException();
    }
    if (length == 0) {
        // if the linked list is empty and a new item is added it will become the head and the tail
        head = newItem;
        tail = newItem;
        newItem->next = nullptr;
        newItem->prev = nullptr;
        length++;
    }
    else {
        // makes the new item added the new head
        newItem->next = head;
        newItem->prev = nullptr;
        head->prev = newItem;
        head = newItem;
        length++;
    }
}

void LinkedList::addItemToBack(LinkedListItem *newItem) {
    if (newItem == nullptr) {
        throw LinkedListException();
    }
    if (length == 0) {
        // if the linked list is empty and a new item is added it will become the head and the tail
        head = newItem;
        tail = newItem;
        newItem->next = nullptr;
        newItem->prev = nullptr;
        length++;
    }
    else {
        // makes the new item added the new tail
        newItem->next = nullptr;
        newItem->prev = tail;
        tail->next = newItem;
        tail = newItem;
        length++;
    }
}

void LinkedList::addItemAt(int index, LinkedListItem *newItem) {
    if (!(0 <= index && index <= length)) {
        // makes sure the index is at the beginning, the end, or within the linked list
        throw LinkedListException();
    }
    if (index == 0) {
        addItemToFront(newItem);
    }
    else if (index == length) {
        addItemToBack(newItem);
    }
    else {
        // shifts the old item at the corresponding index to the right and places the new item at the new index
        LinkedListItem *oldItem = getItemAt(index);
        oldItem->prev->next = newItem;
        newItem->prev = oldItem->prev;
        newItem->next = oldItem;
        oldItem->prev = newItem;
        length++;
    }
}

int LinkedList::getLength() {
    return length;
}

LinkedListItem *LinkedList::getFirstItem() {
    return head;
}

LinkedListItem *LinkedList::getLastItem() {
    return tail;
}

LinkedListItem *LinkedList::getItemAt(int index) {
    LinkedListItem *output = head;
    if (!(0 <= index && index < length)) {
        // makes sure the index is within the linked list
        throw LinkedListException();
    }
    for (int i = 0; i < index; i++) {
        output = output->next;
    }
    return output;
}

LinkedListItem *LinkedList::removeFirstItem() {
    LinkedListItem *removed = head;
    if (length == 0) {
        return nullptr;
    }
    else if (length > 1) {
        // makes the item after the head the new head
        head = head->next;
        head->prev = nullptr;
        length--;
    }
    else if (length == 1) {
        // a linked list with one item becomes and empty list
        head = nullptr;
        tail = head;
        length--;
    }
    return removed;
}

LinkedListItem *LinkedList::removeLastItem() {
    LinkedListItem *removed = tail;
    if (length == 0) {
        return nullptr;
    }
    else if (length > 1) {
        // makes the item previous to the tail the new tail
        tail = tail->prev;
        tail->next = nullptr;
        length--;
    }
    else if (length == 1) {
        // a linked list with one item becomes and empty list
        head = nullptr;
        tail = head;
        length--;
    }
    return removed;
}

LinkedListItem *LinkedList::removeItemAt(int index) {
    if (!(0 <= index && index < length)) {
        // makes sure the index is within the linked list
        throw LinkedListException();
    }
    else if (length == 1) {
        // captures and returns the removed item if length is 1 and leaves an empty linked list
        LinkedListItem *removed = getItemAt(0);
        head = nullptr;
        tail = head;
        length--;
        return removed;
    }
    else if (index == 0) {
        return removeFirstItem();
    }
    else if (index == length - 1) {
        return removeLastItem();
    }
    else {
        // captures and returns the removed item and sets adjacent item's pointers to each other
        LinkedListItem *removed = getItemAt(index);
        removed->prev->next = removed->next;
        removed->next->prev = removed->prev;
        length--;
        return removed;
    }
}

void LinkedList::printList() {
    LinkedListItem *cycle = head;
    while (cycle != nullptr) {
        cycle->printInfo();
        cycle = cycle->next;
    }
}

void LinkedList::printListBackwards() {
    LinkedListItem *cycle = tail;
    while (cycle != nullptr) {
        cycle->printInfo();
        cycle = cycle->prev;
    }
}
