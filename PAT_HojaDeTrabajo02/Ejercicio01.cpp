#include "Ejercicio01.h"

Node<char>* Ejercicio01::rotateRight(Node<char>* head, int k)
{
    if (!head || k == 0) {
        return head;
    }

    int length = 1;
    Node<char>* current = head;

    // Calcula la longitud de la lista
    while (current->next) {
        length++;
        current = current->next;
    }

    k = k % length;  // Posición efectiva de rotación

    if (k == 0) {
        return head;  // No es necesario rotar
    }

    // Encuentra el nuevo nodo principal después de la rotación
    Node<char>* new_head = head;
    for (int i = 0; i < length - k - 1; i++) {
        new_head = new_head->next;
    }

    // Actualiza los punteros para realizar la rotación
    Node<char>* new_tail = new_head;
    while (new_tail->next) {
        new_tail = new_tail->next;
    }
    new_tail->next = head;
    head = new_head->next;
    new_head->next = nullptr;

    return head;
}
