#include "s21_tests.h"

using namespace s21;

TEST(VectorTest, DefaultConstructor) {
  s21::vector<int> vec;
  EXPECT_EQ(vec.size(), 0);
  EXPECT_EQ(vec.capacity(), 0);
}

TEST(VectorTest, SizeConstructor) {
  s21::vector<int> vec(5);
  EXPECT_EQ(vec.size(), 5);
}

TEST(VectorTest, InitializerListConstructor) {
  s21::vector<int> vec{1, 2, 3, 4, 5};
  EXPECT_EQ(vec.size(), 5);
  for (size_t i = 0; i < vec.size(); ++i) {
    EXPECT_EQ(vec[i], i + 1);
  }
}

TEST(VectorTest, CopyConstructor) {
  s21::vector<int> vec1{1, 2, 3, 4, 5};
  s21::vector<int> vec2(vec1);
  EXPECT_EQ(vec2.size(), vec1.size());
  for (size_t i = 0; i < vec1.size(); ++i) {
    EXPECT_EQ(vec2[i], vec1[i]);
  }
}

TEST(VectorTest, MoveConstructor) {
  s21::vector<int> vec1{1, 2, 3, 4, 5};
  size_t original_size = vec1.size();
  s21::vector<int> vec2(std::move(vec1));
  EXPECT_EQ(vec2.size(), original_size);
  EXPECT_EQ(vec1.size(), 0);
}

TEST(VectorTest, AssignmentOperator) {
  s21::vector<int> vec1{1, 2, 3};
  s21::vector<int> vec2;
  vec2 = vec1;
  EXPECT_EQ(vec2.size(), vec1.size());
  for (size_t i = 0; i < vec1.size(); ++i) {
    EXPECT_EQ(vec2[i], vec1[i]);
  }
}

TEST(VectorTest, MoveAssignmentOperator) {
  s21::vector<int> vec1{1, 2, 3};
  s21::vector<int> vec2;
  size_t original_size = vec1.size();
  vec2 = std::move(vec1);
  EXPECT_EQ(vec2.size(), original_size);
  EXPECT_EQ(vec1.size(), 0);
}

TEST(VectorTest, AccessOperator) {
  s21::vector<int> vec{1, 2, 3};
  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 2);
  EXPECT_EQ(vec[2], 3);
}

TEST(VectorTest, AtMethod) {
  s21::vector<int> vec{1, 2, 3};
  EXPECT_EQ(vec.at(0), 1);
  EXPECT_EQ(vec.at(2), 3);
  EXPECT_THROW(vec.at(3), std::out_of_range);
}

TEST(VectorTest, FrontAndBack) {
  s21::vector<int> vec{1, 2, 3};
  EXPECT_EQ(vec.front(), 1);
  EXPECT_EQ(vec.back(), 3);
}

TEST(VectorTest, Data) {
  s21::vector<int> vec{1, 2, 3};
  int* data_ptr = vec.data();
  EXPECT_EQ(data_ptr[0], 1);
  EXPECT_EQ(data_ptr[2], 3);
}

TEST(VectorTest, Empty) {
  s21::vector<int> vec1;
  EXPECT_TRUE(vec1.empty());
  s21::vector<int> vec2{1, 2, 3};
  EXPECT_FALSE(vec2.empty());
}

TEST(VectorTest, Reserve) {
  s21::vector<int> vec;
  vec.reserve(10);
  EXPECT_GE(vec.capacity(), 10);
  EXPECT_EQ(vec.size(), 0);
}

TEST(VectorTest, ShrinkToFit) {
  s21::vector<int> vec;
  vec.reserve(10);
  vec.push_back(1);
  vec.push_back(2);
  vec.shrink_to_fit();
  EXPECT_EQ(vec.capacity(), vec.size());
}

TEST(VectorTest, Clear) {
  s21::vector<int> vec{1, 2, 3};
  vec.clear();
  EXPECT_EQ(vec.size(), 0);
  EXPECT_TRUE(vec.empty());
}

TEST(VectorTest, Iterator) {
  s21::vector<int> vec{1, 2, 3};
  auto it = vec.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  --it;
  EXPECT_EQ(*it, 1);
}

TEST(VectorTest, InsertMethod) {
  s21::vector<int> vec{1, 3, 4};
  auto it = vec.begin() + 1;  // cppcheck-suppress constVariablePointer
  vec.insert(it, 2);
  EXPECT_EQ(vec.size(), 4);
  EXPECT_EQ(vec[1], 2);
}

TEST(VectorTest, EraseMethod) {
  s21::vector<int> vec{1, 2, 3, 4};
  auto it = vec.begin() + 1;  // cppcheck-suppress constVariablePointer
  vec.erase(it);
  EXPECT_EQ(vec.size(), 3);
  EXPECT_EQ(vec[1], 3);
}

TEST(VectorTest, PushBack) {
  s21::vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  EXPECT_EQ(vec.size(), 2);
  EXPECT_EQ(vec.back(), 2);
}

