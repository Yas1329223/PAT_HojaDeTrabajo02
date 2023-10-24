#include "Ejercicio04.h"

FrontMiddleBackQueue::FrontMiddleBackQueue()
{
	front = nullptr;
	back = nullptr;
}

void FrontMiddleBackQueue::pushFront(int value)
{
	Nodo* newNode = new Nodo{ value };
	if (front == nullptr) {
		front = newNode;
		back = newNode;
	}
	else {
		newNode->next = front;
		front = newNode;
	}
	tamanio++;
}

void FrontMiddleBackQueue::pushMiddle(int value)
{
	Nodo* newNode = new Nodo{ value };

	if (front == nullptr) {
		front = newNode;
		back = newNode;
	}
	else if (tamanio == 1) {
		newNode->next = front;
		back = front;
		front = newNode;
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
		if (prev != nullptr) {
			prev->next = newNode;
		}
		else {
			front = newNode;
		}
		newNode->next = slow;
		if (slow == nullptr) {
			back = newNode;
		}
	}
	tamanio++;
}

void FrontMiddleBackQueue::pushBack(int value)
{
	Nodo* newNode = new Nodo{ value };
	if (back == nullptr) {
		front = newNode;
		back = newNode;
	}
	else {
		back->next = newNode;
		back = newNode;
	}
	tamanio++;
}

int FrontMiddleBackQueue::popFront()
{
	if (front == nullptr) {
		return -1;
	}
	int valor = front->valor;
	if (front == back) {
		delete front;
		front = nullptr;
		back = nullptr;
	}
	else {
		Nodo* temporal = front;
		front = front->next;
		delete temporal;
	}
	tamanio--;
	return valor;
}

int FrontMiddleBackQueue::popMiddle()
{
	if (front == nullptr) {
		return -1;
	}

	if (front == back) {
		int valor = front->valor;
		delete front;
		front = nullptr;
		back = nullptr;
		tamanio--;
		return valor;
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
		int valor = slow->valor;
		if (prev != nullptr) {
			prev->next = slow->next;
		}
		else {
			front = slow->next;
		}
		delete slow;
		tamanio--;
		return valor;
	}
}

int FrontMiddleBackQueue::popBack()
{
	if (front == nullptr) {
		return -1;
	}
	int valor = back->valor;
	if (front == back) {
		front = nullptr;
		back = nullptr;
	}
	else {
		Nodo* temporal = front;
		while (temporal->next != back) {
			temporal = temporal->next;
		}
		delete back;
		back = temporal;
		back->next = nullptr;
	}
	tamanio--;
	return valor;
}
