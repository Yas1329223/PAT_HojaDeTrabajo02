#include "Ejercicio04.h"

FrontMiddleBackQueue::FrontMiddleBackQueue()
{
	front = nullptr;
	middle = nullptr;
	back = nullptr;
}

void FrontMiddleBackQueue::pushFront(int value)
{
	Nodo* newNode = new Nodo{ value };
	if (front == nullptr)
    {
		front = newNode;
		middle = newNode;
		back = newNode;
	}
	else {
		newNode->next = front;
		front = newNode;
		if (tamanio % 2 == 0) {
			middle = middle->next;
		}
	}
	tamanio++;
}

void FrontMiddleBackQueue::pushMiddle(int value)
{
	Nodo* newNode = new Nodo{ value };

	if (front == nullptr)
    {
		front = newNode;
		middle = newNode;
		back = newNode;
	}
	else if (tamanio == 1)
    {
		newNode->next = front;
		back = front;
		front = newNode;
		middle = front;
	}
	else {
		Nodo* fast = front;
		Nodo* slow = front;
		Nodo* prev = nullptr;
		while (fast != nullptr && fast->next != nullptr) {
			fast = fast->next->next;
			prev = slow;
			slow = slow->next;
		}
		if (prev != nullptr)
        {
			prev->next = newNode;
		}
		else 
        {
			front = newNode;
		}
		newNode->next = slow;
		if (slow == nullptr)
        {
			back = newNode;
		}
		else if (tamanio % 2 == 0)
        {
			middle = middle->next;
		}
	}
	tamanio++;
}

void FrontMiddleBackQueue::pushBack(int value)
{
	Nodo* newNode = new Nodo{ value };
	if (back == nullptr) {
		front = newNode;
		middle = newNode;
		back = newNode;
	}
	else
    {
		back->next = newNode;
		back = newNode;
		if (tamanio % 2 == 1) 
        {
			middle = middle->next;
		}
	}
	tamanio++;
}

int FrontMiddleBackQueue::popFront()
{
	if (front == nullptr)
    {
		return -1;
	}
	int value = front->value;
	if (front == back) 
    {
		delete front;
		front = nullptr;
		middle = nullptr;
		back = nullptr;
	}
	else {
		Nodo* temp = front;
		front = front->next;
		delete temp;
		if (tamanio % 2 == 1) 
        {
			middle = middle->next;
		}
	}
	tamanio--;
	return value;
}

int FrontMiddleBackQueue::popMiddle()
{
	if (front == nullptr) 
    {
		return -1;
	}

	if (front == back)
    {
		int value = front->value;
		delete front;
		front = nullptr;
		middle = nullptr;
		back = nullptr;
		tamanio--;
		return value;
	}
	else {
		Nodo* fast = front;
		Nodo* slow = front;
		Nodo* prev = nullptr;
		while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr) {
			fast = fast->next->next;
			prev = slow;
			slow = slow->next;
		}
		int value = slow->value;
		if (prev != nullptr)
        {
			prev->next = slow->next;
		}
		else {
			front = slow->next;
		}
		delete slow;
		tamanio--;
		if (tamanio % 2 == 0)
        {
			middle = middle->next;
		}
		return value;
	}
}

int FrontMiddleBackQueue::popBack()
{
	if (front == nullptr)
    {
		return -1;
	}
	int value = back->value;
	if (front == back)
    {
		delete front;
		front = nullptr;
		middle = nullptr;
		back = nullptr;
	}
	else {
		Nodo* temp = front;
		while (temp->next != back) 
        {
			temp = temp->next;
		}
		delete back;
		back = temp;
		back->next = nullptr;
		if (tamanio % 2 == 0)
        {
			middle = middle->next;
		}
	}
	tamanio--;
	return value;
}
