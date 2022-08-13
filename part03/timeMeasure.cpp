// Copyright 2022

#include <ctime>
using namespace std;

double measure() {
  
  clock_t begin = clock();

  code_to_time();

  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  
  return elapsed_secs;
}
