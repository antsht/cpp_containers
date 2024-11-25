#include <set>

#include "s21_test_class.h"
#include "s21_tests.h"

TEST(Set_Member_int, BaseConstructor) {
  std::set<int> cont_orig;
  s21::set<int> cont_21;

  EXPECT_EQ(cont_orig.empty(), cont_21.empty());
}

TEST(Set_Member_int, ArgConstructor) {
  int a = 1, b = 2, c = 3;
  std::set<int> cont_orig{a, b, c};
  s21::set<int> cont_21{a, b, c};

  EXPECT_EQ(cont_orig.size(), cont_21.size());
}

TEST(Set_Member_int, ArgConstructorWithRepeat) {
  int a = 1, b = 2, c = 3;
  std::set<int> cont_orig{a, a, b, b, c, c};
  s21::set<int> cont_21{a, a, b, b, c, c};

  EXPECT_EQ(cont_orig.size(), cont_21.size());
}

TEST(Set_Member_int, ArgConstructorInverseKey) {
  int a = 1, b = 2, c = 3, d = 4;
  std::set<int> cont_orig{d, c, b, a};
  s21::set<int> cont_21{d, c, b, a};

  EXPECT_EQ(cont_orig.size(), cont_21.size());
}

TEST(Set_Member_int, CopyConstructor) {
  int a = 1, b = 2, c = 3;
  s21::set<int> cont_21{a, b, c};
  s21::set<int> copy_21{cont_21};

  EXPECT_EQ(copy_21.size(), cont_21.size());
}

TEST(Set_Member_int, CopyAssignmentEmpty) {
  int a = 1, b = 2, c = 3;
  s21::set<int> cont_21{a, b, c};
  s21::set<int> copy_21 = cont_21;
  auto copy_it = copy_21.begin();
  auto copy_it_end = copy_21.end();

  EXPECT_EQ(copy_21.size(), cont_21.size());
  EXPECT_EQ(*copy_it, a);
  EXPECT_EQ(*(++copy_it), b);
  EXPECT_EQ(*(++copy_it), c);
  EXPECT_EQ(*(++copy_it), *copy_it_end);
}

TEST(Set_Member_int, CopyAssignmentNotEmpty) {
  int a = 1, b = 2, c = 3;
  s21::set<int> cont_21{a, b, c};
  s21::set<int> copy_21{10, 11};
  copy_21 = cont_21;
  auto copy_it = copy_21.begin();
  auto copy_it_end = copy_21.end();

  EXPECT_EQ(copy_21.size(), cont_21.size());
  EXPECT_EQ(*copy_it, a);
  EXPECT_EQ(*(++copy_it), b);
  EXPECT_EQ(*(++copy_it), c);
  EXPECT_EQ(*(++copy_it), *copy_it_end);
}

TEST(Set_Member_int, CopyAssignmentSelf) {
  int a = 1, b = 2, c = 3;
  s21::set<int> copy_21{a, b, c};
  copy_21 = copy_21;
  auto copy_it = copy_21.begin();
  auto copy_it_end = copy_21.end();

  EXPECT_EQ(3, copy_21.size());
  EXPECT_EQ(*copy_it, a);
  EXPECT_EQ(*(++copy_it), b);
  EXPECT_EQ(*(++copy_it), c);
  EXPECT_EQ(*(++copy_it), *copy_it_end);
}

TEST(Set_Member_int, MoveConstructor) {
  int a = 1, b = 2, c = 3;
  s21::set<int> cont_21{a, b, c};
  s21::set<int> move_21(std::move(cont_21));

  EXPECT_EQ(move_21.size(), 3);
  EXPECT_EQ(cont_21.size(), 0);
  EXPECT_EQ(cont_21.empty(), true);
}

TEST(Set_Member_int, MoveAssigment) {
  int a = 1, b = 2, c = 3;
  s21::set<int> cont_21{a, b, c};
  s21::set<int> move_21;
  move_21 = std::move(cont_21);

  EXPECT_EQ(move_21.size(), 3);
  EXPECT_EQ(cont_21.size(), 0);
  EXPECT_EQ(cont_21.empty(), true);
}

TEST(Set_Iterator_CustomClass, SomeOperator) {
  TestUnit a{"ivanov", 1};
  std::set<TestUnit> cont_orig{a};
  s21::set<TestUnit> cont_21{a};

  auto orig = cont_orig.begin();
  auto s21 = cont_21.begin();

  EXPECT_EQ(orig->name, s21->name);
  EXPECT_EQ(orig->level, s21->level);
}

TEST(Set_Iterator_int, EmptyBeginAndEnd) {
  std::set<int> cont_orig;
  s21::set<int> cont_21;

  EXPECT_EQ(cont_orig.empty(), cont_21.empty());
  EXPECT_EQ(cont_orig.begin(), cont_orig.end());
  EXPECT_EQ(cont_21.begin(), cont_21.end());
}

TEST(Set_Iterator_int, Begin) {
  int a = 1, b = 2, c = 3;
  std::set<int> cont_orig{a, b, c};
  s21::set<int> cont_21{a, b, c};

  EXPECT_EQ(*cont_orig.begin(), *cont_21.begin());
}

