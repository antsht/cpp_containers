#include "s21_tests.h"
using namespace s21;

TEST(ListTest, DefaultCtor) {
  list<int> list1;
  ASSERT_EQ(list1.size(), 0);
}

TEST(ListTest, initialization_list_ctor) {
  list<int> list1{1, 2, 3, 4, 5};
  ASSERT_EQ(list1.size(), 5);
}

TEST(ListTest, MoveCtor) {
  list<int> list1;
  list1.push_back(666);
  list1.push_back(777);
  list<int> list2{std::move(list1)};
  ASSERT_EQ(list2.size(), 2);
  ASSERT_EQ(list1.size(), 0);
}

TEST(ListTest, CopyCtor) {
  list<int> list1;

  list1.push_back(666);
  list1.push_back(777);
  list<int> list2{list1};
  ASSERT_EQ(list2.size(), 2);
}

TEST(ListTest, CountCtor) {
  list<int> list1(7);
  ASSERT_EQ(list1.size(), 7);
  for (auto it = list1.begin(); it != list1.end(); ++it) {
    ASSERT_EQ(*it, 0);
  }
  list1.push_back(666);
  list1.push_back(777);
  ASSERT_EQ(list1.size(), 9);
}

TEST(ListTest, Size) {
  s21::list<int> list;
  EXPECT_EQ(list.size(), 0);

  list.push_back(1);
  EXPECT_EQ(list.size(), 1);

  list.push_back(2);
  list.push_back(3);
  EXPECT_EQ(list.size(), 3);

  list.clear();
  EXPECT_EQ(list.size(), 0);
}

TEST(ListTest, MaxSize) {
  s21::list<int> list_int;
  s21::list<char> list_char;
  s21::list<double> list_double;
  s21::list<std::string> list_string;

  EXPECT_GT(list_int.max_size(), 0);
  EXPECT_GT(list_char.max_size(), 0);
  EXPECT_GT(list_double.max_size(), 0);
  EXPECT_GT(list_string.max_size(), 0);

  EXPECT_EQ(list_int.max_size(), list_int.max_size());
  EXPECT_EQ(list_char.max_size(), list_char.max_size());
}

TEST(ListTest, Resize) {
  list<int> list1(2);
  ASSERT_EQ(list1.size(), 2);
  for (auto it = list1.begin(); it != list1.end(); ++it) {
    ASSERT_EQ(*it, 0);
  }
  list1.push_back(666);
  list1.push_back(777);
  ASSERT_EQ(list1.size(), 4);
  list1.resize(3);
  ASSERT_EQ(list1.size(), 3);
  list1.resize(5, 888);
  ASSERT_EQ(list1.size(), 5);
  auto it = list1.begin();
  ASSERT_EQ(*it, 0);
  ++it;
  ASSERT_EQ(*it, 0);
  ++it;
  ASSERT_EQ(*it, 666);
  ++it;
  ASSERT_EQ(*it, 888);
  ++it;
  ASSERT_EQ(*it, 888);
}

TEST(ListTest, CountValuesCtor) {
  list<int> list1(7, 555);
  ASSERT_EQ(list1.size(), 7);
  for (auto it = list1.begin(); it != list1.end(); ++it) {
    ASSERT_EQ(*it, 555);
  }
  list1.push_back(666);
  list1.push_back(777);
  ASSERT_EQ(list1.size(), 9);
}

TEST(ListTest, PushBackInt) {
  list<int> list1;
  ASSERT_EQ(list1.size(), 0);
  list1.push_back(666);
  ASSERT_EQ(list1.size(), 1);
  list1.push_back(777);
  ASSERT_EQ(list1.size(), 2);
}

TEST(ListTest, PushBackStrings) {
  list<std::string> list1;
  ASSERT_EQ(list1.size(), 0);
  list1.push_back("aaa");
  ASSERT_EQ(list1.size(), 1);
  list1.push_back("bbb");
  ASSERT_EQ(list1.size(), 2);
}

TEST(ListTest, PushFrontInt) {
  list<int> list1;
  ASSERT_EQ(list1.size(), 0);
  list1.push_front(666);
  ASSERT_EQ(list1.size(), 1);
  list1.push_front(777);
  ASSERT_EQ(list1.size(), 2);
}

