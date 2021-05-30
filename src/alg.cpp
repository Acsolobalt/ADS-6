// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string>tree;
char changeSize = 'a' - 'A';
std::string keyword = "";
std::ifstream file(filename);
if (!file) {
std::cout << "File error!" << std::endl;
return;
}
while (!file.eof()) {
char ch = file.get();
if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z') {
if (ch >= 'A' && ch <= 'Z') {
ch += changeSize;
}
keyword += ch;
} else {
if (keyword != "") {
tree.add(keyword);
keyword = "";
}
}
}
file.close();
return tree;
}
