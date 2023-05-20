#include <iostream>
#include <list>

#include "./LimitedQueue.hpp"

#include "../Exceptions/Exceptions.hpp"

LimitedQueue::LimitedQueue(const unsigned int max_size) :
    fila(new std::list<int>()) {
    if(max_size <= 0) {
        throw Exceptions::InvalidSizeException();
    }

    this->size = max_size;
}

LimitedQueue::~LimitedQueue() {}

void LimitedQueue::push_back(int value) {
    if(isFilled()) {
        throw Exceptions::QueueFullException();
    }

    fila->push_back(value);
    return;
}

void LimitedQueue::pop_front() {
    if(isEmpty()) {
        throw Exceptions::QueueEmptyException();
    }

    fila->pop_front();
    return;
}

int LimitedQueue::front() const {
    if(isEmpty()) {
        throw Exceptions::QueueEmptyException();
    }

    return fila->front();
}

int LimitedQueue::back() const {
    if(isEmpty()) {
        throw Exceptions::QueueEmptyException();
    }

    return fila->back();
}

unsigned int LimitedQueue::find(int value) const {
    if(isEmpty()) {
        throw Exceptions::QueueEmptyException();
    }

    unsigned int position = 0;
    for(int listValue : *fila) {
        if(listValue == value) {
            return position;
        }
        position++;
    }

    throw Exceptions::ItemNotFoundException();
    return 0;
}

void LimitedQueue::print() const {
    if(isEmpty()) {
        throw Exceptions::QueueEmptyException();
    }

    for(int value : *fila) {
        std::cout << value << "\n";
    }

    return;
}

unsigned int LimitedQueue::get_max_size() const {
    return this->size;
}

bool LimitedQueue::isFilled() const {
    return fila->size() >= this->get_max_size() ;
}

bool LimitedQueue::isEmpty() const {
    return fila->size() <= 0;
}
