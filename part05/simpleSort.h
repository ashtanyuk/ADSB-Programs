template<typename T>
void swap(T *a,T *b) {
    T t = *a;
    *a = *b;
    *b = t;
}

template<typename T>
void unratioSort(T arr[], int N) {
   int i, j;
   for(i = 0; i < N; i++)
     for(j = 0; j < N; j++)
       if(arr[i] < arr[j])
          swap(&arr[i], &arr[j]);
}

template<typename T>
void insertionSort(T arr[], int N) {
   int i, j;
   T temp;
   for(i = 1; i < N; i++) {
      j = i;
      temp = arr[i];
      while(j > 0 && temp < arr[j-1]) {
         arr[j] = arr[j-1];
         j--; 
      }
      arr[j] = temp; 
   }
}

template<typename T>
void selectionSort(T arr[], int N) {
   int i,j,index;
   for(i = 0; i < N-1; i++) {
      index = i;
      for(j = i + 1; j < N; j++)
        if(arr[j] < arr[index])
           index = j;
      swap(&arr[i], &arr[index]);
    }
}

template<typename T>
void bubbleSort1(T arr[], int N) {
   int i, j;
   for(i = 0; i < N - 1; i++)
     for(j = N - 1; j > i; j--)
        if(arr[j - 1] > arr[j])
           swap(&arr[j - 1], &arr[j]);
}

template<typename T>
void bubbleSort2(T arr[], int N) {
   int i, j, lastIndex;
   i = N - 1;
   while(i > 0) {
     lastIndex = 0;
     for(j = 0; j < i; j++)
        if(arr[j + 1] < arr[j]) {
           swap(&arr[j + 1], &arr[j]);
           lastIndex = j;
        }
        i = lastIndex;
   }
}