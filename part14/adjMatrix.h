// Copyright 2022

#include <vector>
#include <iostream>

class Graph {
private:
   std::vector<std::vector<int>> matrix; // матрица смежности
   int vnumber;                          // число вершин
public:
   Graph(int vn):vnumber(vn) {
      matrix.resize(vnumber,std::vector<int>(vnumber));
   }
   void display() { // вывод матрицы на экран
      int i, j;
      for(i = 0; i < matrix.size(); i++) {
         for(j = 0; j < matrix[0].size(); j++) {
            std::cout << matrix[i][j] << " ";
         }
      std::cout << std::endl;
     }
   }
   void add_edge(int u, int v) {  //функция добавления ребра в матрицу
      matrix[u][v] = 1;
      matrix[v][u] = 1;
   }
};

