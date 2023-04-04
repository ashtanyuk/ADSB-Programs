// Copyright 2022
// Single Linked List
//

#include <cassert>
#include <string>
#include <iostream>
 
template<typename T>
class SList {
    struct ITEM {
        T data;
        ITEM * next;
    };
public:
    SList():head(nullptr),tail(nullptr){}
    SList(const T&);
    SList(const SList&);
    ~SList();
    void addTail(const T&);
    void addHead(const T&);
    T rmHead();
    T rmTail();
    int print() const;
private:
    SList::ITEM* create(const T&);
    ITEM *head;
    ITEM *tail;
};

template<typename T>
SList<T>::SList(const SList& list) {
   // list is empty
   if(list.head == nullptr)
     head = tail = nullptr;
   else {
     head = create(list.head->data);
     ITEM* templist = list.head->next;
     ITEM* temp = head;
     while(templist) {
        temp -> next = create(templist->data);
        temp = temp -> next;
        templist = templist -> next;
     }
     tail = temp; 
   }
}

template<typename T>
SList<T>::SList(const T& data) {
    head=create(data);
    tail=head;
}

template<typename T>
SList<T>::~SList() {
    while(head)
        rmHead();
}

template<typename T>
typename SList<T>::ITEM* SList<T>::create(const T& data) {
   ITEM *item=new ITEM;
   item->data=data;
   item->next=nullptr;
   return item;
}

template<typename T>
void SList<T>::addTail(const T& data) {
    if(tail && head) {
        tail->next=create(data);
        tail=tail->next;
    }
    else {
        head=create(data);
        tail=head;
    }
}

template<typename T>
void SList<T>::addHead(const T& data) {
    if(tail && head) {
        ITEM *temp=create(data);
        temp->next=head;
        head=temp;
    }
    else {
        head=create(data);
        tail=head;
    }
}

template<typename T>
T SList<T>::rmHead() {
    if(head) {
        ITEM *temp=head->next;
        T data=head->data;
        delete head;
        head=temp;
        return data;
    }
    else 
       throw std::string("Empty!");
}

template<typename T>
T SList<T>::rmTail() {
    // list has one item
    if(head && head == tail) {
       T data = head -> data;
       delete head;
       head = tail = nullptr;
       return data;
    } 
    // list has 2 or more items
    else if(head) {
       ITEM *temp=head;
       while(temp->next != tail)
          temp = temp -> next;
       T data = tail -> data;
       delete tail;
       temp -> next = nullptr;
       return data;
    }
    else 
       throw std::string("Empty!");
}


template<typename T>
int SList<T>::print() const {
    ITEM *temp=head;
    int count = 0;
    while(temp) {
        std::cout<<temp->data<<" ";
        ++count;
        temp=temp->next;
    }
    std::cout<<std::endl;
    return count;
}

