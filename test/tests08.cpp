// Copyright 2022 A.SHT
#include <gtest/gtest.h>
#include <string>
#include "slist.h"
#include "dlist.h"

TEST(part08, slist_print_1) {

   SList<int> list; 
   int count = list.print();
   ASSERT_EQ(count, 0);
}

TEST(part08, slist_print_2) {

    SList<int> list; 
				list.addTail(5);
				list.addTail(6);
				int count = list.print();
    ASSERT_EQ(count, 2);
}