TEST(ListTest, PushFrontStrings) {
  list<std::string> list1;
  ASSERT_EQ(list1.size(), 0);
  list1.push_front("aaa");
  ASSERT_EQ(list1.size(), 1);
  list1.push_front("bbb");
  ASSERT_EQ(list1.size(), 2);
}

TEST(ListTest, CopyAssigment) {
  list<int> list1;

  list1.push_back(666);
  list1.push_back(777);
  list<int> list2;
  list2.push_back(555);

  list2 = list1;
  ASSERT_EQ(list2.size(), 2);
}

TEST(ListTest, MoveAssignmentRValue) {
  s21::list<int> list1{1, 2, 3};
  s21::list<int> list2{4, 5, 6};

  std::move(list2) = std::move(list1);

  EXPECT_EQ(list2.size(), 3);
  EXPECT_EQ(list2.front(), 1);
  EXPECT_EQ(list2.back(), 3);

  EXPECT_TRUE(list1.empty());
}

TEST(ListTest, MoveAssignmentRValueSelf) {
  s21::list<int> list1{1, 2, 3};
  auto initial_size = list1.size();

  std::move(list1) = std::move(list1);

  EXPECT_EQ(list1.size(), initial_size);
  EXPECT_EQ(list1.front(), 1);
  EXPECT_EQ(list1.back(), 3);
}

TEST(ListTest, MoveAssignmentRValueEmpty) {
  s21::list<int> list1;
  s21::list<int> list2{1, 2, 3};

  std::move(list2) = std::move(list1);

  EXPECT_TRUE(list2.empty());
  EXPECT_TRUE(list1.empty());
}

TEST(ListTest, MoveAssignmentRValueDifferentSizes) {
  s21::list<int> list1{1, 2, 3, 4, 5};
  s21::list<int> list2{1, 2};

  std::move(list2) = std::move(list1);

  EXPECT_EQ(list2.size(), 5);
  EXPECT_TRUE(list1.empty());
}

TEST(ListTest, Iterator) {
  list<int> list1;

  list1.push_back(666);
  list1.push_back(777);
  ASSERT_EQ(list1.size(), 2);
  auto it = list1.begin();
  ASSERT_EQ(*it, 666);
  ++it;
  ASSERT_EQ(*it, 777);
  --it;
  ASSERT_EQ(*it, 666);
  ++it;
  ++it;
  ASSERT_EQ(it, list1.end());
}

TEST(ListIteratorTest, BeginConstIterator) {
  s21::list<int> list = {1, 2, 3, 4, 5};
  s21::list<int>::const_iterator it = list.begin();
  EXPECT_EQ(*it, 1);
}

TEST(ListIteratorTest, EndConstIterator) {
  s21::list<int> list = {1, 2, 3, 4, 5};
  s21::list<int>::const_iterator it = list.end();
  --it;
  EXPECT_EQ(*it, 5);
}

TEST(ListIteratorTest, CBeginEmptyList) {
  s21::list<int> empty_list;
  s21::list<int>::const_iterator it = empty_list.cbegin();
  EXPECT_EQ(it, empty_list.cend());
}

TEST(ListIteratorTest, ConstIteratorTraversal) {
  s21::list<std::string> list = {"one", "two", "three"};
  s21::list<std::string>::const_iterator it = list.cbegin();
  EXPECT_EQ(*it, "one");
  ++it;
  EXPECT_EQ(*it, "two");
  ++it;
  EXPECT_EQ(*it, "three");
  ++it;
  EXPECT_EQ(it, list.cend());
}

TEST(ListIteratorTest, ConstIteratorComparison) {
  s21::list<int> list = {1, 2, 3};
  s21::list<int>::const_iterator it1 = list.begin();
  s21::list<int>::const_iterator it2 = list.begin();
  EXPECT_TRUE(it1 == it2);
  ++it2;
  EXPECT_FALSE(it1 == it2);
}

