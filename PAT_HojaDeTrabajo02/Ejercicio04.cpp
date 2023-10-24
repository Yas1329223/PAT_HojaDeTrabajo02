#include "Exercise04.h"

FrontMiddleBackQueue::FrontMiddleBackQueue()
{
    frontNode = nullptr;
    backNode = nullptr;
}

void FrontMiddleBackQueue::pushFront(int value)
{
    Node* newNode = new Node{ value };
    if (frontNode == nullptr) {
        frontNode = newNode;
        backNode = newNode;
    }
    else {
        newNode->next = frontNode;
        frontNode = newNode;
    }
    size++;
}

void FrontMiddleBackQueue::pushMiddle(int value)
{
    Node* newNode = new Node{ value };

    if (frontNode == nullptr) {
        frontNode = newNode;
        backNode = newNode;
    }
    else if (size == 1) {
        newNode->next = frontNode;
        backNode = frontNode;
        frontNode = newNode;
    }
    else {
        Node* fast = frontNode;
        Node* slow = frontNode;
        Node* prev = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        if (prev != nullptr) {
            prev->next = newNode;
        }
        else {
            frontNode = newNode;
        }
        newNode->next = slow;
        if (slow == nullptr) {
            backNode = newNode;
        }
    }
    size++;
}

void FrontMiddleBackQueue::pushBack(int value)
{
    Node* newNode = new Node{ value };
    if (backNode == nullptr) {
        frontNode = newNode;
        backNode = newNode;
    }
    else {
        backNode->next = newNode;
        backNode = newNode;
    }
    size++;
}

int FrontMiddleBackQueue::popFront()
{
    if (frontNode == nullptr) {
        return -1;
    }
    int value = frontNode->value;
    if (frontNode == backNode) {
        delete frontNode;
        frontNode = nullptr;
        backNode = nullptr;
    }
    else {
        Node* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
    }
    size--;
    return value;
}

int FrontMiddleBackQueue::popMiddle()
{
    if (frontNode == nullptr) {
        return -1;
    }

    if (frontNode == backNode) {
        int value = frontNode->value;
        delete frontNode;
        frontNode = nullptr;
        backNode = nullptr;
        size--;
        return value;
    }
    else {
        Node* fast = frontNode;
        Node* slow = frontNode;
        Node* prev = nullptr;
        while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        int value = slow->value;
        if (prev != nullptr) {
            prev->next = slow->next;
        }
        else {
            frontNode = slow->next;
        }
        delete slow;
        size--;
        return value;
    }
}

int FrontMiddleBackQueue::popBack()
{
    if (frontNode == nullptr) {
        return -1;
    }
    int value = backNode->value;
    if (frontNode == backNode) {
        frontNode = nullptr;
        backNode = nullptr;
    }
    else {
        Node* temp = frontNode;
        while (temp->next != backNode) {
            temp = temp->next;
        }
        delete backNode;
        backNode = temp;
        backNode->next = nullptr;
    }
    size--;
    return value;
}
