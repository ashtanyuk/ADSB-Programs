// Copyright 2022 A.SHT

#include <math.h>

static double delta = 0.00000001;

static double average(double x, double y) {
      return (x + y) / 2.0;
}
static bool good(double guess, double x) {
      return abs(guess * guess - x) < delta;
}
static double improve(double guess, double x) {
      return average(guess, x / guess);
}
static double iter(double guess, double x) {
   if(good(guess, x))
	  return guess;
   else
	  return iter(improve(guess, x), x);
}
double sqrtCalc(double arg) {
      return iter(1.0, arg);
}

