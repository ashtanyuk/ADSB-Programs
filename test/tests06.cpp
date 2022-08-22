// Copyright 2022 A.SHT
#include <gtest/gtest.h>
#include <string>
#include "sstack.h"
#include "dstack.h"

TEST(part06, sstack1) {

   SStack<int> stack; 

   ASSERT_TRUE(stack.isEmpty() == true);
}

TEST(part06, sstack2) {

   SStack<int, 5> stack; 
			stack.push(1);
			stack.push(2);
			stack.push(3);
			stack.push(4);
			stack.push(5);

   ASSERT_TRUE(stack.isFull() == true);
}

