// Copyright 2022 A.SHT
#include <gtest/gtest.h>
#include <string>
#include "queue.h"

TEST(part07, queue1) {

   TQueue<int> q; 

   ASSERT_TRUE(q.isEmpty() == true);
}

TEST(part07, sstack2) {

   TQueue<int> q(5); 
			q.push(1);
			q.push(2);
			q.push(3);
			q.push(4);
			q.push(5);

   ASSERT_TRUE(q.isFull() == true);
}

