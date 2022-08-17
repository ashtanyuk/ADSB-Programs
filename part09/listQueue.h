// Copyright 2022

template<typename T>
class LListQueue {
    struct ITEM {
        T data;
        ITEM * next;
    };
public:
    LListQueue():head(nullptr),tail(nullptr){}
    ~LListQueue();
    void push(const T&);
    T pop();
    void print() const;
private:
    LListQueue::ITEM* create(const T&);
    ITEM *head;
    ITEM *tail;
};

template<typename T>
typename LListQueue<T>::ITEM* LListQueue<T>::create(const T& data) {
   ITEM *item=new ITEM;
   item->data=data;
   item->next=nullptr;
   return item;
}

template<typename T>
LListQueue<T>::~LListQueue() {
    while(head)
      pop();
}
template<typename T>
void LListQueue<T>::push(const T& data) {
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
T LListQueue<T>::pop() {
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
void LListQueue<T>::print() const {
    ITEM *temp=head;
    while(temp) {
        std::cout<<temp->data<<" ";
        temp=temp->next;
    }
    std::cout<<std::endl;
}