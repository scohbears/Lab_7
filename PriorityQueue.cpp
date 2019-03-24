// Priority Queue Implementation

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <array>
#include <ctime>
using namespace std;

#ifndef PQ
#define PQ
template<typename T>
struct Greater {
  bool operator()(T &first, T &second) {
    return first < second;
  }
};
template<typename T>
class QueueInterface {
 public:
  virtual bool isempty() = 0;
  virtual void enqueue(T* newEntry) = 0;
  virtual T* dequeue() = 0;
};

template<typename T>
class PriorityQueue : QueueInterface<T> {
  struct node {
    T* data;
    node *link;
    node(T* t) {
      data = t;
    }
  };
  node *front;
  Greater<T> greater;
 public:
  PriorityQueue() {
    front = NULL;
  }
  bool isempty() { return front == NULL; }
  void enqueue(T* data) {
    node *tmp = new node(data);
    if(front == NULL || greater(*tmp->data, *front->data)) {
      tmp->link = front;
      front = tmp;
    } else {
      node *rover = front;
      while(rover->link != NULL && greater(*rover->link->data, *tmp->data))
        rover = rover->link;
      tmp->link = rover->link;
      rover->link = tmp;

    }
  }
  T* dequeue() {
    node *rover;
    if(front == NULL){
      return NULL;
    }
    else {
      rover = front;
      front = front->link;
      T* data = rover->data;
      free(rover);
      return data;
    }
  }
};

#endif