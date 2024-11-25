#include <set>

#include "s21_test_class.h"
#include "s21_tests.h"

TEST(Multiset_Member_int, BaseConstructor) {
  std::multiset<int> cont_orig;
  s21::multiset<int> cont_21;

  EXPECT_EQ(cont_orig.empty(), cont_21.empty());
}

TEST(Multiset_Member_int, ArgConstructor) {
  int a = 1, b = 2, c = 3;
  std::multiset<int> cont_orig{a, a, b, b, c};
  s21::multiset<int> cont_21{a, a, b, b, c};

  EXPECT_EQ(cont_orig.size(), cont_21.size());
}

TEST(Multiset_Member_int, CopyConstructor) {
  int a = 1, b = 2, c = 3;
  s21::multiset<int> cont_21{a, b, c};
  s21::multiset<int> copy_21{cont_21};

  EXPECT_EQ(copy_21.size(), cont_21.size());
}

TEST(Multiset_Member_int, CopyAssignment) {
  int a = 1, b = 2, c = 3;
  s21::multiset<int> cont_21{a, b, c};
  s21::multiset<int> copy_21 = cont_21;
  auto copy_it = copy_21.begin();
  auto copy_it_end = copy_21.end();

  EXPECT_EQ(copy_21.size(), cont_21.size());
  EXPECT_EQ(*copy_it, a);
  EXPECT_EQ(*(++copy_it), b);
  EXPECT_EQ(*(++copy_it), c);
  EXPECT_EQ(*(++copy_it), *copy_it_end);
}

TEST(Multiset_Member_int, MoveConstructor) {
  int a = 1, b = 2, c = 3;
  s21::multiset<int> cont_21{a, b, c};
  s21::multiset<int> move_21(std::move(cont_21));

  EXPECT_EQ(move_21.size(), 3);
  EXPECT_EQ(cont_21.size(), 0);
  EXPECT_EQ(cont_21.empty(), true);
}

TEST(Multiset_Member_int, MoveAssigment) {
  int a = 1, b = 2;
  s21::multiset<int> cont_21{a, a, b};
  s21::multiset<int> move_21;
  move_21 = std::move(cont_21);

  EXPECT_EQ(move_21.size(), 3);
  EXPECT_EQ(cont_21.size(), 0);
  EXPECT_EQ(cont_21.empty(), true);
}

TEST(Multiset_Iterator_CustomClass, SomeOperator) {
  TestUnit a{"ivanov", 1};
  std::multiset<TestUnit> cont_orig{a};
  s21::multiset<TestUnit> cont_21{a};

  auto orig = cont_orig.begin();
  auto s21 = cont_21.begin();

  EXPECT_EQ(orig->name, s21->name);
  EXPECT_EQ(orig->level, s21->level);
}

TEST(Multiset_Iterator_int, Begin) {
  int a = 1, b = 2, c = 3;
  std::multiset<int> cont_orig{a, a, b, b, c};
  s21::multiset<int> cont_21{a, a, b, b, c};

  EXPECT_EQ(*cont_orig.begin(), *cont_21.begin());
}

TEST(Multiset_Iterator_int, AfterBeginPreinc) {
  int a = 1, b = 2, c = 3;
  std::multiset<int> cont_orig{a, a, b, b, c};
  s21::multiset<int> cont_21{a, a, b, b, c};

  EXPECT_EQ(*(++cont_orig.begin()), *(++cont_21.begin()));
}

TEST(Multiset_Iterator_int, AfterBeginPostinc) {
  int a = 1, b = 2, c = 3;
  std::multiset<int> cont_orig{a, a, b, b, c};
  s21::multiset<int> cont_21{a, a, b, b, c};

  auto orig = cont_orig.begin();
  auto s21 = cont_21.begin();
  orig++;
  s21++;  // cppcheck-suppress postfixOperator

  EXPECT_EQ(*orig, *s21);
}

TEST(Multiset_Iterator_int, EmptyBeginAndEnd) {
  std::multiset<int> cont_orig;
  s21::multiset<int> cont_21;

  EXPECT_EQ(cont_orig.empty(), cont_21.empty());
  EXPECT_EQ(cont_orig.end(), cont_orig.begin());
  EXPECT_EQ(cont_21.end(), cont_21.begin());
}

TEST(Multiset_Iterator_int, End) {
  int a = 1, b = 2, c = 3;
  s21::multiset<int> cont_21{a, b, c};

  EXPECT_EQ(0, *cont_21.end());
}