TEST(Set_Iterator_int, AfterBeginPreinc) {
  int a = 1, b = 2, c = 3;
  std::set<int> cont_orig{a, b, c};
  s21::set<int> cont_21{a, b, c};

  EXPECT_EQ(*(++cont_orig.begin()), *(++cont_21.begin()));
}

TEST(Set_Iterator_int, AfterBeginPostinc) {
  int a = 1, b = 2, c = 3;
  std::set<int> cont_orig{a, b, c};
  s21::set<int> cont_21{a, b, c};

  auto orig = cont_orig.begin();
  auto s21 = cont_21.begin();
  orig++;
  s21++;  // cppcheck-suppress postfixOperator

  EXPECT_EQ(*orig, *s21);
}

TEST(Set_Iterator_int, End) {
  int a = 1, b = 2, c = 3;
  s21::set<int> cont_21{a, b, c};

  EXPECT_EQ(0, *cont_21.end());
}

TEST(Set_Iterator_int, BeforeEndPreinc) {
  int a = 1, b = 2, c = 3;
  std::set<int> cont_orig{a, b, c};
  s21::set<int> cont_21{a, b, c};

  auto orig = --cont_orig.end();
  auto s21 = --cont_21.end();

  EXPECT_EQ(*orig, *s21);
}

TEST(Set_Iterator_int, BeforeEndPostinc) {
  int a = 1, b = 2, c = 3;
  std::set<int> cont_orig{a, b, c};
  s21::set<int> cont_21{a, b, c};

  auto orig = cont_orig.end();
  auto s21 = cont_21.end();
  orig--;
  s21--;  // cppcheck-suppress postfixOperator

  EXPECT_EQ(*orig, *s21);
}

TEST(Set_Modifier_int, EmptyClear) {
  std::set<int> cont_orig;
  s21::set<int> cont_21;

  cont_orig.clear();
  cont_21.clear();

  EXPECT_EQ(cont_orig.empty(), cont_21.empty());
  EXPECT_EQ(cont_orig.size(), cont_21.size());
}

TEST(Set_Modifier_int, Clear) {
  int a = 3, b = 2, c = 1;
  std::set<int> cont_orig{a, b, c};
  s21::set<int> cont_21{a, b, c};

  cont_orig.clear();
  cont_21.clear();

  EXPECT_EQ(cont_orig.empty(), cont_21.empty());
  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(cont_orig.begin(), cont_orig.end());
  EXPECT_EQ(cont_21.begin(), cont_21.end());
}

TEST(Set_Lookup_int, EmptyCount) {
  std::set<int> cont_orig;
  s21::set<int> cont_21;

  int orig = cont_orig.count(1);
  int s21 = cont_21.count(1);

  EXPECT_EQ(cont_orig.empty(), cont_21.empty());
  EXPECT_EQ(orig, s21);
}

TEST(Set_Lookup_int, Count) {
  int a = 1, b = 2, c = 3;
  std::set<int> cont_orig{a, b, c};
  s21::set<int> cont_21{a, b, c};

  int orig = cont_orig.count(1);
  int s21 = cont_21.count(1);

  EXPECT_EQ(orig, s21);
}

TEST(Set_Lookup_int, EmptyContains) {
  s21::set<int> cont_21;

  EXPECT_EQ(false, cont_21.contains(1));
}

TEST(Set_Lookup_int, Countains) {
  int a = 1, b = 2, c = 3;
  s21::set<int> cont_21{a, b, c};

  EXPECT_EQ(true, cont_21.contains(1));
  EXPECT_EQ(true, cont_21.contains(2));
  EXPECT_EQ(true, cont_21.contains(3));
}

TEST(Set_Lookup_int, EmptyFind) {
  std::set<int> cont_orig;
  s21::set<int> cont_21;

  auto orig = cont_orig.find(1);
  auto s21 = cont_21.find(1);

  EXPECT_EQ(cont_orig.empty(), cont_21.empty());
  EXPECT_EQ(*orig, *s21);
}

TEST(Set_Lookup_int, Find) {
  int a = 1, b = 2, c = 3;
  std::set<int> cont_orig{a, b, c};
  s21::set<int> cont_21{a, b, c};

  auto orig = cont_orig.find(2);
  auto s21 = cont_21.find(2);

  EXPECT_EQ(*orig, *s21);
}

TEST(Set_Modifier_int, Swap) {
  int a = 1, b = 2, c = 3;
  s21::set<int> cont_21{a, b, c};
  s21::set<int> swap_21;
  swap_21.swap(cont_21);

  EXPECT_EQ(3, swap_21.size());
  EXPECT_EQ(0, cont_21.size());
  EXPECT_EQ(1, *swap_21.begin());
}

TEST(Set_Modifier_int, ValidityIteratorsAfterSwap) {
  int a = 1, b = 2, c = 3;
  s21::set<int> cont_21{a, b, c};
  s21::set<int> swap_21{4, 5, 6};

  auto cont_begin = cont_21.begin();
  auto swap_begin = swap_21.begin();
  swap_21.swap(cont_21);

  EXPECT_EQ(cont_21.size(), swap_21.size());
  EXPECT_EQ(*cont_begin, 1);
  EXPECT_EQ(*++cont_begin, 2);
  EXPECT_EQ(*++cont_begin, 3);
  EXPECT_EQ(*swap_begin, 4);
  EXPECT_EQ(*++swap_begin, 5);
  EXPECT_EQ(*++swap_begin, 6);
}

