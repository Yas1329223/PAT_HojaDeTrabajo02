#include "Ejercicio02.h"
#include <string>
using namespace std;

Node<int>* Ejercicio02::addTwoNumbers(Node<int>* list1, Node<int>* list2)
{
    if (list1 == nullptr) 
    {
        return list2;
    } else if (list2 == nullptr) 
    {
        return list1;
    }

    int count1 = 1;
    int count2 = 1;
    Node<int>* current1 = list1;
    Node<int>* current2 = list2;

    while (current1->next != nullptr) 
    {
        count1++;
        current1 = current1->next;
    }

    while (current2->next != nullptr) 
    {
        count2++;
        current2 = current2->next;
    }

    if ((count1 >= 1 && count1 <= 360) && (count2 >= 1 && count2 <= 360))
    {
        Node<int>* dummy = new Node<int>{ 0 };
        Node<int>* temp = dummy;
        int carry = 0;

        while (list1 != nullptr || list2 != nullptr || carry != 0) 
        {
            int digit1 = 0;
            int digit2 = 0;

            if (list1) 
            {
                digit1 = list1->value;
                list1 = list1->next;
            }
            
            if (list2) 
            {
                digit2 = list2->value;
                list2 = list2->next;
            }

            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            Node<int>* newNode = new Node<int>{ sum % 10 };
            temp->next = newNode;
            temp = temp->next;
        }
        
        return dummy->next;
    }
    
    return nullptr;
}