TEST(Multiset_Iterator_int, BeforeEndPreinc) {
  int a = 1, b = 2, c = 3;
  std::multiset<int> cont_orig{a, a, b, b, c};
  s21::multiset<int> cont_21{a, a, b, b, c};

  auto orig = --cont_orig.end();
  auto s21 = --cont_21.end();

  EXPECT_EQ(*orig, *s21);
}

TEST(Multiset_Iterator_int, BeforeEndPostinc) {
  int a = 1, b = 2, c = 3;
  std::multiset<int> cont_orig{a, a, b, b, c};
  s21::multiset<int> cont_21{a, a, b, b, c};

  auto orig = cont_orig.end();
  auto s21 = cont_21.end();
  orig--;
  s21--;  // cppcheck-suppress postfixOperator

  EXPECT_EQ(*orig, *s21);
}

TEST(Multiset_Modifier_int, EmptyClear) {
  std::multiset<int> cont_orig;
  s21::multiset<int> cont_21;

  cont_orig.clear();
  cont_21.clear();

  EXPECT_EQ(cont_orig.empty(), cont_21.empty());
  EXPECT_EQ(cont_orig.size(), cont_21.size());
}

TEST(Multiset_Modifier_int, Clear) {
  int a = 3, b = 2, c = 1;
  std::multiset<int> cont_orig{a, a, b, b, c};
  s21::multiset<int> cont_21{a, a, b, b, c};

  cont_orig.clear();
  cont_21.clear();

  EXPECT_EQ(cont_orig.empty(), cont_21.empty());
  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(cont_orig.begin(), cont_orig.end());
  EXPECT_EQ(cont_21.begin(), cont_21.end());
}

TEST(Multiset_Lookup_int, EmptyCount) {
  std::multiset<int> cont_orig;
  s21::multiset<int> cont_21;

  int orig = cont_orig.count(1);
  int s21 = cont_21.count(1);

  EXPECT_EQ(cont_orig.empty(), cont_21.empty());
  EXPECT_EQ(orig, s21);
}

TEST(Multiset_Lookup_int, Count) {
  int a = 1, b = 2, c = 3;
  std::multiset<int> cont_orig{a, a, a, b, b, c};
  s21::multiset<int> cont_21{a, a, a, b, b, c};

  int orig = cont_orig.count(1);
  int s21 = cont_21.count(1);

  EXPECT_EQ(orig, s21);
}

TEST(Multiset_Lookup_int, EmptyContains) {
  s21::multiset<int> cont_21;

  EXPECT_EQ(false, cont_21.contains(1));
}

TEST(Multiset_Lookup_int, Countains) {
  int a = 1, b = 2, c = 3;
  s21::multiset<int> cont_21{a, a, b, b, c};
  //! в multiset только с ++20

  EXPECT_EQ(true, cont_21.contains(1));
  EXPECT_EQ(true, cont_21.contains(2));
  EXPECT_EQ(true, cont_21.contains(3));
}

TEST(Multiset_Lookup_int, EmptyFind) {
  std::multiset<int> cont_orig;
  s21::multiset<int> cont_21;

  auto orig = cont_orig.find(1);
  auto s21 = cont_21.find(1);

  EXPECT_EQ(cont_orig.empty(), cont_21.empty());
  EXPECT_EQ(*orig, *s21);
}

TEST(Multiset_Lookup_int, Find) {
  int a = 1, b = 2, c = 3;
  std::multiset<int> cont_orig{a, a, a, b, b, c};
  s21::multiset<int> cont_21{a, a, a, b, b, c};

  auto orig = cont_orig.find(2);
  auto s21 = cont_21.find(2);

  EXPECT_EQ(*orig, *s21);
}

TEST(Multiset_Modifier_int, Swap) {
  int a = 1, b = 2, c = 3;
  s21::multiset<int> cont_21{a, b, c};
  s21::multiset<int> swap_21;
  swap_21.swap(cont_21);

  EXPECT_EQ(3, swap_21.size());
  EXPECT_EQ(0, cont_21.size());
  EXPECT_EQ(1, *swap_21.begin());
}

TEST(Multiset_Modifier_int, EraseByKeyDouble) {
  int a = 1, b = 2, c = 3;
  std::multiset<int> cont_orig{a, a, a, b, b, c};
  s21::multiset<int> cont_21{a, a, a, b, b, c};

  int orig = cont_orig.erase(2);
  int s21 = cont_21.erase(2);

  EXPECT_EQ(orig, s21);
  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(cont_orig.count(2), cont_21.count(2));
}

TEST(Multiset_Modifier_int, EmptyEraseByKey) {
  int a = 1, b = 2, c = 3;
  std::multiset<int> cont_orig{a, a, a, b, b, c};
  s21::multiset<int> cont_21{a, a, a, b, b, c};

  int orig = cont_orig.erase(4);
  int s21 = cont_21.erase(4);

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(orig, s21);
}