TEST(Set_Modifier_int, EraseByKey) {
  int a = 1, b = 2, c = 3;
  std::set<int> cont_orig{a, b, c};
  s21::set<int> cont_21{a, b, c};

  cont_orig.erase(2);
  cont_21.erase(2);

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(cont_orig.count(2), cont_21.count(2));
}

TEST(Set_Modifier_int, EraseByKeyRoot) {
  int a = 1, b = 2;
  std::set<int> cont_orig{b, a};
  s21::set<int> cont_21{b, a};

  cont_orig.erase(2);
  cont_21.erase(2);

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(cont_orig.count(2), cont_21.count(2));
}

TEST(Set_Modifier_int, EraseByKeyInverseKey) {
  int a = 1, b = 2, c = 3;
  std::set<int> cont_orig{c, b, a};
  s21::set<int> cont_21{c, b, a};

  cont_orig.erase(3);
  cont_21.erase(3);

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(cont_orig.count(3), cont_21.count(3));
}

TEST(Set_Modifier_int, EraseByKeyBigTree) {
  int a = 1, b = 2, c = 3, d = 4, e = 5, i = 8, g = 7;
  std::set<int> cont_orig{g, c, b, a, d, e, i};
  s21::set<int> cont_21{g, c, b, a, d, e, i};

  cont_orig.erase(7);
  cont_21.erase(7);
  cont_orig.erase(5);
  cont_21.erase(5);
  cont_orig.erase(3);
  cont_21.erase(3);

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(cont_orig.count(7), cont_21.count(7));
  EXPECT_EQ(cont_orig.count(5), cont_21.count(5));
}

TEST(Set_Modifier_int, EmptyEraseByKey) {
  int a = 1, b = 2, c = 3;
  std::set<int> cont_orig{a, b, c};
  s21::set<int> cont_21{a, b, c};

  int orig = cont_orig.erase(4);
  int s21 = cont_21.erase(4);

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(orig, s21);
}

TEST(Set_Modifier_int, Merge) {
  s21::set<int> merge_21{1, 2, 3};
  s21::set<int> cont_21{4, 5, 6};
  std::set<int> merge_orig{1, 2, 3};
  std::set<int> cont_orig{4, 5, 6};

  merge_21.merge(cont_21);
  merge_orig.merge(cont_orig);

  EXPECT_EQ(merge_orig.size(), merge_21.size());
  EXPECT_EQ(cont_orig.size(), cont_21.size());
}

TEST(Set_Modifier_int, MergSelf) {
  int a = 1, b = 2, c = 3;
  std::set<int> merge_orig{a, b, c};
  s21::set<int> merge_21{a, b, c};

  merge_21.merge(merge_21);
  merge_orig.merge(merge_orig);

  EXPECT_EQ(3, merge_21.size());
  EXPECT_EQ(3, merge_orig.size());
}

TEST(Set_Modifier_int, EmptyMerge) {
  s21::set<int> merge_21{1, 2, 3};
  s21::set<int> cont_21;

  merge_21.merge(cont_21);

  EXPECT_EQ(3, merge_21.size());
  EXPECT_EQ(0, cont_21.size());
}

TEST(Set_Modifier_int, MergeInEmpty) {
  s21::set<int> merge_21;
  s21::set<int> cont_21{1, 2, 3};

  merge_21.merge(cont_21);

  EXPECT_EQ(3, merge_21.size());
  EXPECT_EQ(0, cont_21.size());
}

TEST(Set_Modifier_int, MergeSimilar) {
  s21::set<int> merge_21{1, 2, 3};
  s21::set<int> cont_21{1, 2, 3};
  std::set<int> merge_orig{1, 2, 3};
  std::set<int> cont_orig{1, 2, 3};

  merge_21.merge(cont_21);
  merge_orig.merge(cont_orig);

  EXPECT_EQ(merge_orig.size(), merge_21.size());
  EXPECT_EQ(cont_orig.size(), cont_21.size());
}

TEST(Set_Modifier_int, InsertInEmpty) {
  s21::set<int> cont_21;

  auto res = cont_21.insert(10);

  EXPECT_EQ(1, cont_21.size());
  EXPECT_EQ(1, cont_21.contains(10));
  EXPECT_EQ(10, *res.first);
  EXPECT_EQ(true, res.second);
}

TEST(Set_Modifier_int, Insert) {
  int a = 1, b = 3, c = 4;
  std::set<int> cont_orig{a, b, c};
  s21::set<int> cont_21{a, b, c};

  auto s21_2 = cont_21.insert(2);
  auto orig_2 = cont_orig.insert(2);

  auto s21_5 = cont_21.insert(5);
  auto orig_5 = cont_orig.insert(5);

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(*orig_2.first, *s21_2.first);
  EXPECT_EQ(orig_2.second, s21_2.second);
  EXPECT_EQ(*orig_5.first, *s21_5.first);
  EXPECT_EQ(orig_5.second, s21_5.second);
}

