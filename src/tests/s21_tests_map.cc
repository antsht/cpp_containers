#include <cstddef>
#include <iostream>
#include <limits>
#include <map>

#include "s21_tests.h"

TEST(Map, BaseConstructor1) {
  std::map<int, int> map_std;
  s21::map<int, int> map_s21;

  EXPECT_EQ(map_std.empty(), map_s21.empty());
}

TEST(Map, InitializerConstructor1) {
  std::map<int, int> map_std{{1, 2}, {3, 4}, {5, 6}};
  s21::map<int, int> map_s21{{1, 2}, {3, 4}, {5, 6}};

  EXPECT_EQ(map_std.size(), map_s21.size());
}

TEST(Map, CopyConstructor1) {
  s21::map<int, int> map_s21_src{{1, 2}, {3, 4}, {5, 6}};
  s21::map<int, int> map_s21_dst(map_s21_src);

  EXPECT_EQ(map_s21_src.size(), map_s21_dst.size());
  EXPECT_FALSE(map_s21_src.empty());
  EXPECT_FALSE(map_s21_dst.empty());
}

TEST(Map, MoveConstructor1) {
  s21::map<int, int> map_s21_src{{1, 2}, {3, 4}, {5, 6}};
  s21::map<int, int> map_s21_dst(std::move(map_s21_src));

  EXPECT_NE(map_s21_src.size(), map_s21_dst.size());
  EXPECT_TRUE(map_s21_src.empty());
  EXPECT_FALSE(map_s21_dst.empty());
}

TEST(Map, CopyAssignmentOperator1) {
  s21::map<int, int> map_s21_src{{1, 2}, {3, 4}, {5, 6}};
  s21::map<int, int> map_s21_dst;
  map_s21_dst = map_s21_src;

  EXPECT_EQ(map_s21_src.size(), map_s21_dst.size());
  EXPECT_FALSE(map_s21_src.empty());
  EXPECT_FALSE(map_s21_dst.empty());
}

TEST(Map, CopyAssignmentOperator2) {
  s21::map<int, int> map_s21_src{{1, 2}, {3, 4}, {5, 6}};
  map_s21_src = map_s21_src;

  EXPECT_EQ(map_s21_src.size(), 3);
  EXPECT_FALSE(map_s21_src.empty());
}

TEST(Map, MoveAssignmentOperator1) {
  s21::map<int, int> map_s21_src{{1, 2}, {3, 4}, {5, 6}};
  s21::map<int, int> map_s21_dst;
  map_s21_dst = std::move(map_s21_src);

  EXPECT_EQ(map_s21_dst.size(), 3);
  EXPECT_EQ(map_s21_src.size(), 0);
  EXPECT_TRUE(map_s21_src.empty());
}

TEST(Map, Insert1) {
  s21::map<int, int> map_s21_dst;

  map_s21_dst.insert({5, 10});
  map_s21_dst.insert(3, 30);
  map_s21_dst.insert(3, 30);
  map_s21_dst.insert(3, 30);
  map_s21_dst.insert(3, 30);
  map_s21_dst.insert(3, 30);
  map_s21_dst.insert(3, 30);
  map_s21_dst.insert(3, 30);
  map_s21_dst.insert(3, 30);
  map_s21_dst.insert(3, 30);
  map_s21_dst.insert(3, 30);
  map_s21_dst.insert(3, 30);
  map_s21_dst.insert(3, 30);
  map_s21_dst.insert(3, 30);
  map_s21_dst.insert(3, 30);
  map_s21_dst.insert(3, 30);
  map_s21_dst.insert(3, 30);
  map_s21_dst.insert(3, 30);

  EXPECT_EQ(map_s21_dst.size(), 2);
}

TEST(Map, InsertOrAssign1) {
  s21::map<int, int> map_s21_dst;

  map_s21_dst.insert_or_assign(5, 10);
  map_s21_dst.insert_or_assign(3, 30);
  map_s21_dst.insert_or_assign(3, 50);

  EXPECT_EQ(map_s21_dst.size(), 2);
  EXPECT_EQ(map_s21_dst[3], 50);
}

