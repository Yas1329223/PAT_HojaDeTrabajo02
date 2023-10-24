#pragma once
class FrontMiddleBackQueue
{
private:
	struct Nodo
	{
		int valor;
		Nodo* next = nullptr;
	};
	Nodo* front;
	Nodo* back;
	int tamanio = 0;
public:
	FrontMiddleBackQueue();

	void pushFront(int value);

	void pushMiddle(int value);

	void pushBack(int value);

	int popFront();

	int popMiddle();

	int popBack();
};