TEST(VectorTest, PopBack) {
  s21::vector<int> vec{1, 2, 3};
  vec.pop_back();
  EXPECT_EQ(vec.size(), 2);
  EXPECT_EQ(vec.back(), 2);
}

TEST(VectorTest, Swap) {
  s21::vector<int> vec1{1, 2, 3};
  s21::vector<int> vec2{4, 5};
  vec1.swap(vec2);
  EXPECT_EQ(vec1.size(), 2);
  EXPECT_EQ(vec2.size(), 3);
  EXPECT_EQ(vec1[0], 4);
  EXPECT_EQ(vec2[0], 1);
}

TEST(VectorTest, MaxSize) {
  s21::vector<int> vec;
  EXPECT_EQ(vec.max_size(), 2305843009213693951);
}

TEST(VectorTest, PushBackString) {
  s21::vector<std::string> vec;
  vec.push_back("first");
  vec.push_back("second");
  EXPECT_EQ(vec.back(), "second");
  EXPECT_EQ(vec.size(), 2);
}

TEST(VectorTest, PopAndEmpty) {
  s21::vector<double> vec;
  vec.push_back(1.1);
  vec.push_back(2.2);
  vec.pop_back();
  EXPECT_EQ(vec.back(), 1.1);
  vec.pop_back();
  EXPECT_TRUE(vec.empty());
}

TEST(VectorTest, InsertManyTest) {
  s21::vector<int> vec{1, 2, 3};
  auto it = vec.begin() + 1;
  vec.insert_many(it, 4, 5, 6);
  EXPECT_EQ(vec.size(), 6);
  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 4);
  EXPECT_EQ(vec[2], 5);
  EXPECT_EQ(vec[3], 6);
  EXPECT_EQ(vec[4], 2);
  EXPECT_EQ(vec[5], 3);
}

TEST(VectorTest, InsertManyEmptyVector) {
  s21::vector<int> vec;
  auto it = vec.begin();
  vec.insert_many(it, 1, 2, 3);
  EXPECT_EQ(vec.size(), 3);
  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 2);
  EXPECT_EQ(vec[2], 3);
}

TEST(VectorTest, InsertManyBackTest) {
  s21::vector<std::string> vec{"hello", "world"};
  vec.insert_many_back("!", "how", "are", "you");
  EXPECT_EQ(vec.size(), 6);
  EXPECT_EQ(vec[0], "hello");
  EXPECT_EQ(vec[1], "world");
  EXPECT_EQ(vec[2], "!");
  EXPECT_EQ(vec[3], "how");
  EXPECT_EQ(vec[4], "are");
  EXPECT_EQ(vec[5], "you");
}

TEST(VectorTest, InsertManySingleElement) {
  s21::vector<double> vec{1.1, 2.2, 3.3};
  auto it = vec.end();
  vec.insert_many(it, 4.4);
  EXPECT_EQ(vec.size(), 4);
  EXPECT_DOUBLE_EQ(vec[0], 1.1);
  EXPECT_DOUBLE_EQ(vec[1], 2.2);
  EXPECT_DOUBLE_EQ(vec[2], 3.3);
  EXPECT_DOUBLE_EQ(vec[3], 4.4);
}

TEST(VectorTest, InsertManyNoElements) {
  s21::vector<int> vec{1, 2, 3};
  auto it = vec.begin();
  vec.insert_many(it);
  EXPECT_EQ(vec.size(), 3);
  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 2);
  EXPECT_EQ(vec[2], 3);
}

TEST(VectorTest, NonDefaultConstructibleType) {
  using PairType = std::pair<const int, int>;
  s21::vector<PairType> vec;
  vec.reserve(2);
  vec.push_back({1, 2});
  vec.push_back({3, 4});

  EXPECT_EQ(vec.size(), 2);
  EXPECT_EQ(vec[0].first, 1);
  EXPECT_EQ(vec[0].second, 2);
  EXPECT_EQ(vec[1].first, 3);
  EXPECT_EQ(vec[1].second, 4);

  s21::vector<PairType> vec2(vec);
  EXPECT_EQ(vec2.size(), 2);
  EXPECT_EQ(vec2[0], vec[0]);
  EXPECT_EQ(vec2[1], vec[1]);

  vec2.insert(vec2.begin(), {5, 6});
  EXPECT_EQ(vec2.size(), 3);
  EXPECT_EQ(vec2[0], PairType(5, 6));
}

TEST(VectorEmplaceBack, PrimitiveType) {
  s21::vector<int> v;
  v.emplace_back(42);
  EXPECT_EQ(v.size(), 1);
  EXPECT_EQ(v[0], 42);
}

TEST(VectorEmplaceBack, StringType) {
  s21::vector<std::string> v;
  v.emplace_back("Hello");
  v.emplace_back("World");
  EXPECT_EQ(v.size(), 2);
  EXPECT_EQ(v[0], "Hello");
  EXPECT_EQ(v[1], "World");
}