TEST(Multiset_Modifier_int, Merge) {
  s21::multiset<int> merge_21{1, 2, 3};
  s21::multiset<int> cont_21{4, 5, 6};
  std::multiset<int> merge_orig{1, 2, 3};
  std::multiset<int> cont_orig{4, 5, 6};

  merge_21.merge(cont_21);
  merge_orig.merge(cont_orig);

  EXPECT_EQ(merge_orig.size(), merge_21.size());
  EXPECT_EQ(cont_orig.size(), cont_21.size());
}

TEST(Multiset_Modifier_int, EmptyMerge) {
  s21::multiset<int> merge_21{1, 2, 3};
  s21::multiset<int> cont_21;
  std::multiset<int> merge_orig{1, 2, 3};
  std::multiset<int> cont_orig;

  merge_21.merge(cont_21);
  merge_orig.merge(cont_orig);

  EXPECT_EQ(merge_orig.size(), merge_21.size());
  EXPECT_EQ(cont_orig.size(), cont_21.size());
}

TEST(Multiset_Modifier_int, MergeInEmpty) {
  s21::multiset<int> merge_21;
  s21::multiset<int> cont_21{1, 1, 1};
  std::multiset<int> merge_orig;
  std::multiset<int> cont_orig{1, 1, 1};

  merge_21.merge(cont_21);
  merge_orig.merge(cont_orig);

  EXPECT_EQ(merge_orig.size(), merge_21.size());
  EXPECT_EQ(cont_orig.size(), cont_21.size());
}

TEST(Multiset_Modifier_int, MergeSimilar) {
  s21::multiset<int> merge_21{1, 2, 3};
  s21::multiset<int> cont_21{1, 2, 3};
  std::multiset<int> merge_orig{1, 2, 3};
  std::multiset<int> cont_orig{1, 2, 3};

  merge_21.merge(cont_21);
  merge_orig.merge(cont_orig);

  auto s21 = merge_21.begin();
  auto orig = merge_orig.begin();

  EXPECT_EQ(merge_orig.size(), merge_21.size());
  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(merge_orig.count(1), merge_21.count(1));
  EXPECT_EQ(merge_orig.count(2), merge_21.count(2));
  EXPECT_EQ(merge_orig.count(3), merge_21.count(3));
  EXPECT_EQ(*orig, *s21);
  EXPECT_EQ(*(++orig), *(++s21));
  EXPECT_EQ(*(++orig), *(++s21));
  EXPECT_EQ(*(++orig), *(++s21));
  EXPECT_EQ(*(++orig), *(++s21));
  EXPECT_EQ(*(++orig), *(++s21));
  EXPECT_EQ(merge_21.end(), ++s21);
}

TEST(Multiset_Modifier_int, InsertInEmpty) {
  s21::multiset<int> cont_21;

  auto res = cont_21.insert(10);

  EXPECT_EQ(1, cont_21.size());
  EXPECT_EQ(1, cont_21.contains(10));
  EXPECT_EQ(10, *res);
}

TEST(Multiset_Modifier_int, InsertSimilar) {
  int a = 1, b = 2, c = 3;
  std::multiset<int> cont_orig{a, b, c};
  s21::multiset<int> cont_21{a, b, c};

  auto s21 = cont_21.insert(b);
  auto orig = cont_orig.insert(b);

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(cont_orig.count(b), cont_21.count(b));
  EXPECT_EQ(*orig, *s21);
}

TEST(Multiset_Capasity_int, MaxSize) {
  s21::multiset<int> cont_21;

  auto res = cont_21.max_size();

  EXPECT_LT(1, res);
}

TEST(Multiset_Modifier_int, EraseByItDouble) {
  int a = 1, b = 2, c = 3;
  std::multiset<int> cont_orig{a, b, b, c};
  s21::multiset<int> cont_21{a, b, b, c};

  cont_orig.erase(cont_orig.find(2));
  cont_21.erase(cont_21.find(2));

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(cont_orig.count(2), cont_21.count(2));
}

TEST(Multiset_Modifier_int, EraseByIt) {
  int a = 1, b = 2, c = 3;
  std::multiset<int> cont_orig{a, b, c};
  s21::multiset<int> cont_21{a, b, c};

  cont_orig.erase(cont_orig.find(2));
  cont_21.erase(cont_21.find(2));

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(cont_orig.count(2), cont_21.count(2));
}

TEST(Multiset_Modifier_int, EmptyEraseByIt) {
  int a = 1, b = 2, c = 3;
  s21::multiset<int> cont_21{a, b, b, c};

  cont_21.erase(cont_21.find(4));

  EXPECT_EQ(4, cont_21.size());
}

