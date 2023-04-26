// Copyright 2022-2023 A.SHT
#include <gtest/gtest.h>
#include <string>
#include "bst.h"

TEST(part10, tree_1) {

    BST<int> tree; 
    int count = tree.count();
    ASSERT_EQ(count, 0);
}