TEST(ListTest, Iterator__eq) {
  list<int> list1;

  list1.push_back(666);
  list1.push_back(777);
  ASSERT_EQ(list1.size(), 2);
  auto it = list1.begin();
  ASSERT_EQ(*it, 666);
  ++it;
  ASSERT_EQ(*it, 777);
  auto it2 = list1.end();
  --it2;
  ASSERT_EQ(*it2, 777);
  ASSERT_EQ(it, it2);
}

TEST(ListTest, Clear) {
  list<int> list1{1, 2, 3, 4, 5};
  ASSERT_EQ(list1.size(), 5);
  list1.clear();
  ASSERT_EQ(list1.size(), 0);
  ASSERT_EQ(list1.begin(), list1.end());
}

TEST(ListTest, Pop) {
  list<int> list1{1, 2, 3, 4, 5};
  ASSERT_EQ(list1.size(), 5);

  auto it = list1.begin();
  ASSERT_EQ(*it, 1);
  list1.pop_front();
  ASSERT_EQ(list1.size(), 4);
  it = list1.begin();
  ASSERT_EQ(*it, 2);

  list1.pop_back();
  ASSERT_EQ(list1.size(), 3);
  it = list1.end();
  --it;
  ASSERT_EQ(*it, 4);
  list1.pop_back();
  ASSERT_EQ(list1.size(), 2);

  list1.pop_back();
  ASSERT_EQ(list1.size(), 1);
  list1.pop_back();
  ASSERT_EQ(list1.size(), 0);
  list1.pop_back();
  ASSERT_EQ(list1.size(), 0);
  list1.pop_front();
  ASSERT_EQ(list1.size(), 0);
}

TEST(ListTest, Empty) {
  list<int> list1;
  ASSERT_EQ(list1.size(), 0);
  ASSERT_EQ(list1.empty(), true);
  list1.push_back(666);
  ASSERT_EQ(list1.size(), 1);
  ASSERT_EQ(list1.empty(), false);
}

TEST(ListTest, Insert) {
  list<int> list1;
  list1.push_back(666);
  list1.push_back(888);
  auto it = list1.begin();
  ++it;
  int to_insert = 777;
  list1.insert(it, to_insert);
  ASSERT_EQ(list1.size(), 3);
  ASSERT_EQ(*it, 888);
  ASSERT_EQ((++it), list1.end());
  ASSERT_EQ(*(--it), 888);
  ASSERT_EQ(*(--it), 777);
  ASSERT_EQ(*(--it), 666);
  ASSERT_EQ(it, list1.begin());
}

TEST(ListTest, InsertRvalue) {
  list<int> list1;
  list1.push_back(666);
  list1.push_back(888);
  auto it = list1.begin();
  ++it;
  list1.insert(it, 777);
  ASSERT_EQ(list1.size(), 3);
  ASSERT_EQ(*it, 888);
  ASSERT_EQ((++it), list1.end());
  ASSERT_EQ(*(--it), 888);
  ASSERT_EQ(*(--it), 777);
  ASSERT_EQ(*(--it), 666);
  ASSERT_EQ(it, list1.begin());
}

TEST(ListTest, InsertMultipleElements) {
  s21::list<int> list{1, 2, 3};
  auto it = list.begin();
  ++it;
  list.insert(it, 3, 5);

  s21::vector<int> expected{1, 5, 5, 5, 2, 3};
  auto exp_it = expected.begin();
  for (const auto &val : list) {
    ASSERT_EQ(val, *exp_it++);
  }
  ASSERT_EQ(list.size(), 6);
}

TEST(ListTest, InsertMultipleElementsAtBegin) {
  s21::list<std::string> list{"hello", "world"};
  list.insert(list.begin(), 2, "test");

  ASSERT_EQ(list.size(), 4);
  auto it = list.begin();
  ASSERT_EQ(*it++, "test");
  ASSERT_EQ(*it++, "test");
  ASSERT_EQ(*it++, "hello");
  ASSERT_EQ(*it, "world");
}

TEST(ListTest, InsertMultipleElementsAtEnd) {
  s21::list<double> list{1.1, 2.2};
  list.insert(list.end(), 3, 3.3);

  ASSERT_EQ(list.size(), 5);
  s21::vector<double> expected{1.1, 2.2, 3.3, 3.3, 3.3};
  auto exp_it = expected.begin();
  for (const auto &val : list) {
    ASSERT_DOUBLE_EQ(val, *exp_it++);
  }
}