TEST(Map, OperatorSquareBrackets1) {
  s21::map<int, int> map_s21_dst;

  map_s21_dst[123] = 456;
  map_s21_dst[456];

  EXPECT_EQ(map_s21_dst.size(), 2);
  EXPECT_EQ(map_s21_dst[456], 0);
  EXPECT_EQ(map_s21_dst[123], 456);
}

TEST(Map, At1) {
  s21::map<int, int> map_s21_dst;

  EXPECT_THROW(map_s21_dst.at(123), std::out_of_range);
}

TEST(Map, At2) {
  s21::map<int, int> map_s21_dst;

  map_s21_dst[123] = 456;
  map_s21_dst[456];

  EXPECT_EQ(map_s21_dst.size(), 2);
  EXPECT_EQ(map_s21_dst.at(456), 0);
  EXPECT_EQ(map_s21_dst.at(123), 456);
}

TEST(Map, Merge1) {
  s21::map<int, int> map_s21_src{{1, 2}, {3, 4}, {5, 6}};
  s21::map<int, int> map_s21_dst{{3, 888}};
  map_s21_dst.merge(map_s21_src);

  EXPECT_EQ(map_s21_src.size(), 1);
  EXPECT_EQ(map_s21_dst.size(), 3);
  EXPECT_FALSE(map_s21_src.empty());
  EXPECT_FALSE(map_s21_dst.empty());
}

TEST(Map, IteratorBegin1) {
  s21::map<int, int> map_s21_src{{1, 2}, {3, 4}, {5, 6}};

  EXPECT_NE(map_s21_src.begin(), map_s21_src.end());
  EXPECT_EQ(*map_s21_src.begin(), 2);
}

TEST(Map, IteratorCBegin1) {
  s21::map<int, int> map_s21_src{{1, 2}, {3, 4}, {5, 6}};

  EXPECT_NE(map_s21_src.cbegin(), map_s21_src.cend());
  EXPECT_EQ(*map_s21_src.cbegin(), 2);
}

TEST(Map, IteratorIncrement1) {
  s21::map<int, int> map_s21_src{{1, 2}, {3, 4}, {5, 6}};

  auto it = map_s21_src.begin();

  ++it;
  EXPECT_EQ(*it, 4);
  it++;  // cppcheck-suppress postfixOperator
  EXPECT_EQ(*it, 6);
}

TEST(Map, IteratorDecrement1) {
  s21::map<int, int> map_s21_src{{1, 2}, {3, 4}, {5, 6}};

  auto it = map_s21_src.end();

  --it;
  EXPECT_EQ(*it, 6);
  it--;  // cppcheck-suppress postfixOperator
  EXPECT_EQ(*it, 4);
}

TEST(Map, IteratorCheckEqual1) {
  s21::map<int, int> map_s21_src;

  EXPECT_EQ(map_s21_src.begin(), map_s21_src.end());
}

TEST(Map, IteratorOperatorArrow1) {
  struct test_t {
    int key;
    int value;
  };
  test_t test1{1, 2};

  s21::map<int, test_t> map_s21_src{{1, test1}};
  auto it = map_s21_src.begin();

  EXPECT_EQ(it->value, 2);
}

TEST(Map, IteratorCopyAssign1) {
  s21::map<int, int> map_s21_src{{1, 2}, {3, 4}, {5, 6}};

  auto it = map_s21_src.begin();
  auto it_copy = map_s21_src.begin();
  ++it_copy;
  it = it_copy;

  EXPECT_EQ(it, it_copy);
}

TEST(Map, InsertMany1) {
  s21::map<int, int> map_s21_src{{1, 2}, {3, 4}, {5, 6}};

  map_s21_src.insert_many(std::make_pair(11, 11), std::make_pair(12, 12),
                          std::make_pair(13, 13), std::make_pair(1, 2));

  EXPECT_EQ(map_s21_src.size(), 6);
}

TEST(Map, MaxSize1) {
  s21::map<int, int> map_s21;
  std::size_t expected =
      std::numeric_limits<std::ptrdiff_t>::max() / (3 * sizeof(void *));

  EXPECT_EQ(map_s21.max_size(), expected);
}