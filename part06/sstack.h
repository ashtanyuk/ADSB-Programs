// Copyright 2022

template<typename T, int size = 100>
class TStack {
   private:
     T arr[size];
     int top;
   public:
     TStack():top(-1) { }
     T get() const { 
        return arr[top];
     }
     bool isEmpty() const {
        return top==-1;
     }
     bool isFull() const {
        return top==size-1;
     }
     void pop() {
        if(top>=0)
          top--;
     }
     void push(T item) {
       if(top<size-1)
         arr[++top]=item;
     }
};