TEST(ListTest, InsertZeroElements) {
  s21::list<int> list{1, 2, 3};
  auto it = list.begin();
  ++it;
  list.insert(it, 0, 5);

  ASSERT_EQ(list.size(), 3);
  s21::vector<int> expected{1, 2, 3};
  auto exp_it = expected.begin();
  for (const auto &val : list) {
    ASSERT_EQ(val, *exp_it++);
  }
}

TEST(ListTest, InsertMultipleElementsEmptyList) {
  s21::list<char> list;
  list.insert(list.begin(), 3, 'a');

  ASSERT_EQ(list.size(), 3);
  for (const auto &val : list) {
    ASSERT_EQ(val, 'a');
  }
}

TEST(ListTest, InsertIteratorRange) {
  s21::list<int> list1 = {1, 2, 3};
  s21::list<int> list2 = {10, 20, 30};

  auto pos = list1.begin();
  ++pos;  // Position at second element

  auto first = list2.begin();
  auto last = list2.end();

  auto ret = list1.insert(pos, first, last);

  s21::vector<int> expected = {1, 10, 20, 30, 2, 3};
  auto it = list1.begin();
  for (int exp : expected) {
    ASSERT_EQ(*it, exp);
    ++it;
  }
  ASSERT_EQ(*ret, 10);
}

TEST(ListTest, InsertEmptyRange) {
  s21::list<int> list1 = {1, 2, 3};
  s21::list<int> list2;

  auto pos = list1.begin();
  auto first = list2.begin();
  auto last = list2.end();

  auto ret = list1.insert(pos, first, last);

  ASSERT_EQ(*ret, 1);

  s21::vector<int> expected = {1, 2, 3};
  auto it = list1.begin();
  for (int exp : expected) {
    ASSERT_EQ(*it, exp);
    ++it;
  }
}

TEST(ListTest, InsertRangeAtEnd) {
  s21::list<int> list1 = {1, 2, 3};
  s21::list<int> list2 = {4, 5};

  auto ret = list1.insert(list1.end(), list2.begin(), list2.end());

  s21::vector<int> expected = {1, 2, 3, 4, 5};
  auto it = list1.begin();
  for (int exp : expected) {
    ASSERT_EQ(*it, exp);
    ++it;
  }
  ASSERT_EQ(*ret, 4);
}

TEST(ListTest, InsertRangeIntoEmpty) {
  s21::list<int> list1;
  s21::list<int> list2 = {1, 2, 3};

  auto ret = list1.insert(list1.begin(), list2.begin(), list2.end());

  s21::vector<int> expected = {1, 2, 3};
  auto it = list1.begin();
  for (int exp : expected) {
    ASSERT_EQ(*it, exp);
    ++it;
  }
  ASSERT_EQ(*ret, 1);
}

TEST(ListTest, InsertManyTest) {
  s21::list<int> list{1, 2, 3};
  auto it = list.begin();
  ++it;
  it = list.insert_many(it, 4, 5, 6);

  s21::vector<int> expected{1, 4, 5, 6, 2, 3};
  auto exp_it = expected.begin();
  for (auto val : list) {
    EXPECT_EQ(val, *exp_it++);
  }
  EXPECT_EQ(*it, 2);
}

TEST(ListTest, InsertManyEmptyListTest) {
  s21::list<std::string> list;
  auto it = list.insert_many(list.begin(), "first", "second", "third");

  s21::vector<std::string> expected{"first", "second", "third"};
  auto exp_it = expected.begin();
  for (const auto &val : list) {
    EXPECT_EQ(val, *exp_it++);
  }
  EXPECT_EQ(it, list.end());
}

TEST(ListTest, InsertManySingleElementTest) {
  s21::list<double> list{1.1, 2.2, 3.3};
  auto it = list.end();
  it = list.insert_many(it, 4.4);

  s21::vector<double> expected{1.1, 2.2, 3.3, 4.4};
  auto exp_it = expected.begin();
  for (auto val : list) {
    EXPECT_DOUBLE_EQ(val, *exp_it++);
  }
  EXPECT_EQ(it, list.end());
  EXPECT_DOUBLE_EQ(*(--it), 4.4);
}

