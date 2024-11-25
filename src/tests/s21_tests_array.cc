#include <cstddef>
#include <iterator>
#include <stdexcept>
#include <string>
#include <utility>

#include "s21_array.h"
#include "s21_tests.h"

TEST(Array, EmptyIterators1) {
  s21::array<int, 0> arr_empty;

  EXPECT_EQ(arr_empty.begin(), arr_empty.end());
  EXPECT_EQ(arr_empty.rbegin(), arr_empty.rend());
  EXPECT_EQ(arr_empty.cbegin(), arr_empty.cend());
  EXPECT_EQ(arr_empty.crbegin(), arr_empty.crend());
}

TEST(Array, EmptyIterators2) {
  auto arr_empty = s21::array<int, 0>();

  EXPECT_EQ(arr_empty.begin(), arr_empty.end());
  EXPECT_EQ(arr_empty.rbegin(), arr_empty.rend());
  EXPECT_EQ(arr_empty.cbegin(), arr_empty.cend());
  EXPECT_EQ(arr_empty.crbegin(), arr_empty.crend());
}

TEST(Array, EmptyIterators3) {
  const s21::array<int, 0> arr_empty;

  EXPECT_EQ(arr_empty.begin(), arr_empty.end());
  EXPECT_EQ(arr_empty.rbegin(), arr_empty.rend());
  EXPECT_EQ(arr_empty.cbegin(), arr_empty.cend());
  EXPECT_EQ(arr_empty.crbegin(), arr_empty.crend());
}

TEST(Array, EmptyIterators4) {
  const auto arr_empty = s21::array<int, 0>();

  EXPECT_EQ(arr_empty.begin(), arr_empty.end());
  EXPECT_EQ(arr_empty.rbegin(), arr_empty.rend());
  EXPECT_EQ(arr_empty.cbegin(), arr_empty.cend());
  EXPECT_EQ(arr_empty.crbegin(), arr_empty.crend());
}

TEST(Array, Empty) {
  auto arr_empty = s21::array<int, 0>();
  EXPECT_EQ(arr_empty.empty(), true);
}

TEST(Array, NotEmpty1) {
  auto arr_not_empty = s21::array<int, 10>();
  EXPECT_EQ(arr_not_empty.empty(), false);
}

TEST(Array, NotEmpty2) {
  auto arr_not_empty = s21::array<int, 1>();
  EXPECT_EQ(arr_not_empty.empty(), false);
}

TEST(Array, OperatorSquareBrackets1) {
  constexpr std::size_t test_size = 10;
  s21::array<int, test_size> arr{};

  for (std::size_t i = 0; i < test_size; ++i) {
    arr[i] = i;
    EXPECT_EQ(arr[i], i);
  }
}

TEST(Array, OperatorSquareBrackets2) {
  constexpr std::size_t test_size = 10;
  const s21::array<int, test_size> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  for (std::size_t i = 0; i < test_size; ++i) {
    EXPECT_EQ(arr[i], i);
  }
}

TEST(Array, At1) {
  constexpr std::size_t test_size = 10;
  const s21::array<int, test_size> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  for (std::size_t i = 0; i < test_size; ++i) {
    EXPECT_EQ(arr.at(i), i);
  }
}

TEST(Array, At2) {
  constexpr std::size_t test_size = 10;
  s21::array<int, test_size> arr;

  for (std::size_t i = 0; i < test_size; ++i) {
    arr.at(i) = i;
    EXPECT_EQ(arr.at(i), i);
  }
}

TEST(Array, At3) {
  constexpr std::size_t test_size = 10;
  const s21::array<int, test_size> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  EXPECT_THROW(arr.at(test_size), std::out_of_range);
}

TEST(Array, At4) {
  constexpr std::size_t test_size = 10;
  s21::array<int, test_size> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  EXPECT_THROW(arr.at(test_size), std::out_of_range);
}

TEST(Array, Front1) {
  const s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_EQ(arr.front(), 0);
}

TEST(Array, Front2) {
  s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_EQ(arr.front(), 0);
}

TEST(Array, Front3) {
  const s21::array<int, 1> arr = {9};
  EXPECT_EQ(arr.front(), 9);
}

TEST(Array, Front4) {
  s21::array<int, 1> arr = {9};
  EXPECT_EQ(arr.front(), 9);
}

TEST(Array, Back1) {
  const s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_EQ(arr.back(), 9);
}

TEST(Array, Back2) {
  s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_EQ(arr.back(), 9);
}