TEST(Set_Modifier_int, InsertSimilar) {
  int a = 1, b = 2, c = 3;
  std::set<int> cont_orig{a, b, c};
  s21::set<int> cont_21{a, b, c};

  auto s21 = cont_21.insert(b);
  auto orig = cont_orig.insert(b);

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(*orig.first, *s21.first);
  EXPECT_EQ(orig.second, s21.second);
}

TEST(Set_Capasity_int, MaxSize) {
  s21::set<int> cont_21;

  auto res = cont_21.max_size();

  EXPECT_LT(1, res);
}

TEST(Set_Modifier_int, EraseByIt) {
  int a = 1, b = 2, c = 3;
  std::set<int> cont_orig{a, b, c};
  s21::set<int> cont_21{a, b, c};

  cont_orig.erase(cont_orig.find(2));
  cont_21.erase(cont_21.find(2));

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(cont_orig.count(2), cont_21.count(2));
}

TEST(Set_Modifier_int, EraseByConstIt) {
  int a = 1, b = 2, c = 3;
  std::set<int> cont_orig{a, b, c};
  s21::set<int> cont_21{a, b, c};

  cont_orig.erase(cont_orig.cbegin());
  cont_21.erase(cont_21.cbegin());

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(cont_orig.count(1), cont_21.count(1));
}

TEST(Set_Modifier_int, EmptyEraseByIt) {
  int a = 1, b = 2, c = 3;
  s21::set<int> cont_21{a, b, c};

  //! cont_orig.erase(cont_orig.find(4)); он удалил последний!!!!
  cont_21.erase(cont_21.find(4));

  EXPECT_EQ(3, cont_21.size());
}

TEST(Set_Lookup_int, LowerBoundEmpty) {
  std::set<int> cont_orig;
  s21::set<int> cont_21;

  auto orig = cont_orig.lower_bound(1);
  auto s21 = cont_21.lower_bound(1);

  EXPECT_EQ(*orig, *s21);
}

TEST(Set_Lookup_int, LowerBoundEqual) {
  int a = 1, b = 2, c = 3;
  std::set<int> cont_orig{a, b, c};
  s21::set<int> cont_21{a, b, c};

  auto orig = cont_orig.lower_bound(2);
  auto s21 = cont_21.lower_bound(2);

  EXPECT_EQ(*orig, *s21);
}

TEST(Set_Lookup_int, LowerBoundGreater) {
  int a = 1, b = 3, c = 4;
  std::set<int> cont_orig{a, b, c};
  s21::set<int> cont_21{a, b, c};

  auto orig = cont_orig.lower_bound(2);
  auto s21 = cont_21.lower_bound(2);

  EXPECT_EQ(*orig, *s21);
}

TEST(Set_Lookup_int, LowerBoundEnd) {
  int a = 1, b = 3, c = 4;
  std::set<int> cont_orig{a, b, c};
  s21::set<int> cont_21{a, b, c};

  auto orig = cont_orig.lower_bound(5);
  auto s21 = cont_21.lower_bound(5);

  EXPECT_EQ(cont_orig.end(), orig);
  EXPECT_EQ(cont_21.end(), s21);
}

TEST(Set_Lookup_int, LowerBoundBeforeFirst) {
  int a = 2, b = 3, c = 4;
  std::set<int> cont_orig{a, b, c};
  s21::set<int> cont_21{a, b, c};

  auto orig = cont_orig.lower_bound(1);
  auto s21 = cont_21.lower_bound(1);

  EXPECT_EQ(*orig, *s21);
}

TEST(Set_Lookup_int, UpperBoundEmpty) {
  std::set<int> cont_orig;
  s21::set<int> cont_21;

  auto orig = cont_orig.upper_bound(1);
  auto s21 = cont_21.upper_bound(1);

  EXPECT_EQ(*orig, *s21);
}

TEST(Set_Lookup_int, UpperBoundEqual) {
  int a = 1, b = 2, c = 3;
  std::set<int> cont_orig{a, b, c};
  s21::set<int> cont_21{a, b, c};

  auto orig = cont_orig.upper_bound(2);
  auto s21 = cont_21.upper_bound(2);

  EXPECT_EQ(*orig, *s21);
}

TEST(Set_Lookup_int, UpperBoundGreater) {
  int a = 1, b = 3, c = 4;
  std::set<int> cont_orig{a, b, c};
  s21::set<int> cont_21{a, b, c};

  auto orig = cont_orig.upper_bound(2);
  auto s21 = cont_21.upper_bound(2);

  EXPECT_EQ(*orig, *s21);
}

TEST(Set_Lookup_int, UpperBoundEnd) {
  int a = 1, b = 3, c = 4;
  std::set<int> cont_orig{a, b, c};
  s21::set<int> cont_21{a, b, c};

  auto orig = cont_orig.upper_bound(5);
  auto s21 = cont_21.upper_bound(5);

  EXPECT_EQ(cont_orig.end(), orig);
  EXPECT_EQ(cont_21.end(), s21);
}