TEST(ListTest, InsertManyAtBeginningTest) {
  s21::list<char> list{'x', 'y', 'z'};
  auto it = list.begin();
  it = list.insert_many(it, 'a', 'b', 'c');

  s21::vector<char> expected{'a', 'b', 'c', 'x', 'y', 'z'};
  auto exp_it = expected.begin();
  for (auto val : list) {
    EXPECT_EQ(val, *exp_it++);
  }
  EXPECT_EQ(*it, 'x');
}

TEST(ListTest, InsertManyBack) {
  s21::list<int> list;
  list.insert_many_back(1, 2, 3, 4, 5);

  EXPECT_EQ(list.size(), 5);
  EXPECT_EQ(list.back(), 5);
  EXPECT_EQ(list.front(), 1);

  auto it = list.begin();
  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 2);
  EXPECT_EQ(*it++, 3);
  EXPECT_EQ(*it++, 4);
  EXPECT_EQ(*it++, 5);
}

TEST(ListTest, InsertManyFront) {
  s21::list<int> list;
  list.insert_many_front(1, 2, 3, 4, 5);

  EXPECT_EQ(list.size(), 5);
  EXPECT_EQ(list.back(), 1);
  EXPECT_EQ(list.front(), 5);

  auto it = list.begin();
  EXPECT_EQ(*it++, 5);
  EXPECT_EQ(*it++, 4);
  EXPECT_EQ(*it++, 3);
  EXPECT_EQ(*it++, 2);
  EXPECT_EQ(*it++, 1);
}

TEST(ListTest, InsertManyBackEmpty) {
  s21::list<int> list;
  list.insert_many_back();
  EXPECT_EQ(list.size(), 0);
}

TEST(ListTest, InsertManyFrontEmpty) {
  s21::list<int> list;
  list.insert_many_front();
  EXPECT_EQ(list.size(), 0);
}

TEST(ListTest, InsertManyBackDifferentTypes) {
  s21::list<std::string> list;
  list.insert_many_back("hello", "world", "test");

  EXPECT_EQ(list.size(), 3);
  EXPECT_EQ(list.front(), "hello");
  EXPECT_EQ(list.back(), "test");
}

TEST(ListTest, InsertManyFrontDifferentTypes) {
  s21::list<std::string> list;
  list.insert_many_front("hello", "world", "test");

  EXPECT_EQ(list.size(), 3);
  EXPECT_EQ(list.front(), "test");
  EXPECT_EQ(list.back(), "hello");
}

TEST(ListTest, EraseMiddle) {
  s21::list<int> list = {1, 2, 3, 4, 5};
  auto it = list.begin();
  ++it;
  ++it;
  auto result = list.erase(it);

  ASSERT_EQ(list.size(), 4);
  EXPECT_EQ(*result, 4);

  s21::vector<int> expected = {1, 2, 4, 5};
  auto list_it = list.begin();
  for (const auto &val : expected) {
    EXPECT_EQ(*list_it, val);
    ++list_it;
  }
}

TEST(ListTest, EraseRange) {
  s21::list<int> list = {1, 2, 3, 4, 5};
  auto first = list.begin();
  ++first;
  auto last = list.end();
  --last;

  auto result = list.erase(first, last);

  ASSERT_EQ(list.size(), 2);
  EXPECT_EQ(*result, 5);

  s21::vector<int> expected = {1, 5};
  auto list_it = list.begin();
  for (const auto &val : expected) {
    EXPECT_EQ(*list_it, val);
    ++list_it;
  }
}

TEST(ListTest, EraseEmpty) {
  s21::list<int> list;
  auto result = list.erase(list.begin(), list.end());

  EXPECT_EQ(result, list.end());
  EXPECT_TRUE(list.empty());
}

TEST(ListTest, FrontReturnsFirstElement) {
  s21::list<int> test_list;
  test_list.push_back(1);
  test_list.push_back(2);
  test_list.push_back(3);
  EXPECT_EQ(test_list.front(), 1);
}

