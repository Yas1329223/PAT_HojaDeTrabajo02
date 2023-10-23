#include "Ejercicio01.h"

Node<char>* Ejercicio01::rotateRight(Node<char>* head, int k)
{
    if (!head || k == 0) {
        return head;
    }

    int length = 1;
    Node<char>* tail = head;

    while (tail->next) {
        tail = tail->next;
        length++;
    }

    k = k % length;

    if (k == 0) {
        return head;
    }

    tail->next = head;

    int shift = length - k;
    while (shift--) {
        head = head->next;
        tail = tail->next;
    }

    tail->next = nullptr;

    return head;
}
