// Copyright 2022 A.SHT
#include <gtest/gtest.h>
#include <string>
#include "slist.h"
#include "dlist.h"

TEST(part08, slist_empty_1) {

   SList<int> list; 
    int count = list.count();
    ASSERT_EQ(count, 0);
}
TEST(part08, slist_add_rem_1) {

    SList<int> list; 
    list.addTail(5);
    list.addTail(6);
    list.rmHead();
    list.rmHead();
    int count = list.count();
    ASSERT_EQ(count, 0);
}

TEST(part08, slist_add_rem_2) {

    SList<int> list; 
    list.addTail(5);
    list.addTail(6);
    list.rmTail();
    list.rmTail();
    int count = list.count();
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
    int count = list.count();
    ASSERT_EQ(count, 0);
}

TEST(part08, slist_throw_1) {
	
    SList<int> list;
    try {
        list.rmHead();
        FAIL() << "Expected std::string";
    }
    catch(std::string const & err) {
        EXPECT_EQ(err,std::string("Empty!"));
    }
    catch(...) {
        FAIL() << "Expected std::string";
    }
}
TEST(part08, slist_throw_2) {
	
    SList<int> list;
				list.addTail(5);
    try {
        list.rmHead();
								list.rmTail();
        FAIL() << "Expected std::string";
    }
    catch(std::string const & err) {
        EXPECT_EQ(err,std::string("Empty!"));
    }
    catch(...) {
        FAIL() << "Expected std::string";
    }
}

TEST(part08, slist_copy_1) {
   
   SList<int> list1;
   list1.addTail(5);
   list1.addTail(6);
   list1.addTail(7);
   list1.addTail(8);
   SList<int> list2{list1};
   int count = list2.count();
   ASSERT_EQ(count, 4);
}

TEST(part08, slist_add_many) {
   
   SList<int> list;
			
			for(int i = 0; i < 100000; i++) 
      list.addTail(i);

   int count = list.count();
   ASSERT_EQ(count, 100000);
}

TEST(part08, dlist_empty) {
   
   DList<int> list;
			

   bool empty = list.isEmpty();
   ASSERT_EQ(empty, true);
}

TEST(part08, dlist_one) {
   
   DList<int> list(5);

   int cnt = list.count();
   ASSERT_EQ(cnt, 1);
}

TEST(part08, dlist_add_rm_1) {
   
   DList<int> list;
			list.addTail(1);
   list.rmTail(); 			
			
   bool empty = list.isEmpty();
   ASSERT_EQ(empty, true);
}

TEST(part08, dlist_add_rm_2) {
   
   DList<int> list;
			list.addHead(1);
   list.rmHead(); 			
			
   bool empty = list.isEmpty();
   ASSERT_EQ(empty, true);
}

TEST(part08, dlist_add_rm_3) {
   
   DList<int> list;
			list.addHead(1);
   list.rmTail(); 			
			
   bool empty = list.isEmpty();
   ASSERT_EQ(empty, true);
}

TEST(part08, dlist_add_rm_4) {
   
   DList<int> list;
			list.addTail(1);
   list.rmHead(); 
			
   bool empty = list.isEmpty();
   ASSERT_EQ(empty, true);
}

TEST(part08, dlist_add_rm_5) {
   
   DList<int> list;
			list.addTail(1);
			list.addHead(2);
   list.rmTail(); 
			
   int cnt = list.count();
   ASSERT_EQ(cnt, 1);
}

TEST(part08, dlist_add_rm_6) {
   
   DList<int> list;
			list.addHead(2);
			list.addTail(1);
   list.rmTail(); 
			
   int cnt = list.count();
   ASSERT_EQ(cnt, 1);
}

TEST(part08, dlist_add_rm_7) {
   
   DList<int> list;
			list.addHead(2);
			list.addTail(1);
   list.rmHead(); 
			
   int cnt = list.count();
   ASSERT_EQ(cnt, 1);
}

TEST(part08, dlist_add_rm_8) {
   
   DList<int> list;
			list.addTail(1);
			list.addTail(2);
   list.rmHead(); 
			list.rmTail();
			
   bool empty = list.isEmpty();
   ASSERT_EQ(empty, true);
}

TEST(part08, dlist_add_many_1) {
   
   DList<int> list;
			
			for(int i = 0; i < 10000; i++)
			   list.addTail(i);
			
   int cnt = list.count();
   ASSERT_EQ(cnt, 10000);
}

TEST(part08, dlist_add_1) {
   
   DList<int> list(200);
			
   int cnt = list.count();
   ASSERT_EQ(cnt, 1);
}

TEST(part08, dlist_throw_1) {
	
    DList<int> list;
				list.addTail(5);
    try {
        list.rmHead();
								list.rmTail();
        FAIL() << "Expected std::string";
    }
    catch(std::string const & err) {
        EXPECT_EQ(err,std::string("Empty!"));
    }
    catch(...) {
        FAIL() << "Expected std::string";
    }
}