TEST(ListTest, BackReturnsLastElement) {
  s21::list<int> test_list;
  test_list.push_back(1);
  test_list.push_back(2);
  test_list.push_back(3);
  EXPECT_EQ(test_list.back(), 3);
}

TEST(ListTest, FrontModifiesFirstElement) {
  s21::list<int> test_list;
  test_list.push_back(1);
  test_list.push_back(2);
  test_list.push_back(3);
  test_list.front() = 10;
  EXPECT_EQ(test_list.front(), 10);
}

TEST(ListTest, BackModifiesLastElement) {
  s21::list<int> test_list;
  test_list.push_back(1);
  test_list.push_back(2);
  test_list.push_back(3);
  test_list.back() = 30;
  EXPECT_EQ(test_list.back(), 30);
}

TEST(ListTest, FrontOnEmptyList) {
  s21::list<int> empty_list;
  EXPECT_THROW(empty_list.front(), std::out_of_range);
}

TEST(ListTest, BackOnEmptyList) {
  s21::list<int> empty_list;
  EXPECT_THROW(empty_list.back(), std::out_of_range);
}

TEST(ListTest, ReverseTest) {
  s21::list<int> list{1, 2, 3};
  list.reverse();

  s21::vector<int> expected{3, 2, 1};
  auto exp_it = expected.begin();
  for (const auto &val : list) {
    EXPECT_EQ(val, *exp_it++);
  }
}

TEST(ListTest, ReverseOneElement) {
  s21::list<int> list{1};
  list.reverse();
  auto it = list.begin();
  EXPECT_EQ(*it, 1);
}

TEST(ListTest, MergeIntLists) {
  s21::list<int> list{1, 2, 3};
  s21::list<int> list2{4, 5, 6};
  list.merge(list2);

  s21::vector<int> expected{1, 2, 3, 4, 5, 6};
  auto exp_it = expected.begin();
  for (const auto &val : list) {
    EXPECT_EQ(val, *exp_it++);
  }
}

TEST(ListTest, MergeEmptyLists) {
  s21::list<int> list1;
  s21::list<int> list2;
  list1.merge(list2);
  EXPECT_TRUE(list1.empty());
  EXPECT_TRUE(list2.empty());
}

TEST(ListTest, MergeSingleElementLists) {
  s21::list<int> list1{1};
  s21::list<int> list2{2};
  list1.merge(list2);
  EXPECT_EQ(list1.size(), 2);
  EXPECT_TRUE(list2.empty());
  auto it = list1.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
}

TEST(ListTest, MergeMultipleElements) {
  s21::list<int> list1{1, 3, 5};
  s21::list<int> list2{2, 4, 6};
  list1.merge(list2);
  EXPECT_EQ(list1.size(), 6);
  EXPECT_TRUE(list2.empty());

  s21::vector<int> expected{1, 3, 5, 2, 4, 6};
  auto it = list1.begin();
  for (const auto &val : expected) {
    EXPECT_EQ(*it, val);
    ++it;
  }
}

TEST(ListTest, MergeSameList) {
  s21::list<int> list1{1, 2, 3};
  list1.merge(list1);
  EXPECT_EQ(list1.size(), 3);

  s21::vector<int> expected{1, 2, 3};
  auto it = list1.begin();
  for (const auto &val : expected) {
    EXPECT_EQ(*it, val);
    ++it;
  }
}

TEST(ListTest, MergeWithEmptyList) {
  s21::list<int> list1{1, 2, 3};
  s21::list<int> list2;
  size_t original_size = list1.size();
  list1.merge(list2);
  EXPECT_EQ(list1.size(), original_size);
  EXPECT_TRUE(list2.empty());
}

TEST(ListTest, UniqueTestBasic) {
  s21::list<int> list{1, 2, 2, 3, 3, 3, 4};
  list.unique();

  s21::vector<int> expected{1, 2, 3, 4};
  auto exp_it = expected.begin();
  for (const auto &val : list) {
    EXPECT_EQ(val, *exp_it++);
  }
}