TEST(Set_Lookup_int, UpperBoundRoot) {
  std::set<int> cont_orig{5};
  s21::set<int> cont_21{5};

  auto orig = cont_orig.upper_bound(5);
  auto s21 = cont_21.upper_bound(5);

  EXPECT_EQ(cont_orig.end(), orig);
  EXPECT_EQ(cont_21.end(), s21);
}

TEST(Set_Lookup_int, LowerBoundRoot) {
  std::set<int> cont_orig{5};
  s21::set<int> cont_21{5};

  auto orig = cont_orig.lower_bound(5);
  auto s21 = cont_21.lower_bound(5);

  EXPECT_EQ(*orig, *s21);
}

TEST(Set_Lookup_int, UpperBoundBeforeRoot) {
  std::set<int> cont_orig{5};
  s21::set<int> cont_21{5};

  auto orig = cont_orig.upper_bound(4);
  auto s21 = cont_21.upper_bound(4);

  EXPECT_EQ(*orig, *s21);
}

TEST(Set_Lookup_int, LowerBoundAfterRoot) {
  std::set<int> cont_orig{5};
  s21::set<int> cont_21{5};

  auto orig = cont_orig.lower_bound(6);
  auto s21 = cont_21.lower_bound(6);

  EXPECT_EQ(cont_orig.end(), orig);
  EXPECT_EQ(cont_21.end(), s21);
}

TEST(Set_Lookup_int, RangeBounds) {
  std::set<int> cont_orig{1, 2, 3};
  s21::set<int> cont_21{1, 2, 3};

  auto orig = cont_orig.equal_range(2);
  auto s21 = cont_21.equal_range(2);

  EXPECT_EQ(*orig.first, *s21.first);
  EXPECT_EQ(*orig.second, *s21.second);
}

TEST(Set_Lookup_int, RangeBoundsFirst) {
  std::set<int> cont_orig{1, 2, 3};
  s21::set<int> cont_21{1, 2, 3};

  auto orig = cont_orig.equal_range(1);
  auto s21 = cont_21.equal_range(1);

  EXPECT_EQ(*orig.first, *s21.first);
  EXPECT_EQ(*orig.second, *s21.second);
}

TEST(Set_Lookup_int, RangeBoundsLast) {
  std::set<int> cont_orig{1, 2, 3};
  s21::set<int> cont_21{1, 2, 3};

  auto orig = cont_orig.equal_range(3);
  auto s21 = cont_21.equal_range(3);

  EXPECT_EQ(*orig.first, *s21.first);
  EXPECT_EQ(orig.second, cont_orig.end());
  EXPECT_EQ(s21.second, cont_21.end());
}

TEST(Set_Lookup_int, RangeBoundsEmpty) {
  std::set<int> cont_orig;
  s21::set<int> cont_21;

  auto orig = cont_orig.equal_range(3);
  auto s21 = cont_21.equal_range(3);

  EXPECT_EQ(*orig.first, *s21.first);
  EXPECT_EQ(orig.second, cont_orig.end());
  EXPECT_EQ(s21.second, cont_21.end());
}

TEST(Set_Lookup_int, RangeBoundsAfter) {
  std::set<int> cont_orig{1, 2, 3};
  s21::set<int> cont_21{1, 2, 3};

  auto orig = cont_orig.equal_range(4);
  auto s21 = cont_21.equal_range(4);

  EXPECT_EQ(orig.first, cont_orig.end());
  EXPECT_EQ(s21.first, cont_21.end());
  EXPECT_EQ(orig.second, cont_orig.end());
  EXPECT_EQ(s21.second, cont_21.end());
}

TEST(Set_Lookup_int, RangeBoundsBefore) {
  std::set<int> cont_orig{1, 2, 3};
  s21::set<int> cont_21{1, 2, 3};

  auto orig = cont_orig.equal_range(-10);
  auto s21 = cont_21.equal_range(-10);

  EXPECT_EQ(*orig.first, *s21.first);
  EXPECT_EQ(*orig.second, *s21.second);
}

TEST(Set_Lookup_int, RangeBoundsPair) {
  std::set<int> cont_orig{1, 2};
  s21::set<int> cont_21{1, 2};

  auto orig = cont_orig.equal_range(3);
  auto s21 = cont_21.equal_range(3);

  EXPECT_EQ(orig.first, cont_orig.end());
  EXPECT_EQ(s21.first, cont_21.end());
  EXPECT_EQ(orig.second, cont_orig.end());
  EXPECT_EQ(s21.second, cont_21.end());
}

TEST(Set_Lookup_int, BeginForMin) {
  int a = 1, b = 2;
  std::set<int> cont_orig{a, b, b};
  s21::set<int> cont_21{a, b, b};

  auto orig = cont_orig.begin();
  auto s21 = cont_21.begin();

  EXPECT_EQ(*orig, *s21);
}

TEST(Set_Iterator_int, ItNotEquals) {
  s21::set<int> cont_21{1, 2, 3};

  auto first = cont_21.begin();
  auto second = cont_21.find(2);
  auto end = cont_21.end();

  EXPECT_EQ(false, first == second);
  EXPECT_EQ(false, end == second);
  EXPECT_EQ(false, first == end);
}

