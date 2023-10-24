#include "Ejercicio04.h"

FrontMiddleBackQueue::FrontMiddleBackQueue()
{
	front = nullptr;
	back = nullptr;
}

void FrontMiddleBackQueue::pushFront(int value)
{
	Nodo* nuevo = new Nodo{ value };
	if (front == nullptr) {
		front = nuevo;
		back = nuevo;
	}
	else {
		nuevo->next = front;
		front = nuevo;
	}
	tamanio++;
}

void FrontMiddleBackQueue::pushMiddle(int value)
{
	Nodo* nuevo = new Nodo{ value };

	if (front == nullptr) {
		front = nuevo;
		back = nuevo;
	}
	else if (tamanio == 1) {
		nuevo->next = front;
		back = front;
		front = nuevo;
	}
	else {
		Nodo* rapido = front;
		Nodo* lento = front;
		Nodo* previo = nullptr;
		while (rapido != nullptr && rapido->next != nullptr) {
			rapido = rapido->next->next;
			previo = lento;
			lento = lento->next;
		}
		if (previo != nullptr) {
			previo->next = nuevo;
		}
		else {
			front = nuevo;
		}
		nuevo->next = lento;
		if (lento == nullptr) {
			back = nuevo;
		}
	}
	tamanio++;
}

void FrontMiddleBackQueue::pushBack(int value)
{
	Nodo* nuevo = new Nodo{ value };
	if (back == nullptr) {
		front = nuevo;
		back = nuevo;
	}
	else {
		back->next = nuevo;
		back = nuevo;
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
		Nodo* rapido = front;
		Nodo* lento = front;
		Nodo* previo = nullptr;
		while (rapido != nullptr && rapido->next != nullptr && rapido->next->next != nullptr) {
			rapido = rapido->next->next;
			previo = lento;
			lento = lento->next;
		}
		int valor = lento->valor;
		if (previo != nullptr) {
			previo->next = lento->next;
		}
		else {
			front = lento->next;
		}
		delete lento;
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
