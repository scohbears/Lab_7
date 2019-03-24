//
// Created by jun26 on 2019-03-22.
//

#include <string>

//using std::string;
using namespace std;
#ifndef NODE
#define NODE
//문제에서 제시한 코드와 똑같이 작성함
class Node {
 public:
  virtual int code() const = 0;
  virtual string symbol() const = 0;
  bool operator<(const Node &node) const {
    return code() < node.code();
  }
};

class Leaf : public Node {
  int _code;
  string _symbol;
 public:
  Leaf(string &symbol, int c) : _code(c), _symbol(symbol) { }
  int code() const override {
    return _code;
  }

  string symbol() const override {
    return _symbol;
  }
};

class Branch : public Node {
  Node *_left;
  Node *_right;
  int _code;
 public:
  Branch(Node *a, Node *b) {
    if(a->code() < b->code()) {
      _left = a;
      _right = b;
    } else {
      _left = b;
      _right = a;
    }
    _code = a->code() + b->code();
  }
  int code() const override {
    return _code;
  }
  string symbol() const override {
    return "";
  }
  Node *left() {
    return _left;
  }
  Node *right() {
    return _right;
  }
};
#endif