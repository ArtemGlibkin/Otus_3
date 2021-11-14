#include <gtest/gtest.h>
#include "IPPrint.h"

TEST(IPPrintTest, IntegerTest) {

	ip_printer v;
	int integer = 2130706433;
	short shrt = 0;
	char chr = -1;
	long lng = 8875824491850138409;

	ASSERT_EQ(v.print(integer), std::string("127.0.0.1"));
	ASSERT_EQ(v.print(shrt), std::string("0.0.0.0"));
	ASSERT_EQ(v.print(chr), std::string("255.255.255.255"));
	ASSERT_EQ(v.print(lng), std::string("101.112.131.41"));
}

TEST(IPPrintTest, VectorTest) {

	std::vector<int> test = { 192, 168,23, 1 };
	std::vector<std::string> test2 = { "192", "168" ,"18", "196" };
	ip_printer v;
	ASSERT_EQ(v.print(test), std::string("192.168.23.1"));
	ASSERT_EQ(v.print(test2), std::string("192.168.18.196"));
}

TEST(IPPrintTest, ListTest) {

	std::list<int> test = { 192, 168,23, 1 };
	std::list<std::string> test2 = { "192", "168" ,"18", "196" };
	ip_printer v;
	ASSERT_EQ(v.print(test), std::string("192.168.23.1"));
	ASSERT_EQ(v.print(test2), std::string("192.168.18.196"));
}

TEST(IPPrintTest, TupleTest) {

	std::tuple<int, int, int, int> tuple = std::make_tuple(255, 255, 255, 3);
	std::tuple<std::string, std::string, std::string, std::string> tuple2 = std::make_tuple("5", "5", "3", "2");
	ip_printer v;
	ASSERT_EQ(v.print(tuple), std::string("255.255.255.3"));
	ASSERT_EQ(v.print(tuple2), std::string("5.5.3.2"));
}

TEST(IPPrintTest, StringTest) {
	ip_printer v;
	ASSERT_EQ(v.print(std::string("10.10.41.132")), std::string("10.10.41.132"));
}