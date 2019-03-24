#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include "Node.cpp"
#include "PriorityQueue.cpp"
#include "MorseTable.cpp"
#include "DynamicArray.cpp"

//using std::string;
using namespace std;

DynamicArray<string> encrypt;
PriorityQueue<Node> queue;

string walkDecrypt(Node *node, std::ifstream &stream); //트리를 걸어내려가면서 암호화된 binary -> 문자
void walkEncrypt(Node *node, const string &code); //트리를 걸어내려가면서 encrypt테이블(문자->암호화된 binary) 작성

int main(int argc, char **argv) {

  for(pair<string, string> pair:getMorseTable()) { //모스 부호 표 -> 이진화된 모스부호로 변환
    int code = 0;
    for(char c:pair.second) {
      if(c == '-') {
        code += 0b01;
      } else {
        code += 0b10;
      }
      code <<= 2;
    }
    code >>= 2;
    queue.enqueue(new Leaf(pair.first, code)); //문제에서 요구한대로 queue에 집어넣음
  }

  Node *root;
  while(true) { //queue가 빌때까지 앞의 두개를 꺼내서 branch로 엮는 작업을 반복함(문제에서 요구한 사항 그대로)
    Node *first = queue.dequeue();
    Node *second = queue.dequeue();
    if(second == nullptr) {
      root = first;
      break;
    }
    queue.enqueue(new Branch(first, second));
  }

  walkEncrypt(root, ""); //트리를 걸어내려가면서 encrypt 테이블 작성

  //raw.txt의 내용 읽어서 encrypted.bin이라는 암호화된 파일 생성
  ifstream in("raw.txt");
  ofstream out("encrypt.txt");
  bool first = true;
  while(!in.eof()) {
    char c;
    in.get(c);
    if(!first){
      if(c==' '){ //스페이스일 경우 LS(11), 아닐경우 WS(00)을 각 암호화된 문자 사이에 삽입(문제에서 요구한 조건)
        out<<"11";
        in.get(c);
      }
      else{
        out<<"00";
      }
    }
    c = (char)toupper((int)c);
    string en = encrypt.get((int)c);
    out<<en;
    first = false;
  }
  out.flush();
  out.close();
  in.close();
  cout << "Encrypted file generated! Check the folder " << endl;

  //encrypted.bin의 내용을 읽어서 decrypted.txt라는 복호화된 파일 생성
  ifstream ein("encrypt.txt");
  ofstream fout("decrypt.txt");
  while(!ein.eof()){
    string dec = walkDecrypt(root, ein);
    if(ein.eof()) break;
    fout<<dec;
    //WS또는 LS를 읽어들이는 작업
    char s1, s2;
    ein >> s1 >> s2;
    if(s1=='1'){
      fout<<' ';
    }
  }
  ein.close();
  fout.flush();
  fout.close();
  cout << "Decrypted file generated! Check the folder " << endl;
  return 0;
}

void walkEncrypt(Node *node, const string &code) {
  if(typeid(*node) == typeid(Leaf)) {
    auto leaf = (Leaf *) node;
    encrypt.insert((int)(leaf->symbol()[0]), code);
  } else {
    auto branch = (Branch *) node;
    Node *left = branch->left();
    Node *right = branch->right();
    if(left != nullptr) {
      walkEncrypt(left, code + "0");
    }
    if(right != nullptr) {
      walkEncrypt(right, code + "1");
    }
  }
}

string walkDecrypt(Node *node, std::ifstream &stream) {
  if(typeid(*node) == typeid(Leaf)) {
    return ((Leaf *) node)->symbol();
  } else {
    auto branch = (Branch *) node;
    char next;
    stream >> next;
    if(next == '0') {
      return walkDecrypt(branch->left(), stream);
    } else {
      return walkDecrypt(branch->right(), stream);
    }
  }
}
