#include "Ejercicio04.h"
#include <deque>

FrontMiddleBackQueue::FrontMiddleBackQueue()
{
}

void FrontMiddleBackQueue::pushFront(int value)
{
    queue.push_front(value);
}

void FrontMiddleBackQueue::pushMiddle(int value)
{
    int middle = queue.size() / 2;
    queue.insert(queue.begin() + middle, value);
}

void FrontMiddleBackQueue::pushBack(int value) 
{
    queue.push_back(value);
}

int FrontMiddleBackQueue::popFront()
{
    if (queue.empty()) 
    {
        return -1;
    }

    int front = queue.front();
    queue.pop_front();
    return front;
}

int FrontMiddleBackQueue::popMiddle() 
{
    if (queue.empty())
    {
        return -1;
    }

    int middle = queue.size() / 2;
    int value = queue[middle];
    queue.erase(queue.begin() + middle);
    return value;
}

int FrontMiddleBackQueue::popBack()
{
    if (queue.empty()) 
    {
        return -1;
    }

    int back = queue.back();
    queue.pop_back();
    return back;
}

