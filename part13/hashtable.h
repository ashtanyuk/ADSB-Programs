// Copyright 2022

#ifndef _HASH_TABLE_
#define _HASH_TABLE_

#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

typedef int TKey;
typedef string TValue;
typedef list<pair<TKey,TValue>> slist;

class HashTable {
private:
   vector<slist> table;
   unsigned capacity;
   unsigned count;
public:
   HashTable(unsigned divisor = 99);
   ~HashTable();
   unsigned hashIntKey(int key); 
   unsigned dataToKey(TValue Data) ;
   TValue search(TKey key) ;
   void insert(TKey key_val,TValue el_value);
   void print();
   void del(TValue element);
   TValue operator[](int key);
};

unsigned HashTable::hashIntKey(int key) {
   return key % capacity;
}

HashTable::HashTable() {
   count=0;
   capacity = 100;
   table.resize(capacity, slist());
}

HashTable::HashTable(unsigned divisor) {
   count=0;
   capacity = divisor;
   table.resize(capacity, slist());
}

HashTable::~HashTable() {
   table.clear();
}

TValue HashTable::search(TKey key)  {
   unsigned pos=hashIntKey(key);
   slist lst = table.at(pos);
   if(lst.size()< 1) //if list hasnt elements
     return (TValue)0;
   for(auto it = lst.begin(); it != lst.end(); ++it)  {
     if(it->first == key) {
       return (it->second); 
     } 
   }
   Insert(key,TValue()); 
   return operator[](key);
}

void HashTable::insert(TKey key_val,TValue el_value) {
   unsigned pos=hashIntKey((int)key_val); 
   pair< TKey,TValue> toInsert(key_val, el_value);
 
   slist& lst = table.at(pos);
   if(!lst.empty()) {
    for(auto it = lst.begin(); it != lst.end(); ++it)  {
       if(it->first == key_val) {
          lst.push_front(toInsert);
          return;
       } 
    }
   }
   table[pos].push_front(toInsert);
   count++;
}

void HashTable::print() const  {
    int NumOfCollision = 0;
    cout<< "Hash table capacity ";
    NumOfCollision += table[i].size() - 1;
  
    for(auto it = table[i].begin(); it != table[i].end();it++)  {
       cout<< "HashTable["<< i<< "]: "<< (it->second)<< endl;
    }
    cout<< "N.Hash collisions: "<< NumOfCollision<< endl;
}

TValue HashTable::operator[](int key) {
    unsigned pos = hashIntKey(key);
    slist& lst = table.at(pos);

    if(lst.size()< 1)
      return (TValue)0;
    for(auto it = lst.begin(); it != lst.end(); ++it)  {
      if(it->first == key){
        return (it->second);
      } 
    }
    insert(key,TValue());
    return operator[](key);
}

#endif
