// Copyright 2022

#include <list>
#include <iostream>

class Graph {
private:
   std::map<int, std::list<int>> adj; // список смежности
   int vnumber; // число вершин
public:
   Graph(int vn):vnumber(vn) {}
   void display() {
      for(auto& [key, value] : adj) { // C++17!
         std::cout << key << " - ";
         for(auto& i: value) {
            std::cout << i << " ";
         }
         std::cout << std::endl;
      }
  }
  // функция добавления ребра в матрицу
  void add_edge(int u, int v) {  
     adj[u].push_back(v);
     adj[v].push_back(u);
  }
};