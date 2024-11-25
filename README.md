# C++ Containers Implementation

This project implements custom C++ containers that mirror the behavior of the C++ Standard Template Library (STL) containers.

## Containers Implemented

- Vector - Dynamic array container
- Array - Static array container with fixed size
- List - Doubly-linked list
- Queue - FIFO (First-In-First-Out) container adapter
- Stack - LIFO (Last-In-First-Out) container adapter
- Map - Associative container that stores key-value pairs
- Set - Associative container for unique elements
- Multiset - Associative container that allows duplicate elements

## Features

- Modern C++17 implementation
- Header-only library
- Template-based containers
- STL-compatible interfaces
- Move semantics support
- Iterator support

## Container Specifications

### Vector
- Dynamic size array
- Automatic resizing
- Contiguous memory storage
- Random access iterators

### Array
- Fixed-size sequential container
- Direct element access via index
- Constant time complexity for element access
- STL-compatible iterators

### List
- Doubly-linked list implementation
- Constant time insertions and deletions
- Bidirectional iterators
- No random access

### Queue
- FIFO data structure
- Push/pop operations
- Front/back element access
- Size tracking

### Stack
- LIFO data structure
- Push/pop operations
- Top element access
- Size tracking

### Map
- Key-value storage
- Self-balancing tree implementation
- Key-based element access
- Bounds checking

### Set
- Unique sorted elements
- Tree-based implementation
- Fast lookup operations
- No duplicates allowed

### Multiset
- Sorted container allowing duplicates
- Tree-based implementation
- Fast lookup operations
- Range-based operations

## Usage

```cpp
#include "s21_vector.h"
#include "s21_array.h"
#include "s21_list.h"
#include "s21_queue.h"
#include "s21_stack.h"
#include "s21_map.h"
#include "s21_set.h"
#include "s21_multiset.h"

// Create and use containers
s21::vector<int> vec = {1, 2, 3};
s21::array<int, 5> arr = {1, 2, 3, 4, 5};
s21::list<int> list;
s21::queue<int> queue;
s21::stack<int> stack;
s21::map<int, std::string> map;
s21::set<int> set;
s21::multiset<int> mset;
```

## Building and Testing

 1. Clone the repository
 1. Navigate to the src directory
 1. Use make to build the project and run tests

## Requirements

 - C++17 or higher
 - Make
 - GTest for testing
 - GCC or Clang compiler

## License

This project is available under the GNU GPL License.
