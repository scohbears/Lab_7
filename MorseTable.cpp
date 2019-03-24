//
// Created by jun26 on 2019-03-22.
//

#include <map>
using namespace std;

#ifndef MT
#define MT
map<string, string> getMorseTable(){ //모스 부호 테이블을 반환
  map<string, string> morse;
  morse["A"] = ".-";
  morse["B"] = "-...";
  morse["C"] = "-.-.";
  morse["D"] = "-..";
  morse["E"] = ".";
  morse["F"] = "..-.";
  morse["G"] = "--.";
  morse["H"] = "....";
  morse["I"] = "..";
  morse["J"] = ".---";
  morse["K"] = "-.-";
  morse["L"] = ".-..";
  morse["M"] = "--";
  morse["N"] = "-.";
  morse["O"] = "---";
  morse["P"] = ".--.";
  morse["Q"] = "--.-";
  morse["R"] = ".-.";
  morse["S"] = "...";
  morse["T"] = "-";
  morse["U"] = "..-";
  morse["V"] = "...-";
  morse["W"] = ".--";
  morse["X"] = "-..-";
  morse["Y"] = "-.--";
  morse["Z"] = "--..";
//  morse["Ä"] = ".-.-";
//  morse["Ö"] = "---.";
//  morse["Ü"] = "..--";
  //ch는 글자를 못 찾겠음.
  morse["0"] = "-----";
  morse["1"] = ".----";
  morse["2"] = "..---";
  morse["3"] = "...--";
  morse["4"] = "....-";
  morse["5"] = ".....";
  morse["6"] = "-....";
  morse["7"] = "--...";
  morse["8"] = "---..";
  morse["9"] = "----.";
  morse["."] = ".-.-.-";
  morse[","] = "--..--";
  morse["?"] = "..--..";
  morse["!"] = "..--.";
  morse[":"] = "---...";
  morse["\""] = ".-..-.";
  morse["'"] = ".----.";
  morse["="] = "-...-";
  return morse;
}

#endif