TEST(Set_Iterator_int, ItEquals) {
  s21::set<int> cont_21{1, 2, 3};

  auto first = cont_21.begin();
  auto second = cont_21.find(2);
  auto end = cont_21.end();

  ++first;
  --end;
  --end;

  EXPECT_EQ(true, first == second);
  EXPECT_EQ(true, end == second);
  EXPECT_EQ(true, first == end);
}

TEST(Set_Iterator_int, Decrement) {
  s21::set<int> cont_21{7, 3, 2, 1, 4, 5, 8};

  auto it = cont_21.end();

  EXPECT_EQ(*--it, 8);
  EXPECT_EQ(*--it, 7);
  EXPECT_EQ(*--it, 5);
  EXPECT_EQ(*--it, 4);
  EXPECT_EQ(*--it, 3);
  EXPECT_EQ(*--it, 2);
  EXPECT_EQ(*--it, 1);
  EXPECT_EQ(--it, cont_21.end());
}

TEST(Set_Iterator_int, ReverseIt) {
  s21::set<int> cont_21{7, 3, 2, 1, 4, 5, 8};
  std::set<int> cont_orig{7, 3, 2, 1, 4, 5, 8};

  std::reverse_iterator s21{cont_21.end()};
  std::reverse_iterator orig{cont_orig.end()};
  std::reverse_iterator s21_begin{cont_21.begin()};
  std::reverse_iterator orig_begin{cont_orig.begin()};

  EXPECT_EQ(*s21, *orig);
  EXPECT_EQ(*++s21, *++orig);
  EXPECT_EQ(*++s21, *++orig);
  EXPECT_EQ(*++s21, *++orig);
  EXPECT_EQ(*++s21, *++orig);
  EXPECT_EQ(*++s21, *++orig);
  EXPECT_EQ(*++s21, *++orig);
  EXPECT_EQ(*s21_begin, *cont_21.end());
}

TEST(Set_Iterator_int, ConstReverseIt) {
  s21::set<int> cont_21{7, 3, 2, 1, 4, 5, 8};
  std::set<int> cont_orig{7, 3, 2, 1, 4, 5, 8};

  std::reverse_iterator s21{cont_21.cend()};
  std::reverse_iterator orig{cont_orig.cend()};
  std::reverse_iterator s21_begin{cont_21.cbegin()};
  std::reverse_iterator orig_begin{cont_orig.cbegin()};

  EXPECT_EQ(*s21, *orig);
  EXPECT_EQ(*++s21, *++orig);
  EXPECT_EQ(*++s21, *++orig);
  EXPECT_EQ(*++s21, *++orig);
  EXPECT_EQ(*++s21, *++orig);
  EXPECT_EQ(*++s21, *++orig);
  EXPECT_EQ(*++s21, *++orig);
  EXPECT_EQ(*s21_begin, *cont_21.end());
}

TEST(Set_Iterator_int, ConstIterator) {
  s21::set<int> cont_21{1, 2, 3};

  s21::set<int>::const_iterator it = cont_21.cbegin();

  EXPECT_EQ(*it, 1);
  EXPECT_EQ(*++it, 2);
  EXPECT_EQ(*++it, 3);
  EXPECT_EQ(++it, cont_21.cend());
}

TEST(Set_Iterator_int, CopyAssigment) {
  s21::set<int> cont_21{1, 2, 3};

  auto first = cont_21.begin();
  auto copy{first};

  EXPECT_EQ(first, copy);
}

TEST(Set_Iterator_int, CopyConstructor) {
  s21::set<int> cont_21{1, 2, 3};

  auto first = cont_21.begin();
  auto copy = first;

  EXPECT_EQ(first, copy);
}

TEST(Set_Iterator_int, MoveConstructor) {
  s21::set<int> cont_21{1, 2, 3};

  auto first = cont_21.begin();
  auto copy(std::move(first));

  EXPECT_EQ(1, *copy);
}

TEST(Set_Member_CustomClass, ArgConstructor) {
  TestUnit a{"ivanov", 1}, b{"petrov", 10}, c{"sidorov", 100};
  std::set<TestUnit> cont_orig{a, b, c};
  s21::set<TestUnit> cont_21{a, b, c};

  auto s21 = cont_21.begin();
  auto orig = cont_orig.begin();

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(*orig, *s21);
  EXPECT_EQ(*++orig, *++s21);
  EXPECT_EQ(*++orig, *++s21);
  EXPECT_EQ(++orig, cont_orig.end());
  EXPECT_EQ(++s21, cont_21.end());
}

TEST(Set_Member_CustomClass, ArgConstructorWithRepeat) {
  TestUnit a{"ivanov", 1};
  std::set<TestUnit> cont_orig{a, a, a};
  s21::set<TestUnit> cont_21{a, a, a};

  auto s21 = cont_21.begin();
  auto orig = cont_orig.begin();

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(*orig, *s21);
  EXPECT_EQ(++orig, cont_orig.end());
  EXPECT_EQ(++s21, cont_21.end());
}

