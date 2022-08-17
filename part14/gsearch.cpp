// Copyright 2022

#include <iostream>
#include <map>
#include <vector>
#include <list>
#include "adjList.h"

// поиск в глубину
void DFS(Graph& gr, int v, bool first) {
   static std::map<int,bool> visited; 
   // первый запуск
   if(first) {
      visited.clear();
      first = false;
   }
   visited[v] = true;
   std::cout << v << " ";

   for (auto i = gr.adj[v].begin(); i != gr.adj[v].end(); ++i)
     if (!visited[*i])
         DFS(gr, *i, false);
}

// поиск в ширину
void BFS(Graph& gr, int s) {

    std::vector<bool> visited;
    visited.resize(gr.vnumber,false);
 
    // создаем очередь BFS
    std::list<int> queue;
 
    // помечаем текущий узел как посещённый
    visited[s] = true;
    queue.push_back(s);
 
    while(!queue.empty()) {
        // извлекаем из очереди и печатаем
        s = queue.front();
        std::cout << s << " ";
        queue.pop_front();

        for (auto adjecent: gr.adj[s]) {
            if (!visited[adjecent]) {
                visited[adjecent] = true;
                queue.push_back(adjecent);
            }
        }
    }
}
