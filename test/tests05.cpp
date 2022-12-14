// Copyright 2022 A.SHT
#include <gtest/gtest.h>
#include <string>
#include "simpleSort.h"
#include "advanceSort.h"

TEST(part05, unratio1) {
   int arr[] = {5, 8, 1};
   unratioSort(arr, 3);
   ASSERT_TRUE(arr[0] == 1 && arr[1] == 5 && arr[2] == 8 );
}

TEST(part05, unratio2) {
   int arr[]  = {5, 8, 1, 4, 9, 0, 6, 12, 2, 4};
   int arrS[] = {0, 1, 2, 4, 4, 5, 6, 8, 9, 12};

   unratioSort(arr, 10);
  
   for (int i = 0; i < 10; ++i) 
      EXPECT_EQ(arr[i], arrS[i]) << "Arrays differ at index " << i;
}


TEST(part05, insertion1) {
   int arr[] = {5, 8, 1};
   insertionSort(arr, 3);
   ASSERT_TRUE(arr[0] == 1 && arr[1] == 5 && arr[2] == 8 );
}

TEST(part05,  insertion2) {
   int arr[]  = {5, 8, 1, 4, 9, 0, 6, 12, 2, 4};
   int arrS[] = {0, 1, 2, 4, 4, 5, 6, 8, 9, 12};

   insertionSort(arr, 10);
  
   for (int i = 0; i < 10; ++i) 
      EXPECT_EQ(arr[i], arrS[i]) << "Arrays differ at index " << i;
}

TEST(part05,  selection) {
   int arr[]  = {5, 8, 1, 4, 9, 0, 6, 12, 2, 4};
   int arrS[] = {0, 1, 2, 4, 4, 5, 6, 8, 9, 12};

   selectionSort(arr, 10);
  
   for (int i = 0; i < 10; ++i) 
      EXPECT_EQ(arr[i], arrS[i]) << "Arrays differ at index " << i;
}

TEST(part05,  bubble1) {
   int arr[]  = {5, 8, 1, 4, 9, 0, 6, 12, 2, 4};
   int arrS[] = {0, 1, 2, 4, 4, 5, 6, 8, 9, 12};

   bubbleSort1(arr, 10);
  
   for (int i = 0; i < 10; ++i) 
      EXPECT_EQ(arr[i], arrS[i]) << "Arrays differ at index " << i;
}

TEST(part05,  bubble2) {
   int arr[]  = {5, 8, 1, 4, 9, 0, 6, 12, 2, 4};
   int arrS[] = {0, 1, 2, 4, 4, 5, 6, 8, 9, 12};

   bubbleSort2(arr, 10);
  
   for (int i = 0; i < 10; ++i) 
      EXPECT_EQ(arr[i], arrS[i]) << "Arrays differ at index " << i;
}

TEST(part05, quick1) {
   int arr[]  = {5, 8, 1, 4, 9, 0, 6, 12, 2, 4};
   int arrS[] = {0, 1, 2, 4, 4, 5, 6, 8, 9, 12};

   quickSort(arr, 0, 9);
  
   for (int i = 0; i < 10; ++i) 
      EXPECT_EQ(arr[i], arrS[i]) << "Arrays differ at index " << i;
}

TEST(part05, shell1) {
   int arr[]  = {5, 8, 1, 4, 9, 0, 6, 12, 2, 4};
   int arrS[] = {0, 1, 2, 4, 4, 5, 6, 8, 9, 12};

   shellSort1(arr, 10);
  
   for (int i = 0; i < 10; ++i) 
      EXPECT_EQ(arr[i], arrS[i]) << "Arrays differ at index " << i;
}

TEST(part05, shell2) {
   int arr[]  = {5, 8, 1, 4, 9, 0, 6, 12, 2, 4};
   int arrS[] = {0, 1, 2, 4, 4, 5, 6, 8, 9, 12};

   shellSort2(arr, 10);
  
   for (int i = 0; i < 10; ++i) 
      EXPECT_EQ(arr[i], arrS[i]) << "Arrays differ at index " << i;
}