TEST(Multiset_Modifier_int, EraseByConstIt) {
  int a = 1, b = 2, c = 3;
  std::multiset<int> cont_orig{a, a, b, c};
  s21::multiset<int> cont_21{a, a, b, c};

  cont_orig.erase(cont_orig.cbegin());
  cont_21.erase(cont_21.cbegin());

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(cont_orig.count(1), cont_21.count(1));
}

TEST(Multiset_Lookup_int, LowerBoundEmpty) {
  std::multiset<int> cont_orig;
  s21::multiset<int> cont_21;

  auto orig = cont_orig.lower_bound(1);
  auto s21 = cont_21.lower_bound(1);

  EXPECT_EQ(*orig, *s21);
}

TEST(Multiset_Iterator_int, ConstIterator) {
  s21::multiset<int> cont_21{1, 1, 2};

  s21::multiset<int>::const_iterator it = cont_21.cbegin();

  EXPECT_EQ(*it, 1);
  EXPECT_EQ(*++it, 1);
  EXPECT_EQ(*++it, 2);
  EXPECT_EQ(++it, cont_21.cend());
}

TEST(Multiset_Lookup_int, LowerBoundEqual) {
  int a = 1, b = 2, c = 3;
  std::multiset<int> cont_orig{a, a, a, b, b, c};
  s21::multiset<int> cont_21{a, a, a, b, b, c};

  auto orig = cont_orig.lower_bound(2);
  auto s21 = cont_21.lower_bound(2);

  EXPECT_EQ(*orig, *s21);
  EXPECT_EQ(*(++orig), *(++s21));
  EXPECT_EQ(*(++orig), *(++s21));
}

TEST(Multiset_Lookup_int, LowerBoundGreater) {
  int a = 1, b = 3, c = 4;
  std::multiset<int> cont_orig{a, a, a, b, b, c};
  s21::multiset<int> cont_21{a, a, a, b, b, c};

  auto orig = cont_orig.lower_bound(2);
  auto s21 = cont_21.lower_bound(2);

  EXPECT_EQ(*orig, *s21);
  EXPECT_EQ(*(++orig), *(++s21));
  EXPECT_EQ(*(++orig), *(++s21));
}

TEST(Multiset_Lookup_int, LowerBoundEnd) {
  int a = 1, b = 3, c = 4;
  std::multiset<int> cont_orig{a, a, a, b, b, c};
  s21::multiset<int> cont_21{a, a, a, b, b, c};

  auto orig = cont_orig.lower_bound(5);
  auto s21 = cont_21.lower_bound(5);

  EXPECT_EQ(cont_orig.end(), orig);
  EXPECT_EQ(cont_21.end(), s21);
  EXPECT_EQ(*(--orig), *(--s21));
}

TEST(Multiset_Lookup_int, BeginForMin) {
  int a = 1, b = 2;
  std::multiset<int> cont_orig{a, b, b};
  s21::multiset<int> cont_21{a, b, b};

  auto orig = cont_orig.begin();
  auto s21 = cont_21.begin();

  EXPECT_EQ(*orig, *s21);
}

TEST(Multiset_Lookup_int, LowerBoundBeforeFirst) {
  int a = 2, b = 3, c = 4;
  std::multiset<int> cont_orig{a, a, a, b, b, c};
  s21::multiset<int> cont_21{a, a, a, b, b, c};

  auto orig = cont_orig.lower_bound(1);
  auto s21 = cont_21.lower_bound(1);

  EXPECT_EQ(*orig, *s21);
}

TEST(Multiset_Lookup_int, UpperBoundEmpty) {
  std::multiset<int> cont_orig;
  s21::multiset<int> cont_21;

  auto orig = cont_orig.upper_bound(1);
  auto s21 = cont_21.upper_bound(1);

  EXPECT_EQ(*orig, *s21);
}

TEST(Multiset_Lookup_int, UpperBoundEqual) {
  int a = 1, b = 2, c = 3;
  std::multiset<int> cont_orig{a, a, a, b, b, c, c};
  s21::multiset<int> cont_21{a, a, a, b, b, c, c};

  auto orig = cont_orig.upper_bound(2);
  auto s21 = cont_21.upper_bound(2);

  EXPECT_EQ(*orig, *s21);
  EXPECT_EQ(*(++orig), *(++s21));
  EXPECT_EQ(cont_orig.end(), ++orig);
  EXPECT_EQ(cont_21.end(), ++s21);
}

