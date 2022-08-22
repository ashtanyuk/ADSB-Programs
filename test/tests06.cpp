// Copyright 2022 A.SHT
#include <gtest/gtest.h>
#include <string>
#include "sstack.h"
#include "dstack.h"

TEST(part06, sstack1) {

   SStack<int> stack; 

   ASSERT_TRUE(stack.isEmpty() == true);
}