TEST(Array, Back3) {
  const s21::array<int, 1> arr = {9};
  EXPECT_EQ(arr.back(), 9);
}

TEST(Array, Back4) {
  s21::array<int, 1> arr = {9};
  EXPECT_EQ(arr.back(), 9);
}

TEST(Array, Data1) {
  const s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_EQ(arr.data(), arr.begin());
}

TEST(Array, Data2) {
  s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_EQ(arr.data(), arr.begin());
}

TEST(Array, Data3) {
  const s21::array<int, 0> arr;
  EXPECT_EQ(arr.data(), nullptr);
}

TEST(Array, Data4) {
  s21::array<int, 0> arr;
  EXPECT_EQ(arr.data(), nullptr);
}

TEST(Array, Fill1) {
  s21::array<int, 0> arr;
  EXPECT_NO_THROW(arr.fill(123));
}

TEST(Array, Fill2) {
  s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_NO_THROW(arr.fill(123));

  for (std::size_t i = 0; i < arr.size(); ++i) {
    EXPECT_EQ(arr.at(i), 123);
  }
}

TEST(Array, SwapMethod1) {
  s21::array<int, 0> arr;
  s21::array<int, 0> arr2;
  EXPECT_NO_THROW(arr.swap(arr2));
}

TEST(Array, SwapMethod2) {
  constexpr int arr_size = 10;
  s21::array<int, arr_size> arr{}, arr2{};

  for (std::size_t i = 0; i < arr.size(); ++i) {
    arr[i] = i;
    arr2[i] = arr_size - i;
  }

  arr.swap(arr2);

  for (std::size_t i = 0; i < arr.size(); ++i) {
    EXPECT_EQ(arr[i], arr_size - i);
    EXPECT_EQ(arr2[i], i);
  }
}

TEST(Array, SwapFunction1) {
  s21::array<int, 0> arr;
  s21::array<int, 0> arr2;
  EXPECT_NO_THROW(s21::swap(arr, arr2));
}

TEST(Array, SwapFunction2) {
  constexpr int arr_size = 10;
  s21::array<int, arr_size> arr{}, arr2{};

  for (std::size_t i = 0; i < arr.size(); ++i) {
    arr[i] = i;
    arr2[i] = arr_size - i;
  }

  s21::swap(arr, arr2);

  for (std::size_t i = 0; i < arr.size(); ++i) {
    EXPECT_EQ(arr[i], arr_size - i);
    EXPECT_EQ(arr2[i], i);
  }
}

TEST(Array, OperatorEq1) {
  s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21::array<int, 10> arr2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  EXPECT_EQ(arr, arr2);
}

TEST(Array, OperatorEq2) {
  s21::array<int, 0> arr;
  s21::array<int, 0> arr2;

  EXPECT_EQ(arr, arr2);
}

TEST(Array, OperatorEq3) {
  s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21::array<int, 10> arr2 = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

  EXPECT_FALSE(arr == arr2);
}

TEST(Array, OperatorNeq1) {
  s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21::array<int, 10> arr2 = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

  EXPECT_NE(arr, arr2);
}

TEST(Array, OperatorNeq2) {
  s21::array<int, 0> arr;
  s21::array<int, 0> arr2{};

  EXPECT_FALSE(arr != arr2);
}

TEST(Array, OperatorNeq3) {
  s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21::array<int, 10> arr2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  EXPECT_FALSE(arr != arr2);
}

TEST(Array, OperatorLt1) {
  s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21::array<int, 10> arr2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_FALSE(arr < arr2);
}

TEST(Array, OperatorLt2) {
  s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21::array<int, 10> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  EXPECT_LT(arr, arr2);
}

TEST(Array, OperatorLt3) {
  s21::array<int, 0> arr;
  s21::array<int, 0> arr2{};
  EXPECT_FALSE(arr < arr2);
}

TEST(Array, OperatorGt1) {
  s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21::array<int, 10> arr2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_FALSE(arr > arr2);
}

TEST(Array, OperatorGt2) {
  s21::array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::array<int, 10> arr2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_GT(arr, arr2);
}

TEST(Array, OperatorGt3) {
  s21::array<int, 0> arr;
  s21::array<int, 0> arr2{};
  EXPECT_FALSE(arr < arr2);
}

TEST(Array, OperatorLe1) {
  s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21::array<int, 10> arr2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_LE(arr, arr2);
  EXPECT_LE(arr2, arr);
}

TEST(Array, OperatorLe2) {
  s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21::array<int, 10> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  EXPECT_LE(arr, arr2);
  EXPECT_FALSE(arr2 <= arr);
}