TEST(Multiset_Lookup_int, UpperBoundGreater) {
  int a = 1, b = 3, c = 4;
  std::multiset<int> cont_orig{a, a, a, b, b, c};
  s21::multiset<int> cont_21{a, a, a, b, b, c};

  auto orig = cont_orig.upper_bound(2);
  auto s21 = cont_21.upper_bound(2);

  EXPECT_EQ(*orig, *s21);
}

TEST(Multiset_Lookup_int, UpperBoundEnd) {
  int a = 1, b = 3, c = 4;
  std::multiset<int> cont_orig{a, a, a, b, b, c};
  s21::multiset<int> cont_21{a, a, a, b, b, c};

  auto orig = cont_orig.upper_bound(5);
  auto s21 = cont_21.upper_bound(5);

  EXPECT_EQ(cont_orig.end(), orig);
  EXPECT_EQ(cont_21.end(), s21);
  EXPECT_EQ(*(--orig), *(--s21));
}

TEST(Multiset_Lookup_int, UpperBoundRoot) {
  std::multiset<int> cont_orig{5};
  s21::multiset<int> cont_21{5};

  auto orig = cont_orig.upper_bound(5);
  auto s21 = cont_21.upper_bound(5);

  EXPECT_EQ(cont_orig.end(), orig);
  EXPECT_EQ(cont_21.end(), s21);
}

TEST(Multiset_Lookup_int, LowerBoundRoot) {
  std::multiset<int> cont_orig{5};
  s21::multiset<int> cont_21{5};

  auto orig = cont_orig.lower_bound(5);
  auto s21 = cont_21.lower_bound(5);

  EXPECT_EQ(*orig, *s21);
}

TEST(Multiset_Lookup_int, UpperBoundBeforeRoot) {
  std::multiset<int> cont_orig{5};
  s21::multiset<int> cont_21{5};

  auto orig = cont_orig.upper_bound(4);
  auto s21 = cont_21.upper_bound(4);

  EXPECT_EQ(*orig, *s21);
}

TEST(Multiset_Lookup_int, LowerBoundAfterRoot) {
  std::multiset<int> cont_orig{5};
  s21::multiset<int> cont_21{5};

  auto orig = cont_orig.lower_bound(6);
  auto s21 = cont_21.lower_bound(6);

  EXPECT_EQ(cont_orig.end(), orig);
  EXPECT_EQ(cont_21.end(), s21);
}

TEST(Multiset_Lookup_int, RangeBounds) {
  int a = 1, b = 2, c = 3;
  std::multiset<int> cont_orig{a, a, a, b, b, c};
  s21::multiset<int> cont_21{a, a, a, b, b, c};

  auto orig = cont_orig.equal_range(2);
  auto s21 = cont_21.equal_range(2);

  EXPECT_EQ(*orig.first, *s21.first);
  EXPECT_EQ(*(++orig.first), *(++s21.first));
  EXPECT_EQ(*orig.second, *s21.second);
}

TEST(Multiset_Lookup_int, RangeBoundsFirst) {
  int a = 1, b = 2, c = 3;
  std::multiset<int> cont_orig{a, a, a, b, b, c};
  s21::multiset<int> cont_21{a, a, a, b, b, c};

  auto orig = cont_orig.equal_range(1);
  auto s21 = cont_21.equal_range(1);

  EXPECT_EQ(*orig.first, *s21.first);
  EXPECT_EQ(*orig.second, *s21.second);
}

TEST(Multiset_Lookup_int, RangeBoundsLast) {
  int a = 1, b = 2, c = 3;
  std::multiset<int> cont_orig{a, a, a, b, b, c};
  s21::multiset<int> cont_21{a, a, a, b, b, c};

  auto orig = cont_orig.equal_range(3);
  auto s21 = cont_21.equal_range(3);

  EXPECT_EQ(*orig.first, *s21.first);
  EXPECT_EQ(orig.second, cont_orig.end());
  EXPECT_EQ(s21.second, cont_21.end());
}

TEST(Multiset_Lookup_int, RangeBoundsEmpty) {
  std::multiset<int> cont_orig;
  s21::multiset<int> cont_21;

  auto orig = cont_orig.equal_range(3);
  auto s21 = cont_21.equal_range(3);

  EXPECT_EQ(*orig.first, *s21.first);
  EXPECT_EQ(orig.second, cont_orig.end());
  EXPECT_EQ(s21.second, cont_21.end());
}

TEST(Multiset_Lookup_int, RangeBoundsAfter) {
  int a = 1, b = 2, c = 3;
  std::multiset<int> cont_orig{a, a, a, b, b, c};
  s21::multiset<int> cont_21{a, a, a, b, b, c};

  auto orig = cont_orig.equal_range(4);
  auto s21 = cont_21.equal_range(4);

  EXPECT_EQ(orig.first, cont_orig.end());
  EXPECT_EQ(s21.first, cont_21.end());
  EXPECT_EQ(orig.second, cont_orig.end());
  EXPECT_EQ(s21.second, cont_21.end());
}

