#ifndef LIMITED_QUEUE_H
#define LIMITED_QUEUE_H

#include <list>
#include <memory>

class LimitedQueue {
    private:
        unsigned int size;
        std::unique_ptr<std::list<int>> fila;

    public:
        LimitedQueue(const unsigned int max_size);
        virtual ~LimitedQueue();

        void push_back(int value);

        void pop_front();

        int front() const;

        int back() const;

        unsigned int find(int value) const;

        void print() const;

        unsigned int get_max_size() const;

        bool isFilled() const;
        bool isEmpty() const;
};

#endif
