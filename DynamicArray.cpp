//
// Created by jun26 on 2019-03-22.
//

#ifndef DA
#define DA

template<typename T>
class DynamicArray { //Dynamic하게 capacity가 늘어나는 배열
  T *array;
  int capacity;
 public:
  DynamicArray(int _capacity) : capacity(_capacity), array(new T[_capacity]) { }
  DynamicArray(): capacity(20), array(new T[20]){ }

  T &get(int index) {
    return array[index];
  }
  void insert(int index, const string &value) {
    if(index >= capacity) {
      int n = capacity;
      while(index>n){
        n*=2;
      }
      resize(n);
    }
    array[index] = value;
  }
  void resize(int to) {
    if(to > capacity) {
      T *old = array;
      array = new T[to];
      for(int i = 0; i < capacity; i++) {
        array[i] = old[i];
      }
      delete[] old;
      capacity = to;
    }
  }
};

#endif