TEST(Multiset_Lookup_int, RangeBoundsBefore) {
  int a = 1, b = 2, c = 3;
  std::multiset<int> cont_orig{a, a, a, b, b, c};
  s21::multiset<int> cont_21{a, a, a, b, b, c};

  auto orig = cont_orig.equal_range(-10);
  auto s21 = cont_21.equal_range(-10);

  EXPECT_EQ(*orig.first, *s21.first);
  EXPECT_EQ(*orig.second, *s21.second);
}

TEST(Multiset_Lookup_int, RangeBoundsPair) {
  std::multiset<int> cont_orig{1, 2};
  s21::multiset<int> cont_21{1, 2};

  auto orig = cont_orig.equal_range(3);
  auto s21 = cont_21.equal_range(3);

  EXPECT_EQ(orig.first, cont_orig.end());
  EXPECT_EQ(s21.first, cont_21.end());
  EXPECT_EQ(orig.second, cont_orig.end());
  EXPECT_EQ(s21.second, cont_21.end());
}

TEST(Multiset_Iterator_int, ItNotEquals) {
  s21::multiset<int> cont_21{1, 2, 3};

  auto first = cont_21.begin();
  auto second = cont_21.find(2);
  auto end = cont_21.end();

  EXPECT_EQ(false, first == second);
  EXPECT_EQ(false, end == second);
  EXPECT_EQ(false, first == end);
}

TEST(Multiset_Iterator_int, ItEquals) {
  s21::multiset<int> cont_21{1, 2, 2, 3};

  auto first = cont_21.begin();
  auto second = cont_21.find(2);
  auto end = cont_21.end();

  ++first;
  ++first;
  --end;
  --end;

  EXPECT_EQ(true, first == second);
  EXPECT_EQ(true, end == second);
  EXPECT_EQ(true, first == end);
}

TEST(Multiset_Iterator_int, ItDubleEquals) {
  s21::multiset<int> cont_21{1, 1};
  std::multiset<int> cont_orig{1, 1};

  auto first = cont_21.begin();
  auto second = (++first);

  auto first_orig = cont_orig.begin();
  auto second_orig = (++first_orig);

  EXPECT_EQ(true, first == second);
  EXPECT_EQ(true, first_orig == second_orig);
}

TEST(Multiset_Iterator_int, CopyAssigment) {
  s21::multiset<int> cont_21{1, 2, 3};

  auto first = cont_21.begin();
  auto copy{first};

  EXPECT_EQ(first, copy);
}

TEST(Multiset_Iterator_int, CopyConstructor) {
  s21::multiset<int> cont_21{1, 2, 3};

  auto first = cont_21.begin();
  auto copy = first;

  EXPECT_EQ(first, copy);
}

TEST(Multiset_Iterator_int, MoveConstructor) {
  s21::multiset<int> cont_21{1, 2, 3};

  auto first = cont_21.begin();
  auto copy(std::move(first));

  EXPECT_EQ(1, *copy);
}

TEST(Multiset_Iterator_int, DecrementSimilar) {
  s21::multiset<int> cont_21{1, 1, 2, 2, 3, 3};

  auto s21 = cont_21.end();

  EXPECT_EQ(3, *(--s21));
  EXPECT_EQ(3, *(--s21));
  EXPECT_EQ(2, *(--s21));
  EXPECT_EQ(2, *(--s21));
  EXPECT_EQ(1, *(--s21));
  EXPECT_EQ(1, *(--s21));
  EXPECT_EQ(cont_21.begin(), s21);
}

TEST(Multiset_Member_CustomClass, ArgConstructor) {
  TestUnit a{"ivanov", 1}, b{"petrov", 10}, c{"sidorov", 100};
  std::multiset<TestUnit> cont_orig{a, b, c};
  s21::multiset<TestUnit> cont_21{a, b, c};

  auto s21 = cont_21.begin();
  auto orig = cont_orig.begin();

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(*orig, *s21);
  EXPECT_EQ(*++orig, *++s21);
  EXPECT_EQ(*++orig, *++s21);
  EXPECT_EQ(++orig, cont_orig.end());
  EXPECT_EQ(++s21, cont_21.end());
}

