//
// Created by Umar Khan on 6/26/22.
//

#ifndef DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H

class DoublyLinkedList {

public:
    struct Node {
        int data;
        Node *prev;
        Node *next;
    };

    DoublyLinkedList();
    void addHead(int newData);
    void addBefore(int beforeNumber, int newData);
    void addAfter(int afterNumber, int newData);
    void addTail(int newData);
    void removeHead();
    void removeNode(int removeNumber);
    void removeTail();
    void printListForward();
    void printListReverse();
    void printHeadTail();
    void printListDetails();

private:
    Node *head;
    Node *tail;
};

#endif //DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
