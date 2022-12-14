// Copyright 2022

#ifndef _SWAP_
#define _SWAP_
template<typename T>
void swap(T *a,T *b) {
    T t = *a;
    *a = *b;
    *b = t;
}
#endif // _SWAP_

template<typename T>
void quickSort(T arr[], int p, int r) {
   int i,j;
   T x;
   i = p;
   j = r;
   x = arr[(i + j) / 2];
   do {
      while(arr[i] < x) i++;
      while(arr[j] > x) j--;
      if(i <= j) {
        swap(&arr[i], &arr[j]);
        i++;
        j--;
      }
    }
    while(i <= j);
    if(j > p)
       quickSort(arr, p, j);
    if(i<r)
       quickSort(arr, i, r);
}

template<typename T>
void shellSort1(T arr[], int size)  {
   int j, d, temp;
   d = size / 2;
   while (d > 0) {
      for (int i = 0; i < size - d; i++) {
         j = i;
         while (j >= 0 && arr[j] > arr[j + d]) {
           temp = arr[j];
           arr[j] = arr[j + d];
           arr[j + d] = temp;
           j--;
         }
      }
      d = d / 2;
    }
}

int increment(long inc[], long size) {
// inc[] массив, в который заносятся инкременты
// size размерность этого массива
 int p1, p2, p3, s;
  
  p1 = p2 = p3 = 1;
  s = -1;
  do {// заполняем массив элементов по формуле Роберта Седжвика
    if (++s % 2) {
      inc[s] = 8*p1 - 6*p2 + 1;
    } else {
      inc[s] = 9*p1 - 9*p3 + 1;
      p2 *= 2;
      p3 *= 2;
    }
    p1 *= 2;
// заполняем массив, пока текущая инкремента хотя бы в 3 раза меньше количества элементов в массиве
  } while(3*inc[s] < size);
  
  return s > 0 ? --s : 0;// возвращаем количество элементов в массиве
}
  
template<class T>
void shellSort2(T a[], long size) {
// inc инкремент, расстояние между элементами сравнения
// i и j стандартные переменные цикла
// seq[40] массив, в котором хранятся инкременты
  long inc, i, j, seq[40];
  int s;//количество элементов в массиве seq[40]
  
  // вычисление последовательности приращений
  s = increment(seq, size);
  while (s >= 0) {
    //извлекаем из массива очередной шаг
    inc = seq[s--];
    for (i = inc; i < size; i++) {
      T temp = a[i];
// сдвигаем элементы до тех пор, пока не дойдем до конца или не упорядочим в нужном порядке
      for (j = i-inc; (j >= 0) && (a[j] > temp); j -= inc)
        a[j+inc] = a[j];
// после всех сдвигов ставим на место j+inc элемент, который находился на i месте
      a[j+inc] = temp;
    }
  }
}

template<typename T>
T* mergeSort(T *up, T *down, unsigned int left, unsigned int right) {
    if (left == right) {
        down[left] = up[left];
        return down;
    }

    unsigned int middle = (left + right) / 2;

    // разделяй и властвуй
    T *lbuf = mergeSort(up, down, left, middle);
    T *rbuf = mergeSort(up, down, middle + 1, right);

    // слияние двух отсортированных половин
    T *target = lbuf == up ? down : up;

    unsigned int lcur = left, rcur = middle + 1;
    for (unsigned int i = left; i <= right; i++) {
        if (lcur <= middle && rcur <= right) {
            if (lbuf[lcur] < rbuf[rcur]) {
                target[i] = lbuf[lcur];
                lcur++;
            }
            else {
                target[i] = rbuf[rcur];
                rcur++;
            }
        }
        else if (lcur <= middle) {
            target[i] = lbuf[lcur];
            lcur++;
        }
        else {
            target[i] = rbuf[rcur];
            rcur++;
        }
    }
    return target;
}

