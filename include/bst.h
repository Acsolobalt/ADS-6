// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template < typename T >
class BST
{
public:
struct Node
{
T value;
int count;
Node * left;
Node * right;
unsigned char height;
Node(T k) : value(k), left(nullptr), right(nullptr), height(1), count(1) {}
};
private:
Node * root;
int depthTree(Node * root) {
if (root == nullptr)
return 0;
else {
lh = depthTree(root->left);
rh = depthTree(root->right);
return (lh > rh ? lh : rh) + 1;
}
}
int searchNode(Node * root, T value) {
if (root == nullptr)
return 0;
else if (root->value == value)
return count;
else if (value < root−>value)
return searchNode(root->left, value);
else
return searchNode(root->right, value);
}
unsigned char height(Node * p) { // селектор высоты
return p ? p->height :0;
}
int bfactor(Node * p) { // вычисление баланса узла
return height(p->right) - height(p->left);
}
void fixheight(Node * p) { // установка поля высоты узла
unsigned char hl = height(p->left);
unsigned char hr = height(p->right);
p->height = (hl > hr ? hl : hr) + 1;
}
Node * rotateright(Node * p) { // правый поворот вокруг p
Node * q = p->left;
p->left = q->right;
q->right = p;
fixheight(p);
fixheight(q);
return q;
}
Node * rotateleft(Node * q) { // левый поворот вокруг q
Node* p = q->right;
q->right = p->left;
p->left = q;
fixheight(q);
fixheight(p);
return p;
}	
Node * balance(Node * p) { // балансировка узла p
fixheight(p);
if (bfactor(p) == 2)
{
if (bfactor(p->right) < 0)
p->right = rotateright(p->right);
return rotateleft(p);
}
if (bfactor(p) == −2)
{
if (bfactor(p->left) > 0)
p->left = rotateleft(p->left);
return rotateright(p);
}
return p; // балансировка не нужна
}	
Node * insert(Node * p, T k) { // вставка ключа k в дерево с корнем p
if (!p) return new Node(k);
if (k <p−>key)
p->left = insert(p->left, k);
else
p->right = insert(p->right, k);
return balance(p);
}
public:
BST() : root(nullptr) {}
~BST() {
if (root)
delTree(root);
}
void add(T value) {
root = insert(root, value);
}
int depth() {
return depthTree(root);
}
int search(T value) {
return searchNode(root, value);
}
};

#endif  // INCLUDE_BST_H_