TEST(Set_Modifier_CustomClass, Merge) {
  TestUnit a{"ivanov", 1}, b{"petrov", 10}, c{"sidorov", 100};
  std::set<TestUnit> cont_orig{a, b, c};
  s21::set<TestUnit> cont_21{a, b, c};

  TestUnit a2{"ivanov", 2}, b2{"petrov", 22}, c2{"sidorov", 222};
  std::set<TestUnit> cont_orig_2{a2, b2, c2};
  s21::set<TestUnit> cont_21_2{a2, b2, c2};

  cont_21.merge(cont_21_2);
  cont_orig.merge(cont_orig_2);

  auto s21 = cont_21.begin();
  auto orig = cont_orig.begin();

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(cont_orig_2.size(), cont_21_2.size());
  EXPECT_EQ(*s21, *orig);
  EXPECT_EQ(*(++s21), *(++orig));
  EXPECT_EQ(*(++s21), *(++orig));
  EXPECT_EQ(*(++s21), *(++orig));
  EXPECT_EQ(*(++s21), *(++orig));
  EXPECT_EQ(*(++s21), *(++orig));
  EXPECT_EQ(cont_orig.end(), ++orig);
  EXPECT_EQ(cont_21.end(), ++s21);
}

TEST(Set_Modifier_CustomClass, MergeSimilar) {
  TestUnit a{"ivanov", 1}, b{"petrov", 10}, c{"sidorov", 100};
  std::set<TestUnit> cont_orig{a, b, c};
  s21::set<TestUnit> cont_21{a, b, c};

  std::set<TestUnit> cont_orig_2{a, b, c};
  s21::set<TestUnit> cont_21_2{a, b, c};

  cont_21.merge(cont_21_2);
  cont_orig.merge(cont_orig_2);

  auto s21 = cont_21.begin();
  auto orig = cont_orig.begin();

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(*s21, *orig);
  EXPECT_EQ(*(++s21), *(++orig));
  EXPECT_EQ(*(++s21), *(++orig));
  EXPECT_EQ(cont_orig.end(), ++orig);
  EXPECT_EQ(cont_21.end(), ++s21);
}

TEST(Set_Modifier_CustomClass, CustomComparatorErase) {
  TestUnit a{"ivanov", 1}, b{"petrov", 10}, c{"sidorov", 100};
  std::set<TestUnit, TestUnitComparator> cont_orig{a, c, b};
  s21::set<TestUnit, TestUnitComparator> cont_21{a, c, b};

  size_t s21_erase = cont_21.erase(a);
  size_t orig_erase = cont_orig.erase(a);

  auto s21 = cont_21.begin();
  auto orig = cont_orig.begin();

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(orig_erase, s21_erase);
  EXPECT_EQ(*orig, *s21);
  EXPECT_EQ(*(++orig), *(++s21));
  EXPECT_EQ(++orig, cont_orig.end());
  EXPECT_EQ(++s21, cont_21.end());
}

TEST(Set_Modifier_CustomClass, CustomComparatorEraseRoot) {
  TestUnit a{"ivanov", 1}, b{"petrov", 10}, c{"sidorov", 100};
  std::set<TestUnit, TestUnitComparator> cont_orig{a, c, b};
  s21::set<TestUnit, TestUnitComparator> cont_21{a, c, b};

  size_t s21_erase = cont_21.erase(b);
  size_t orig_erase = cont_orig.erase(b);

  auto s21 = cont_21.begin();
  auto orig = cont_orig.begin();

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(orig_erase, s21_erase);
  EXPECT_EQ(*orig, *s21);
  EXPECT_EQ(*(++orig), *(++s21));
  EXPECT_EQ(++orig, cont_orig.end());
  EXPECT_EQ(++s21, cont_21.end());
}

TEST(Set_Member_CustomClass, CustomComparatorInsert) {
  TestUnit a{"ivanov", 1}, b{"petrov", 10}, c{"sidorov", 100};
  std::set<TestUnit, TestUnitComparator> cont_orig{a, c};
  s21::set<TestUnit, TestUnitComparator> cont_21{a, c};

  auto s21_ins = cont_21.insert(b);
  auto orig_ins = cont_orig.insert(b);

  auto s21 = cont_21.begin();
  auto orig = cont_orig.begin();

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(orig_ins.second, s21_ins.second);
  EXPECT_EQ(*orig, *s21);
  EXPECT_EQ(*++orig, *++s21);
  EXPECT_EQ(*++orig, *++s21);
  EXPECT_EQ(++orig, cont_orig.end());
  EXPECT_EQ(++s21, cont_21.end());
}

TEST(Set_Member_int, CompGreaterInsert) {
  std::set<int, std::greater<int>> cont_orig{1, 3, 5};
  s21::set<int, std::greater<int>> cont_21{1, 3, 5};

  auto s21_ins = cont_21.insert(2);
  auto orig_ins = cont_orig.insert(2);

  auto s21 = cont_21.begin();
  auto orig = cont_orig.begin();

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(orig_ins.second, s21_ins.second);
  EXPECT_EQ(*orig, *s21);
  EXPECT_EQ(*++orig, *++s21);
  EXPECT_EQ(*++orig, *++s21);
  EXPECT_EQ(*++orig, *++s21);
  EXPECT_EQ(++orig, cont_orig.end());
  EXPECT_EQ(++s21, cont_21.end());
}

