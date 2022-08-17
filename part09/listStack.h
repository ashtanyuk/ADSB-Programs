// Copyright 2022

#include <cassert>
 
template<typename T>
class LListStack {
    struct ITEM {
        T data;
        ITEM * next;
    };
public:
    LListStack():head(nullptr){}
    ~LListStack();
    void push(const T&);
    T pop();
    void print() const;
private:
    LListStack::ITEM* create(const T&);
    ITEM *head;
};

template<typename T>
LListStack<T>::~LListStack() {
    while(head)
        pop();
}

template<typename T>
typename LListStack<T>::ITEM* LListStack<T>::create(const T& data) {
   ITEM *item=new ITEM;
   item->data=data;
   item->next=nullptr;
   return item;
}

template<typename T>
void LListStack<T>::push(const T& data) {
    if(head) {
        ITEM *temp=create(data);
        temp->next=head;
        head=temp;
    }
    else {
        head=create(data);
    }
}

template<typename T>
T LListStack<T>::pop() {
    if(head) {
        ITEM *temp=head->next;
        T data=head->data;
        delete head;
        head=temp;
        return data;
    }
    else {
        return (T)0;
    }
}

template<typename T>
void LListStack<T>::print() const {
    ITEM *temp=head;
    while(temp) {
        std::cout<<temp->data<<" ";
        temp=temp->next;
    }
    std::cout<<std::endl;
}

