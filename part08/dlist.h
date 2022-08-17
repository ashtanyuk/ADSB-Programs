// Copyright 2022

#include <cassert>
#include <iostream> 
#include <string>

template<typename T>
class DList {
private:
    struct ITEM {
        T data;
        ITEM * next;
        ITEM * prev;
    };
public:
    DList():head(nullptr),tail(nullptr),current(nullptr){}
    DList(const T&);
    DList(const DList&);
    ~DList();
    void addTail(const T&);
    void addHead(const T&);
    T rmHead();
    T rmTail();
    T getNext();
    void reset();
    void print() const;
    void printReverse() const;
    bool isEmpty() const;
    void insert(const T&, const T&);
    //T remove(int);
private:
    DList::ITEM* create(const T&);
    ITEM *head;
    ITEM *tail;
    ITEM *current;
};

template<typename T>
typename DList<T>::ITEM* DList<T>::create(const T& data) {
   ITEM *item=new ITEM;
   item->data=data;
   item->next=nullptr;
   item->prev=nullptr;
   return item;
}

template<typename T>
DList<T>::DList(const T& data) {
    head=tail=create(data);
    current=nullptr;
}

template<typename T>
DList<T>::DList(const DList& list) {
    try {
       const_cast<DList&>(list).reset();
       while(true) {
          T val = const_cast<DList&>(list).getNext();
          addTail(val);
       }
    }
    catch(std::string& err) {
    } 
    current=nullptr;
}


template<typename T>
DList<T>::~DList() {
    while(head)
        rmHead();
}

template<typename T>
void DList<T>::addTail(const T& data) {
    if(tail && head) {
        tail->next=create(data);
        tail->next->prev=tail;
        tail=tail->next;
    }
    else {
        head=create(data);
        tail=head;
    }
}

template<typename T>
void DList<T>::addHead(const T& data) {
    if(tail && head) {
        ITEM *temp=create(data);
        temp->next=head;
        temp->next->prev=temp;
        head=temp;

    }
    else {
        head=create(data);
        tail=head;
    }
}

template<typename T>
T DList<T>::rmHead() {
    if(head) {
        ITEM *temp=head->next;
        if(temp)
          temp->prev=nullptr;
        T data=head->data;
        delete head;
        head=temp;
        return data;
    }
    else {
        throw std::string("Empty!");
    }
}

template<typename T>
T DList<T>::rmTail() {
    if(head && tail) {
        ITEM *temp=tail->prev;
        if(temp)
          temp->next=nullptr;        
        T data=tail->data;
        delete tail;
        tail=temp;
        return data;
    }
    else {
        throw std::string("Empty!");
    }
}


template<typename T>
bool DList<T>::isEmpty() const {
    return !head;
}

template<typename T>
T DList<T>::getNext() {
    if(head && tail) {
        if(!current)
            current=head;
        else if(current->next)
            current=current->next;
        else
            throw std::string("The end!");
        return current->data;
    }
    else {
        throw std::string("Empty!");
    }
}

template<typename T>
void DList<T>::reset() {
    current=nullptr;
}

template<typename T>
void DList<T>::print() const {
    ITEM *temp=head;
    while(temp) {
        std::cout<<temp->data<<" ";
        temp=temp->next;
    }
    std::cout<<std::endl;
}

template<typename T>
void DList<T>::insert(const T& data, const T& value) {
	ITEM * temp = head;
	ITEM * item = create(value);
	while(temp && temp->data != data)
		temp=temp->next;
	
	if(!temp && head) { // вставка в конец
		tail->next = item;
		tail->next->prev=tail;
		tail=item;
	}
	else if(!temp && !head) {// вставка в пустой список
		head=tail=item;
	}
	else if(!temp->prev) { // вставка в начало
	    temp->prev=item;
	    item->next=temp;
	    head=item;
	}
	else { // вставка в середину
	    temp->prev->next=item;
		item->prev=temp->prev;
		item->next=temp;
		temp->prev=item;		
	}
}

template<typename T>
void DList<T>::printReverse() const {
    ITEM *temp=tail;
    while(temp) {
        std::cout<<temp->data<<" ";
        temp=temp->prev;
    }
    std::cout<<std::endl;
}