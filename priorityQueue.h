#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>

using namespace std;

struct Node {
    int value;
    int priority;
};

class PriorityQueue {
private:
    Node* data;
    int size;
    int capacity;

    void resize();
    int findHighest() const;

public:
    PriorityQueue();
    PriorityQueue(const PriorityQueue& other);
    ~PriorityQueue();

    void operator=(const PriorityQueue& other);

    void add(int value, int priority);
    bool get(int& value, int& priority);

    int count(int priority = 0) const;
    bool peek(int& value, int& priority) const;

    int get(int priority, int*& buffer);

    bool exist(int value, int priority = 0) const;

    PriorityQueue operator+(const PriorityQueue& other) const;
    PriorityQueue operator-(const PriorityQueue& other) const;
    PriorityQueue operator&(const PriorityQueue& other) const;

    bool operator==(const PriorityQueue& other) const;
    bool operator!=(const PriorityQueue& other) const { return !(*this == other); }
    bool operator<(const PriorityQueue& other) const;
    bool operator>(const PriorityQueue& other) const { return other < *this; }
    bool operator<=(const PriorityQueue& other) const { return !(*this > other); }
    bool operator>=(const PriorityQueue& other) const { return !(*this < other); }

    friend ostream& operator<<(ostream& os, const PriorityQueue& q);
};

#endif