TEST(ListTest, UniqueTestNoDuplicates) {
  s21::list<int> list{1, 2, 3, 4};
  list.unique();

  s21::vector<int> expected{1, 2, 3, 4};
  auto exp_it = expected.begin();
  for (const auto &val : list) {
    EXPECT_EQ(val, *exp_it++);
  }
}

TEST(ListTest, UniqueTestAllSame) {
  s21::list<int> list{5, 5, 5, 5, 5};
  list.unique();

  s21::vector<int> expected{5};
  auto exp_it = expected.begin();
  for (const auto &val : list) {
    EXPECT_EQ(val, *exp_it++);
  }
}

TEST(ListTest, UniqueTestEmpty) {
  s21::list<int> list;
  list.unique();

  EXPECT_TRUE(list.empty());
}

TEST(ListTest, UniqueTestSingleElement) {
  s21::list<int> list{7};
  list.unique();

  s21::vector<int> expected{7};
  auto exp_it = expected.begin();
  for (const auto &val : list) {
    EXPECT_EQ(val, *exp_it++);
  }
}

TEST(ListTest, UniqueTestDuplicatesAtEnd) {
  s21::list<int> list{1, 2, 3, 4, 4};
  list.unique();

  s21::vector<int> expected{1, 2, 3, 4};
  auto exp_it = expected.begin();
  for (const auto &val : list) {
    EXPECT_EQ(val, *exp_it++);
  }
}

TEST(ListTest, UniqueTestDuplicatesAtBeginning) {
  s21::list<int> list{6, 6, 7, 8, 9};
  list.unique();

  s21::vector<int> expected{6, 7, 8, 9};
  auto exp_it = expected.begin();
  for (const auto &val : list) {
    EXPECT_EQ(val, *exp_it++);
  }
}

TEST(ListTest, UniqueTestAlternatingDuplicates) {
  s21::list<int> list{1, 2, 1, 2, 1, 2};
  list.unique();

  s21::vector<int> expected{1, 2, 1, 2, 1, 2};
  auto exp_it = expected.begin();
  for (const auto &val : list) {
    EXPECT_EQ(val, *exp_it++);
  }
}

TEST(ListTest, UniqueTestMixedDuplicates) {
  s21::list<int> list{1, 1, 2, 3, 3, 2, 4};
  list.unique();

  s21::vector<int> expected{1, 2, 3, 2, 4};
  auto exp_it = expected.begin();
  for (const auto &val : list) {
    EXPECT_EQ(val, *exp_it++);
  }
}

TEST(ListTest, SpliceEmptyList) {
  s21::list<int> list1 = {1, 2, 3};
  s21::list<int> list2;
  auto it = list1.begin();
  ++it;
  list1.splice(it, list2);

  s21::vector<int> expected = {1, 2, 3};
  ASSERT_EQ(list1.size(), 3);
  ASSERT_EQ(list2.size(), 0);

  auto list1_it = list1.begin();
  for (int val : expected) {
    EXPECT_EQ(*list1_it, val);
    ++list1_it;
  }
}

TEST(ListTest, SpliceSameList) {
  s21::list<int> list1 = {1, 2, 3};
  auto it = list1.begin();
  ++it;
  list1.splice(it, list1);

  s21::vector<int> expected = {1, 2, 3};
  ASSERT_EQ(list1.size(), 3);

  auto list1_it = list1.begin();
  for (int val : expected) {
    EXPECT_EQ(*list1_it, val);
    ++list1_it;
  }
}

TEST(ListTest, SpliceFullLists) {
  s21::list<int> list1 = {1, 2, 3};
  s21::list<int> list2 = {4, 5, 6};
  auto it = list1.begin();
  ++it;
  list1.splice(it, list2);

  s21::vector<int> expected = {1, 4, 5, 6, 2, 3};
  ASSERT_EQ(list1.size(), 6);
  ASSERT_EQ(list2.size(), 0);

  auto list1_it = list1.begin();
  for (int val : expected) {
    EXPECT_EQ(*list1_it, val);
    ++list1_it;
  }
}