TEST(Array, OperatorLe3) {
  s21::array<int, 0> arr;
  s21::array<int, 0> arr2{};
  EXPECT_LE(arr, arr2);
  EXPECT_LE(arr2, arr);
}

TEST(Array, OperatorGe1) {
  s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21::array<int, 10> arr2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_GE(arr, arr2);
  EXPECT_GE(arr2, arr);
}

TEST(Array, OperatorGe2) {
  s21::array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::array<int, 10> arr2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_GE(arr, arr2);
}

TEST(Array, OperatorGe3) {
  s21::array<int, 0> arr;
  s21::array<int, 0> arr2{};
  EXPECT_GE(arr, arr2);
  EXPECT_GE(arr2, arr);
}

TEST(Array, Get1) {
  s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_EQ(s21::get<5>(arr), 5);
}

TEST(Array, Get2) {
  const s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  const int t = s21::get<5>(arr);
  EXPECT_EQ(t, 5);
}

TEST(Array, Get3) {
  const s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  const int t = std::move(s21::get<5>(arr));
  EXPECT_EQ(t, 5);
}

TEST(Array, Get4) {
  s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int t = std::move(s21::get<5>(arr));
  EXPECT_EQ(t, 5);
}

TEST(Array, Get5) {
  s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21::get<5>(arr) = 55;
  EXPECT_EQ(arr[5], 55);
}

TEST(Array, Get6) {
  s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21::get<5>(arr) = std::move(55);
  EXPECT_EQ(arr[5], 55);
}

TEST(Array, Get7) {
  constexpr s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  constexpr int t = s21::get<5>(arr);
  EXPECT_EQ(t, 5);
}

TEST(Array, Get8) {
  s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int& t = s21::get<5>(arr);
  EXPECT_EQ(t, 5);
  t = 55;
  EXPECT_EQ(arr[5], 55);
}

TEST(Array, Get9) {
  const s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  const int& t = s21::get<5>(arr);
  EXPECT_EQ(t, 5);
  EXPECT_EQ(arr[5], 5);
}

TEST(Array, Get10) {
  s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int&& t = s21::get<2>(std::move(arr));
  EXPECT_EQ(t, 2);
}

TEST(Array, Get11) {
  const s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  const int&& t = s21::get<2>(std::move(arr));
  EXPECT_EQ(t, 2);
}

TEST(Array, IteratorBegin) {
  s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto it = arr.begin();
  *it = 123;
  EXPECT_EQ(*it, 123);
  EXPECT_EQ(*(it + 2), 2);
}

TEST(Array, IteratorCBegin) {
  s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  const auto it = arr.cbegin();
  EXPECT_EQ(*it, 0);
  EXPECT_EQ(*(it + 2), 2);
}

TEST(Array, IteratorEnd) {
  s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto it = arr.end();
  *(it - 1) = 123;
  EXPECT_EQ(*(it - 1), 123);
  EXPECT_EQ(*(it - 2), 8);
}

TEST(Array, IteratorCEnd) {
  s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  const auto it = arr.cend();
  EXPECT_EQ(*(it - 1), 9);
  EXPECT_EQ(*(it - 2), 8);
}

TEST(Array, IteratorRbegin1) {
  s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto it = arr.rbegin();
  *(it + 1) = 123;
  EXPECT_EQ(*(it + 1), 123);
  EXPECT_EQ(*(it + 2), 7);
}

TEST(Array, IteratorRbegin2) {
  const s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  const auto it = arr.rbegin();
  EXPECT_EQ(*(it + 1), 8);
  EXPECT_EQ(*(it + 2), 7);
}

TEST(Array, IteratorCRbegin) {
  s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  const auto it = arr.crbegin();
  EXPECT_EQ(*(it + 1), 8);
  EXPECT_EQ(*(it + 2), 7);
}

TEST(Array, IteratorRend1) {
  s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto it = arr.rend();
  *(it - 1) = 123;
  EXPECT_EQ(*(it - 1), 123);
  EXPECT_EQ(*(it - 2), 1);
}

TEST(Array, IteratorRend2) {
  const s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  const auto it = arr.rend();
  EXPECT_EQ(*(it - 1), 0);
  EXPECT_EQ(*(it - 2), 1);
}

TEST(Array, IteratorCRend) {
  const s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  const auto it = arr.crend();
  EXPECT_EQ(*(it - 1), 0);
  EXPECT_EQ(*(it - 2), 1);
}

TEST(Array, MaxSize) {
  s21::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_EQ(arr.max_size(), 10);
}