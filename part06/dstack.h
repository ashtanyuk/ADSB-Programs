// Copyright 2022

template<typename T>
class DStack {
   private:
     T *arr;
     int size;
     int top;
     void resize(int nsize) {
        T *temp=new T[nsize];
        for(int i=0;i<size;i++)
          temp[i]=arr[i];
        delete[]arr;
        arr=temp;
        size=nsize;
     }
   public:
     DStack(int size):top(-1) { 
       this->size=size;
       arr=new T[size];
     }
     ~DSize() {
       delete[]arr;
     }
     bool isEmpty() const {
        return top==-1;
     }
     T get() const { 
        return arr[top];
     }
     void pop() {
        if(top>=0)
          top--;
     }
     void push(T item) {
       if(top==size-1)
         resize(2*size);
       arr[++top]=item;
     }
};
