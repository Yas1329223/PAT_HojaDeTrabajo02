#include "Ejercicio02.h"

Node<int>* Ejercicio02::addTwoNumbers(Node<int>* l1, Node<int>* l2) 
{
    Node<int>* dummyHead = new Node<int>(0);
    Node<int>* current = dummyHead;
    int carry = 0;

    while (l1 || l2)
    {
        int sum = carry;

        if (l1) 
        {
            sum += l1->data;
            l1 = l1->next;
        }

        if (l2) 
        {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;
        current->next = new Node<int>(sum % 10);
        current = current->next;
    }

    if (carry > 0)
    {
        current->next = new Node<int>(carry);
    }

    Node<int>* result = dummyHead->next;
    delete dummyHead;
    return result;
}