TEST(Multiset_Member_CustomClass, ArgConstructorWithRepeat) {
  TestUnit a{"ivanov", 1};
  std::multiset<TestUnit> cont_orig{a, a, a};
  s21::multiset<TestUnit> cont_21{a, a, a};

  auto s21 = cont_21.begin();
  auto orig = cont_orig.begin();

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(cont_orig.count(a), cont_21.count(a));
  EXPECT_EQ(*orig, *s21);
  EXPECT_EQ(*(++s21), *(++orig));
  EXPECT_EQ(*(++s21), *(++orig));
  EXPECT_EQ(++orig, cont_orig.end());
  EXPECT_EQ(++s21, cont_21.end());
}

TEST(Multiset_Modifier_CustomClass, Insert) {
  TestUnit a{"ivanov", 1}, b{"petrov", 10};
  std::multiset<TestUnit> cont_orig{a};
  s21::multiset<TestUnit> cont_21{a};

  cont_orig.insert(b);
  cont_21.insert(b);

  auto s21 = cont_21.begin();
  auto orig = cont_orig.begin();

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(cont_orig.count(b), cont_21.count(b));
  EXPECT_EQ(*s21, *orig);
  EXPECT_EQ(*(++s21), *(++orig));
  EXPECT_EQ(cont_orig.end(), ++orig);
  EXPECT_EQ(cont_21.end(), ++s21);
}

TEST(Multiset_Modifier_CustomClass, InsertSimilar) {
  TestUnit a{"ivanov", 1};
  std::multiset<TestUnit> cont_orig{a};
  s21::multiset<TestUnit> cont_21{a};

  cont_orig.insert(a);
  cont_21.insert(a);

  auto s21 = cont_21.begin();
  auto orig = cont_orig.begin();

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(cont_orig.count(a), cont_21.count(a));
  EXPECT_EQ(*s21, *orig);
  EXPECT_EQ(*(++s21), *(++orig));
  EXPECT_EQ(cont_orig.end(), ++orig);
  EXPECT_EQ(cont_21.end(), ++s21);
}

TEST(Multiset_Modifier_CustomClass, Erase) {
  TestUnit a{"ivanov", 1}, b{"petrov", 10}, c{"sidorov", 100};
  std::multiset<TestUnit> cont_orig{a, b, c};
  s21::multiset<TestUnit> cont_21{a, b, c};

  cont_21.erase(a);
  cont_orig.erase(a);

  auto s21 = cont_21.begin();
  auto orig = cont_orig.begin();

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(cont_orig.count(a), cont_21.count(a));
  EXPECT_EQ(*s21, *orig);
  EXPECT_EQ(*(++s21), *(++orig));
  EXPECT_EQ(cont_orig.end(), ++orig);
  EXPECT_EQ(cont_21.end(), ++s21);
}

TEST(Multiset_Modifier_CustomClass, EraseSimilar) {
  TestUnit a{"ivanov", 1};
  std::multiset<TestUnit> cont_orig{a, a, a};
  s21::multiset<TestUnit> cont_21{a, a, a};

  cont_21.erase(a);
  cont_orig.erase(a);

  auto s21 = cont_21.begin();
  auto orig = cont_orig.begin();

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(cont_orig.count(a), cont_21.count(a));
  EXPECT_EQ(cont_orig.end(), orig);
  EXPECT_EQ(cont_21.end(), s21);
}

TEST(Multiset_Modifier_CustomClass, Merge) {
  TestUnit a{"ivanov", 1}, b{"petrov", 10}, c{"sidorov", 100};
  std::multiset<TestUnit> cont_orig{a, b, c};
  s21::multiset<TestUnit> cont_21{a, b, c};

  TestUnit a2{"ivanov", 2}, b2{"petrov", 22}, c2{"sidorov", 222};
  std::multiset<TestUnit> cont_orig_2{a2, b2, c2};
  s21::multiset<TestUnit> cont_21_2{a2, b2, c2};

  cont_21.merge(cont_21_2);
  cont_orig.merge(cont_orig_2);

  auto s21 = cont_21.begin();
  auto orig = cont_orig.begin();
  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(cont_orig.count(b), cont_21.count(b));
  EXPECT_EQ(*s21, *orig);
  EXPECT_EQ(*(++s21), *(++orig));
  EXPECT_EQ(*(++s21), *(++orig));
  EXPECT_EQ(*(++s21), *(++orig));
  EXPECT_EQ(*(++s21), *(++orig));
  EXPECT_EQ(*(++s21), *(++orig));
  EXPECT_EQ(cont_orig.end(), ++orig);
  EXPECT_EQ(cont_21.end(), ++s21);
}

