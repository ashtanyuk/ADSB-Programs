// Copyright 2022 A.SHT
#include <gtest/gtest.h>
#include <string>
#include "simpleSort.h"

TEST(part05, unratio1) {
	
	int arr[] = {5, 8, 1};
	unratioSort(arr, 3);
	ASSERT_TRUE(arr[0] == 1 && arr[1] == 5 && arr[2] == 8 );
}

