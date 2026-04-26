#include "PriorityQueue.h"

void PriorityQueue::resize() {
    int newCap = capacity * 2;
    Node* newData = new Node[newCap];
    for (int i = 0; i < size; i++)
        newData[i] = data[i];
    delete[] data;
    data = newData;
    capacity = newCap;
}

PriorityQueue::PriorityQueue() {
    size = 0;
    capacity = 4;
    data = new Node[capacity];
}

PriorityQueue::PriorityQueue(const PriorityQueue& other) {
    size = other.size;
    capacity = other.capacity;
    data = new Node[capacity];
    for (int i = 0; i < size; i++)
        data[i] = other.data[i];
}

void PriorityQueue::operator=(const PriorityQueue& other) {
    if (this == &other) return;
    delete[] data;
    size = other.size;
    capacity = other.capacity;
    data = new Node[capacity];
    for (int i = 0; i < size; i++)
        data[i] = other.data[i];
}

PriorityQueue::~PriorityQueue() {
    delete[] data;
}

int PriorityQueue::findHighest() const {
    if (size == 0) return -1;
    int idx = 0;
    for (int i = 1; i < size; i++)
        if (data[i].priority > data[idx].priority)
            idx = i;
    return idx;
}

void PriorityQueue::add(int value, int priority) {
    if (size == capacity) resize();
    data[size].value = value;
    data[size].priority = priority;
    size++;
}

bool PriorityQueue::get(int& value, int& priority) {
    int idx = findHighest();
    if (idx == -1) return false;

    value = data[idx].value;
    priority = data[idx].priority;

    for (int i = idx; i < size - 1; i++)
        data[i] = data[i + 1];

    size--;
    return true;
}

int PriorityQueue::count(int priority) const {
    if (priority == 0) return size;
    int c = 0;
    for (int i = 0; i < size; i++)
        if (data[i].priority == priority)
            c++;
    return c;
}

bool PriorityQueue::peek(int& value, int& priority) const {
    int idx = findHighest();
    if (idx == -1) return false;
    value = data[idx].value;
    priority = data[idx].priority;
    return true;
}

int PriorityQueue::get(int priority, int*& buffer) {
    int cnt = count(priority);
    if (cnt == 0) return 0;

    buffer = new int[cnt];
    int b = 0;

    for (int i = 0; i < size; ) {
        if (data[i].priority == priority) {
            buffer[b++] = data[i].value;
            for (int j = i; j < size - 1; j++)
                data[j] = data[j + 1];
            size--;
        } else {
            i++;
        }
    }
    return cnt;
}

bool PriorityQueue::exist(int value, int priority) const {
    for (int i = 0; i < size; i++)
        if (data[i].value == value &&
            (priority == 0 || data[i].priority == priority))
            return true;
    return false;
}

PriorityQueue PriorityQueue::operator+(const PriorityQueue& other) const {
    PriorityQueue res(*this);
    for (int i = 0; i < other.size; i++)
        res.add(other.data[i].value, other.data[i].priority);
    return res;
}

PriorityQueue PriorityQueue::operator-(const PriorityQueue& other) const {
    PriorityQueue res(*this);
    for (int i = 0; i < other.size; i++) {
        int v = other.data[i].value;
        int p = other.data[i].priority;
        for (int j = 0; j < res.size; ) {
            if (res.data[j].value == v && res.data[j].priority == p) {
                for (int k = j; k < res.size - 1; k++)
                    res.data[k] = res.data[k + 1];
                res.size--;
            } else {
                j++;
            }
        }
    }
    return res;
}

PriorityQueue PriorityQueue::operator&(const PriorityQueue& other) const {
    PriorityQueue res;
    for (int i = 0; i < size; i++)
        if (other.exist(data[i].value, data[i].priority))
            res.add(data[i].value, data[i].priority);
    return res;
}

bool PriorityQueue::operator==(const PriorityQueue& other) const {
    if (size != other.size) return false;

    for (int p = 1000; p >= -1000; p--) {
        int c1 = 0, c2 = 0;
        for (int i = 0; i < size; i++)
            if (data[i].priority == p) c1++;
        for (int i = 0; i < other.size; i++)
            if (other.data[i].priority == p) c2++;
        if (c1 != c2) return false;
    }
    return true;
}

bool PriorityQueue::operator<(const PriorityQueue& other) const {
    for (int p = 1000; p >= -1000; p--) {
        int c1 = 0, c2 = 0;
        for (int i = 0; i < size; i++)
            if (data[i].priority == p) c1++;
        for (int i = 0; i < other.size; i++)
            if (other.data[i].priority == p) c2++;
        if (c1 != c2) return c1 < c2;
    }
    return false;
}

ostream& operator<<(ostream& os, const PriorityQueue& q) {
    os << "[";
    for (int i = 0; i < q.size; i++) {
        os << "(" << q.data[i].value << ", приоритет=" << q.data[i].priority << ")";
        if (i + 1 < q.size) os << ", ";
    }
    os << "]";
    return os;
}