# PriorityQueue

Custom `PriorityQueue` implementation in C++ without STL containers, written as part of the *Object-Oriented Programming Technologies* course.

Each element in the queue holds an integer value and an integer priority. Extraction follows priority order — the element with the highest priority is extracted first. Among elements with equal priority, the one added earliest is extracted first (FIFO within a priority level).

## Features

- Add elements with a priority
- Extract the highest-priority element (with removal)
- Peek at the next element without removing it
- Check element existence by value, optionally filtered by priority
- Extract all elements of a given priority into a buffer
- Count all elements, or only those with a given priority
- Operator overloading:
  - `+` — union of two queues (duplicates kept)
  - `-` — difference (elements absent in the other queue, matched by value and priority)
  - `&` — intersection (elements present in both queues, matched by value and priority)
  - `==`, `!=`, `<`, `>`, `<=`, `>=` — comparison by priority group counts
  - `<<` — print queue to console
- Correct copy semantics (copy constructor and assignment operator)
- Console menu for interactive testing

## File structure

```
├── PriorityQueue.h     # Class declaration
├── PriorityQueue.cpp   # Class implementation
└── source.cpp          # Console menu and entry point
```

## Build and run

Requires a C++17-compatible compiler.

**g++**
```bash
g++ source.cpp PriorityQueue.cpp -o priority_queue
./priority_queue
```
