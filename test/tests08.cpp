// Copyright 2022 A.SHT
#include <gtest/gtest.h>
#include <string>
#include "slist.h"
#include "dlist.h"

TEST(part08, slist_empty_1) {

   SList<int> list; 
    int count = list.print();
    ASSERT_EQ(count, 0);
}

TEST(part08, slist_addTail_1) {

    SList<int> list; 
    list.addTail(5);
    list.addTail(6);
    int count = list.print();
    ASSERT_EQ(count, 2);
}

TEST(part08, slist_empty_2) {

    SList<int> list; 
    list.addTail(5);
    list.rmTail();
    int count = list.print();
    ASSERT_EQ(count, 0);
}

TEST(part08, slist_throw_1) {
	
    SList<int> list;
    try {
        list.rmHead();
        FAIL() << "Expected std::string";
    }
    catch(std::string const & err) {
        EXPECT_STREQ(err,std::string("empty!"));
    }
    catch(...) {
        FAIL() << "Expected std::string";
    }
}