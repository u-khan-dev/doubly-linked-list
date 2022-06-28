//
// Created by Umar Khan on 6/26/22.
//

#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

void DoublyLinkedList::addHead(int newData) {
    Node* newNode = new Node();
    newNode->data = newData;

    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
        newNode->next->prev = newNode;
    }
}

void DoublyLinkedList::addBefore(int beforeNumber, int newData) {
    if (head != nullptr) {
        Node* curr = head;

        while (curr != nullptr) {
            if (curr->data == beforeNumber) {
                Node *newNode = new Node();
                newNode->data = newData;

                if (curr == head) {
                    addHead(newData);
                } else {
                    curr->prev->next = newNode;
                    newNode->prev = curr->prev;
                    newNode->next = curr;
                    curr->prev = newNode;
                }

                break;
            }

            curr = curr->next;
        }
    }
}

void DoublyLinkedList::addAfter(int afterNumber, int newData) {
    if (head != nullptr) {
        Node* curr = head;

        while (curr != nullptr) {
            if (curr->data == afterNumber) {
                Node *newNode = new Node();
                newNode->data = newData;

                if (curr->next == nullptr) {
                    addTail(newData);
                } else {
                    curr->next->prev = newNode;
                    newNode->prev = curr;
                    newNode->next = curr->next;
                    curr->next = newNode;
                }

                break;
            }

            curr = curr->next;
        }
    }
}

void DoublyLinkedList::addTail(int newData) {
    if (head != nullptr) {
        Node *newNode = new Node();
        newNode->data = newData;

        if (tail != nullptr) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            head->next = newNode;
            newNode->prev = head;
            tail = newNode;
        }
    }
}

void DoublyLinkedList::removeHead() {
    if (head != nullptr) {
        Node* removeNode = head;

        if (tail == nullptr) {
            head = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
            removeNode->next = nullptr;
        }
    }
}

void DoublyLinkedList::removeNode(int removeNumber) {
    if (head != nullptr) {
        Node* curr = head;

        while (curr != nullptr) {
            if (curr->data == removeNumber) {
                if (curr == head) {
                    removeHead();
                } else if (curr == tail) {
                    removeTail();
                } else {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                    curr->prev = nullptr;
                    curr->next = nullptr;
                }

                break;
            }

            curr = curr->next;
        }
    }
}

void DoublyLinkedList::removeTail() {
    if (tail != nullptr) {
        Node* removeNode = tail;

        if (tail->prev == head) {
            tail = nullptr;
            head->next = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
            removeNode->prev = nullptr;
        }
    }
}

void DoublyLinkedList::printListForward() {
    if (head != nullptr) {
        if (tail != nullptr) {
            Node *curr = head;
            string arrow;

            cout << "\nnull <--- ";

            while (curr != tail) {
                if (curr->next == nullptr) {
                    arrow = " ---> ";
                } else {
                    arrow = " <---> ";
                }

                cout << curr->data << arrow;
                curr = curr->next;
            }

            cout << tail->data << " ---> null\n";
        } else {
            cout<<"\nnull <--- " << head->data << " ---> null";
        }
    }
}

void DoublyLinkedList::printListReverse() {
    if (head != nullptr) {
        if (tail != nullptr) {
            Node *curr = tail;
            string arrow;

            cout << "\nnull <--- ";

            while (curr != head) {
                if (curr->prev == nullptr) {
                    arrow = " ---> ";
                } else {
                    arrow = " <---> ";
                }

                cout << curr->data << arrow;
                curr = curr->prev;
            }

            cout << head->data << " ---> null\n";
        } else {
            cout<<"\nnull <--- " << head->data << " ---> null";
        }
    }
}

void DoublyLinkedList::printHeadTail() {
    string H, T;

    if (head == nullptr) {
        H = "null";
    } else {
        H = to_string(head->data);
    }

    if (tail == nullptr) {
        T = "null";
    } else {
        T = to_string(tail->data);
    }

    cout << "\n(" << H << ", " << T << ")\n";
}

void DoublyLinkedList::printListDetails() {
    printListForward();
    printListReverse();
    printHeadTail();
}