TEST(Set_Member_int, CompGreaterErase) {
  std::set<int, std::greater<int>> cont_orig{1, 3, 5};
  s21::set<int, std::greater<int>> cont_21{1, 3, 5};

  auto s21_er = cont_21.erase(1);
  auto orig_er = cont_orig.erase(1);

  auto s21 = cont_21.begin();
  auto orig = cont_orig.begin();

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(orig_er, s21_er);
  EXPECT_EQ(*orig, *s21);
  EXPECT_EQ(*++orig, *++s21);
  EXPECT_EQ(++orig, cont_orig.end());
  EXPECT_EQ(++s21, cont_21.end());
}

TEST(Set_Member_int, CompGreaterEraseRoot) {
  std::set<int, std::greater<int>> cont_orig{1, 3, 5};
  s21::set<int, std::greater<int>> cont_21{1, 3, 5};

  auto s21_er = cont_21.erase(3);
  auto orig_er = cont_orig.erase(3);

  auto s21 = cont_21.begin();
  auto orig = cont_orig.begin();

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(orig_er, s21_er);
  EXPECT_EQ(*orig, *s21);
  EXPECT_EQ(*++orig, *++s21);
  EXPECT_EQ(++orig, cont_orig.end());
  EXPECT_EQ(++s21, cont_21.end());
}

TEST(Set_Member_int, CompLessEraseRoot) {
  std::set<int> cont_orig{1, 3, 5};
  s21::set<int> cont_21{1, 3, 5};

  auto s21_er = cont_21.erase(3);
  auto orig_er = cont_orig.erase(3);

  auto s21 = cont_21.begin();
  auto orig = cont_orig.begin();

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(orig_er, s21_er);
  EXPECT_EQ(*orig, *s21);
  EXPECT_EQ(*++orig, *++s21);
  EXPECT_EQ(++orig, cont_orig.end());
  EXPECT_EQ(++s21, cont_21.end());
}

TEST(Set_Member_int, InsertAfterClear) {
  std::set<int> cont_orig{1, 3, 5};
  s21::set<int> cont_21{1, 3, 5};

  cont_21.clear();
  cont_orig.clear();

  auto s21_ins = cont_21.insert(1);
  auto orig_ins = cont_orig.insert(1);

  auto s21 = cont_21.begin();
  auto orig = cont_orig.begin();

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(orig_ins.second, s21_ins.second);
  EXPECT_EQ(*orig, *s21);
  EXPECT_EQ(++orig, cont_orig.end());
  EXPECT_EQ(++s21, cont_21.end());
}

TEST(Set_Member_int, InsertAfterErase) {
  std::set<int> cont_orig{1};
  s21::set<int> cont_21{1};

  cont_21.erase(1);
  cont_orig.erase(1);

  auto s21_ins = cont_21.insert(1);
  auto orig_ins = cont_orig.insert(1);

  auto s21 = cont_21.begin();
  auto orig = cont_orig.begin();

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(orig_ins.second, s21_ins.second);
  EXPECT_EQ(*orig, *s21);
  EXPECT_EQ(++orig, cont_orig.end());
  EXPECT_EQ(++s21, cont_21.end());
}

TEST(Set_Modifier_int, InsertMany) {
  s21::set<int> cont_21;

  s21::vector<std::pair<s21::set<int>::iterator, bool>> result =
      cont_21.insert_many(1, 2, 3, 4, 5);
  s21::vector<std::pair<int, bool>> expect = {
      {2, true}, {1, true}, {4, true}, {3, true}, {5, true}};

  auto exp = expect.begin();

  EXPECT_EQ(cont_21.size(), result.size());
  for (auto elem : result) {
    EXPECT_EQ(*elem.first, exp->first);
    EXPECT_EQ(elem.second, exp->second);
    ++exp;
  }
}

TEST(Set_Modifier_int, InsertManySimilar) {
  s21::set<int> cont_21{1, 2, 3};

  s21::vector<std::pair<s21::set<int>::iterator, bool>> result =
      cont_21.insert_many(1, 2, 3);
  s21::vector<std::pair<int, bool>> expect = {
      {1, false}, {2, false}, {3, false}};

  auto exp = expect.begin();

  EXPECT_EQ(cont_21.size(), result.size());
  for (auto elem : result) {
    EXPECT_EQ(*elem.first, exp->first);
    EXPECT_EQ(elem.second, exp->second);
    ++exp;
  }
}

TEST(Set_Modifier_int, InsertManyWithRepeat) {
  s21::set<int> cont_21{1};

  s21::vector<std::pair<s21::set<int>::iterator, bool>> result =
      cont_21.insert_many(1, 1, 2);
  s21::vector<std::pair<int, bool>> expect = {
      {1, false}, {1, false}, {2, true}};

  auto exp = expect.begin();

  EXPECT_EQ(3, result.size());
  EXPECT_EQ(2, cont_21.size());
  for (auto elem : result) {
    EXPECT_EQ(*elem.first, exp->first);
    EXPECT_EQ(elem.second, exp->second);
    ++exp;
  }
}