TEST(Multiset_Modifier_CustomClass, MergeSimilar) {
  TestUnit a{"ivanov", 1}, b{"petrov", 10}, c{"sidorov", 100};
  std::multiset<TestUnit> cont_orig{a, b, c};
  s21::multiset<TestUnit> cont_21{a, b, c};

  std::multiset<TestUnit> cont_orig_2{a, b, c};
  s21::multiset<TestUnit> cont_21_2{a, b, c};

  cont_21.merge(cont_21_2);
  cont_orig.merge(cont_orig_2);

  auto s21 = cont_21.begin();
  auto orig = cont_orig.begin();

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(cont_orig.count(a), cont_21.count(a));
  EXPECT_EQ(cont_orig.count(b), cont_21.count(b));
  EXPECT_EQ(cont_orig.count(c), cont_21.count(c));
  EXPECT_EQ(*s21, *orig);
  EXPECT_EQ(*(++s21), *(++orig));
  EXPECT_EQ(*(++s21), *(++orig));
  EXPECT_EQ(*(++s21), *(++orig));
  EXPECT_EQ(*(++s21), *(++orig));
  EXPECT_EQ(*(++s21), *(++orig));
  EXPECT_EQ(cont_orig.end(), ++orig);
  EXPECT_EQ(cont_21.end(), ++s21);
}

TEST(Multiset_Comparator, Comp) {
  TestUnit a{"ivanov", 1}, b{"petrov", 10}, c{"sidorov", 100};
  std::multiset<TestUnit, TestUnitComparator> cont_orig{a, b, c};
  s21::multiset<TestUnit, TestUnitComparator> cont_21{a, b, c};

  std::multiset<TestUnit, TestUnitComparator> cont_orig_2{a, b, c};
  s21::multiset<TestUnit, TestUnitComparator> cont_21_2{a, b, c};

  cont_21.merge(cont_21_2);
  cont_orig.merge(cont_orig_2);

  auto s21 = cont_21.begin();
  auto orig = cont_orig.begin();

  EXPECT_EQ(cont_orig.size(), cont_21.size());
  EXPECT_EQ(cont_orig.count(a), cont_21.count(a));
  EXPECT_EQ(cont_orig.count(b), cont_21.count(b));
  EXPECT_EQ(cont_orig.count(c), cont_21.count(c));
  EXPECT_EQ(*s21, *orig);
  EXPECT_EQ(*(++s21), *(++orig));
  EXPECT_EQ(*(++s21), *(++orig));
  EXPECT_EQ(*(++s21), *(++orig));
  EXPECT_EQ(*(++s21), *(++orig));
  EXPECT_EQ(*(++s21), *(++orig));
  EXPECT_EQ(cont_orig.end(), ++orig);
  EXPECT_EQ(cont_21.end(), ++s21);
}

TEST(Multiset_Iterator_int, ReverseIt) {
  s21::multiset<int> cont_21{1, 2, 2, 3, 3, 3, 4};
  std::multiset<int> cont_orig{1, 2, 2, 3, 3, 3, 4};

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

TEST(Multiset_Iterator_int, ConstReverseIt) {
  s21::multiset<int> cont_21{1, 2, 2, 3, 3, 3, 4};
  std::multiset<int> cont_orig{1, 2, 2, 3, 3, 3, 4};

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
  EXPECT_EQ(*s21_begin, *cont_21.cend());
}

TEST(Multiset_Modifier_int, InsertMany) {
  s21::multiset<int> cont_21;

  s21::vector<std::pair<s21::multiset<int>::iterator, bool>> result =
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

TEST(Multiset_Modifier_int, InsertManySimilar) {
  s21::multiset<int> cont_21{1, 2, 3};

  s21::vector<std::pair<s21::multiset<int>::iterator, bool>> result =
      cont_21.insert_many(1, 2, 3);
  s21::vector<std::pair<int, bool>> expect = {{1, true}, {2, true}, {3, true}};

  auto exp = expect.begin();

  EXPECT_EQ(3, result.size());
  EXPECT_EQ(6, cont_21.size());
  for (auto elem : result) {
    EXPECT_EQ(*elem.first, exp->first);
    EXPECT_EQ(elem.second, exp->second);
    ++exp;
  }
}

TEST(Multiset_Modifier_int, InsertManyWithRepeat) {
  s21::multiset<int> cont_21{1};

  s21::vector<std::pair<s21::multiset<int>::iterator, bool>> result =
      cont_21.insert_many(1, 1, 2);
  s21::vector<std::pair<int, bool>> expect = {{1, true}, {1, true}, {2, true}};

  auto exp = expect.begin();

  EXPECT_EQ(3, result.size());
  EXPECT_EQ(4, cont_21.size());
  for (auto elem : result) {
    EXPECT_EQ(*elem.first, exp->first);
    EXPECT_EQ(elem.second, exp->second);
    ++exp;
  }
}