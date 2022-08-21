// Copyright 2022

#include <cassert>
 
template<typename T>
class TQueue
{
private:    
    T *arr;          
	int size;        
    int begin;       
    int end;         
    int count;       
public:
    TQueue(int =100);          
    ~TQueue();                 
 
    void push(const T &); 
    T pop();              
    T get() const;        
    bool isEmpty() const; 
    bool isFull() const;  
};

template<typename T>
TQueue<T>::TQueue(int sizeQueue) :
    size(sizeQueue), 
    begin(0), end(0), count(0) {
    arr = new T[size + 1];
}

template<typename T>
TQueue<T>::~TQueue() {
    delete [] arr;
}

template<typename T>
void TQueue<T>::push(const T & item) {
    assert( count < size );
    arr[end++] = item;
    count++;
    if (end > size)
        end -= size + 1; 
}

template<typename T>
T TQueue<T>::pop() {
    assert( count > 0 );
    T item = arr[begin++];
    count--;
    if (begin > size)
        begin -= size + 1; 
    return item;
}

template<typename T>
T TQueue<T>::get() const {
    assert( count > 0 );
    return arr[begin];
}

template<typename T>
bool TQueue<T>::isEmpty() const {
  return count==0;
}

template<typename T>
bool TQueue<T>::isFull() const {
  return count==size;
}