TEST(ListTest, SpliceAtBeginning) {
  s21::list<int> list1 = {1, 2, 3};
  s21::list<int> list2 = {4, 5, 6};
  list1.splice(list1.begin(), list2);

  s21::vector<int> expected = {4, 5, 6, 1, 2, 3};
  ASSERT_EQ(list1.size(), 6);
  ASSERT_EQ(list2.size(), 0);

  auto list1_it = list1.begin();
  for (int val : expected) {
    EXPECT_EQ(*list1_it, val);
    ++list1_it;
  }
}

TEST(ListTest, SpliceAtEnd) {
  s21::list<int> list1 = {1, 2, 3};
  s21::list<int> list2 = {4, 5, 6};
  list1.splice(list1.end(), list2);

  s21::vector<int> expected = {1, 2, 3, 4, 5, 6};
  ASSERT_EQ(list1.size(), 6);
  ASSERT_EQ(list2.size(), 0);

  auto list1_it = list1.begin();
  for (int val : expected) {
    EXPECT_EQ(*list1_it, val);
    ++list1_it;
  }
}

TEST(ListIteratorTest, DereferenceOperatorValidNode) {
  s21::list<int> lst{1, 2, 3};
  auto it = lst.begin();
  EXPECT_EQ(*it, 1);
}

TEST(ListIteratorTest, DereferenceOperatorThrowsOnSentinel) {
  s21::list<int> lst;
  auto it = lst.end();
  EXPECT_THROW(*it, std::out_of_range);
}

TEST(ListIteratorTest, ArrowOperatorValidNode) {
  s21::list<std::string> lst{"test"};
  auto it = lst.begin();
  EXPECT_EQ(it->length(), 4);
}

TEST(ListIteratorTest, ArrowOperatorThrowsOnSentinel) {
  struct A {
    int value = 42;
  };
  A a{};
  s21::list<A> lst{a};
  auto it = lst.end();
  EXPECT_THROW(it->value, std::out_of_range);
}

TEST(ListIteratorTest, DereferenceOperatorWithComplexType) {
  struct TestStruct {
    int value = 42;
  };
  s21::list<TestStruct> lst{{42}};
  auto it = lst.begin();
  EXPECT_EQ((*it).value, 42);
}

TEST(ListIteratorTest, ArrowOperatorWithComplexType) {
  struct TestStruct {
    int value = 42;
  };
  s21::list<TestStruct> lst{{42}};
  auto it = lst.begin();
  EXPECT_EQ(it->value, 42);
}

TEST(ListSort, EmptyList) {
  s21::list<int> lst;
  lst.sort();
  EXPECT_EQ(lst.size(), 0);
}

TEST(ListSort, SingleElement) {
  s21::list<int> lst{5};
  lst.sort();
  EXPECT_EQ(lst.front(), 5);
  EXPECT_EQ(lst.size(), 1);
}

TEST(ListSort, MultipleElements) {
  s21::list<int> lst{5, 2, 8, 1, 9, 3, 7, 4, 6};
  lst.sort();

  s21::vector<int> expected{1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto it = lst.begin();
  for (int val : expected) {
    EXPECT_EQ(*it, val);
    ++it;
  }
}

TEST(ListSort, DuplicateElements) {
  s21::list<int> lst{3, 1, 3, 2, 1, 2};
  lst.sort();

  s21::vector<int> expected{1, 1, 2, 2, 3, 3};
  auto it = lst.begin();
  for (int val : expected) {
    EXPECT_EQ(*it, val);
    ++it;
  }
}

TEST(ListSort, NegativeNumbers) {
  s21::list<int> lst{-5, 3, -2, 0, -1, 4, -3};
  lst.sort();

  s21::vector<int> expected{-5, -3, -2, -1, 0, 3, 4};
  auto it = lst.begin();
  for (int val : expected) {
    EXPECT_EQ(*it, val);
    ++it;
  }
}

TEST(ListSort, StringSort) {
  s21::list<std::string> lst{"banana", "apple", "cherry", "date"};
  lst.sort();

  s21::vector<std::string> expected{"apple", "banana", "cherry", "date"};
  auto it = lst.begin();
  for (const auto &val : expected) {
    EXPECT_EQ(*it, val);
    ++it;
  }
}