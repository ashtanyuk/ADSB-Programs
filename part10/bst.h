// Copyright 2022-2023

#include <vector>

template<typename T>
class BST {
public:
    struct Node {
        T value;
        int count;
        Node *left;
        Node *right;
    };
private:
    Node* root;
    Node* addNode(Node *, T);
    void  printTree(Node*);
    int   depthTree(Node*);
    int   searchNode(Node*,T);
    void  delTree(Node*);
    Node* delNode(Node*,int);
    int   countTree(Node*);
public:
    BST(const BST&);
				BST(
    ~BST();
    void add(T);
    void print();
    int  depth();
    int  search(T);
    void clear();
    void remove(int);
    int count();
};

BST(const BST& other) : root(nullptr) {
    std::vector<Node*> remain;
    Node* cur = other.root;
    while (cur) {
      add(cur->data);
      if (cur->right) {
        remain.push_back(cur->right);
      }
      if (cur->left) {
        cur = cur->left;
      }
      else if (remain.empty()) {
        break;
      }
      else {
        cur = remain.back();
        remain.pop_back();
      }
    }
}

template<typename T>
int BST<T>::countTree(Node<T>* root) {
	  if(root == nullptr)
				  return 0;
			else 
      return countTree(root->left) + countTree(root->right) + 1;
}

template<typename T>
int BST<T>::count() {
	  return countTree(root);
}

template<typename T>
BST<T>::BST():root(nullptr) {}

template<typename T>
BST<T>::~BST() {
    if(root)
        delTree(root);
}

template<typename T>
typename BST<T>::Node* BST<T>::addNode(Node *root, T value) {
   if(root==nullptr) {
      root=new Node;
      root->value=value;
      root->count=1;
      root->left=root->right=nullptr;
   }
   else if(root->value>value) {
     root->left=addNode(root->left,value);
   }
   else if(root->value<value) {
     root->right=addNode(root->right,value);
   }
   else
    root->count++;
   return root;
}

template<typename T>
void BST<T>::add(T value) {
   root=addNode(root,value);
}

template<typename T>
void BST<T>::printTree(Node* root) {
    if(root==nullptr)
        return;
    printTree(root->left);
    for(int i=0;i<root->count;i++)
        std::cout<<root->value<<" ";
    printTree(root->right);
}

template<typename T>
void BST<T>::print() {
   printTree(root);
}

template<typename T>
int BST<T>::depthTree(Node* root) {
   if(root==nullptr)
     return 0;
   if(root->left==nullptr && root->right==nullptr)
     return 0;
   int left=depthTree(root->left);
   int right=depthTree(root->right);
   if(left>right)
     return left+1;
   else
     return right+1;
}

template<typename T>
int BST<T>::depth() {
    return depthTree(root);
}

template<typename T>
int BST<T>::searchNode(Node* root,T value) {
   if(root==nullptr)
     return 0;
   else if(root->value>value)
     return searchNode(root->left,value);
   else if(root->value<value)
     return searchNode(root->right,value);
   else
     return root->count;
}

template<typename T>
int BST<T>::search(T value) {
    return searchNode(root,value);
}

template<typename T>
void  BST<T>::delTree(Node* root)
{
   if(root==nullptr)
       return;
   else
   {
       delTree(root->left);
       delTree(root->right);
       delete root;
   }
}

template<typename T>
void BST<T>::clear() {
    if(root){
        delTree(root);
        root=nullptr;
    }   
}

template<typename T>
typename BST<T>::Node* BST<T>::delNode(typename BST<T>::Node* root,int value) {
    Node* p,*v;
    // случай 0: поддерево пустое
    if(root==nullptr)
        return root;
    // ищем удаляемый узел либо в левом, либо в правом поддереве
    else if(value<root->value)
        root->left=delNode(root->left,value);
    else if(value>root->value)
        root->right=delNode(root->right,value);  
    else {
        // случай 1,2: у узла есть только один потомок или узел - лист
        p=root;
        if(root->right==nullptr)
            root=root->left;
        else if(root->left==nullptr)
            root=root->right;
        else {
            // случай 3,4: у узла есть 2 потомка
            v=root->left; // будем просматривать левое поддерево
            //  случай 3. У левого потомка есть правый потомок
            if(v->right) {
                // ищем самый большой эл-т в левом поддереве
                while(v->right->right) 
                    v=v->right;
                // меняем найденное значение с корнем
                root->value=v->right->value;
                root->count=v->right->count;
                p=v->right; // этот эл-т мы удалим
                v->right=v->right->left;
            }
            else { // случай 4. У левого потомка удаляемого узла нет правого поддерева (или нет сыновей)            
                root->value=v->value;
                root->count=v->count;
                p=v;
                root->left=root->left->left;
            }
        }
        delete p;
    }
    return root;
}

template<typename T>
void BST<T>::remove(int value) {
   if(root)
     root=delNode(root,value);
}
