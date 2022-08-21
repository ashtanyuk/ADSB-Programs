// Copyright 2022 A.SHT
#include <gtest/gtest.h>
#include <string>
#include "part03.h"

TEST(part03, search1) {
	const char * source = "00000000111111000000000000";
	const char * str = "111";
	ASSERT_TRUE(strSearch(source, str) == 1);
}

TEST(part03, search2) {
	const char * source = "00000000111111000000000000";
	const char * str = "222";
	ASSERT_TRUE(strSearch(source, str) == 0);
}
