// Copyright 2022

#include <cassert>
 
template<typename T>
class SList
{
    struct ITEM
    {
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
    void print() const;
private:
    SList::ITEM* create(const T&);
    ITEM *head;
    ITEM *tail;
};

template<typename T>
SList<T>::SList(const T& data)
{
    head=create(data);
    tail=head;
}
template<typename T>
SList<T>::~SList()
{
    while(head)
        rmHead();
}

template<typename T>
typename SList<T>::ITEM* SList<T>::create(const T& data)
{
   ITEM *item=new ITEM;
   item->data=data;
   item->next=nullptr;
   return item;
}

template<typename T>
void SList<T>::addTail(const T& data)
{
    if(tail && head)
    {
        tail->next=create(data);
        tail=tail->next;
    }
    else
    {
        head=create(data);
        tail=head;
    }
}

template<typename T>
void SList<T>::addHead(const T& data)
{
    if(tail && head)
    {
        ITEM *temp=create(data);
        temp->next=head;
        head=temp;
    }
    else
    {
        head=create(data);
        tail=head;
    }
}

template<typename T>
T SList<T>::rmHead()
{
    if(head)
    {
        ITEM *temp=head->next;
        T data=head->data;
        delete head;
        head=temp;
        return data;
    }
    else
    {
        return (T)0;
    }
}

template<typename T>
void SList<T>::print() const
{
    ITEM *temp=head;
    while(temp)
    {
        std::cout<<temp->data<<" ";
        temp=temp->next;
    }
    std::cout<<std::endl;
}

