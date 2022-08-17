// Copyright 2022

#include <iostream>

template<typename T>
struct NODE { // структура для представления узлов дерева
   T key;                    // ключ узла
   unsigned char height;     // высота поддерева
   NODE* left;
   NODE* right;
   NODE(T k):key(k),left(nullptr),right(nullptr),height(1) {} // конструктор
};
  
template<typename T>
class AVLTree {
private:
   unsigned char height(NODE<T>* p);  // селектор высоты
   int  bfactor(NODE<T>* p);          // вычисление баланса узла
   void fixheight(NODE<T>* p);        // установка поля высоты узла

   NODE<T>* rotateright(NODE<T>* p);  // правый поворот вокруг p
   NODE<T>* rotateleft(NODE<T>* q);   // левый поворот вокруг q

   NODE<T>* balance(NODE<T>* p);      // балансировка узла p
   NODE<T>* insert(NODE<T>* p, T k);  // вставка ключа k в дерево с корнем p
   void  print_dfs(NODE<T> *p, int level); // печать структуры дерева
public:
  AVLTree():root(nullptr){};
  void insert(T k);
  void print();
private:
   NODE<T>* root;
};

template<typename T>
unsigned char AVLTree<T>::height(NODE<T>* p) {
  return p?p->height:0;
}

template<typename T>
int AVLTree<T>::bfactor(NODE<T>* p) {
  return height(p->right)-height(p->left);
}

template<typename T>
void AVLTree<T>::fixheight(NODE<T>* p) {
  unsigned char hl = height(p->left);
  unsigned char hr = height(p->right);
  p->height = (hl>hr?hl:hr)+1;
} 

template<typename T>
NODE<T>* AVLTree<T>::rotateright(NODE<T>* p) {
  NODE<T>* q = p->left;
  p->left = q->right;
  q->right = p;
  fixheight(p);
  fixheight(q);
  return q;
}

template<typename T>
NODE<T>* AVLTree<T>::rotateleft(NODE<T>* q) {
  NODE<T>* p = q->right;
  q->right = p->left;
  p->left = q;
  fixheight(q);
  fixheight(p);
  return p;
} 

template<typename T>
NODE<T>* AVLTree<T>::balance(NODE<T>* p) {
  fixheight(p);
  if( bfactor(p)==2 ) {
     if( bfactor(p->right) < 0 )
         p->right = rotateright(p->right);
     return rotateleft(p);
  }
  if( bfactor(p)==-2 )  {
     if( bfactor(p->left) > 0  )
         p->left = rotateleft(p->left);
     return rotateright(p);
  }
  return p; // балансировка не нужна
}

template<typename T>
NODE<T>* AVLTree<T>::insert(NODE<T>* p, T k)
{
  if( !p ) return new NODE<T>(k);
  if( k<p->key )
     p->left = insert(p->left,k);
  else
     p->right = insert(p->right,k);
  return balance(p);
}

template<typename T>
void AVLTree<T>::insert(T k) {
  root=insert(root,k);
}
