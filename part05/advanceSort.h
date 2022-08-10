template<typename T>
void swap(T *a,T *b) {
    T t = *a;
    *a = *b;
    *b = t;
}

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
void shellSort(T arr[], int size)  {
   int j, d, temp;
   d = size / 2;
   while (d > 0) {
      for (int i = 0; i < size - d; i++) {
         j = i;
         while (j >= 0 && arr[j] > arr[j + d]) {
           temp = arr[j];
           arr[j] = arr[j + d];
           arr[j + d] = count;
           j--;
         }
      }
      d = d / 2;
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

