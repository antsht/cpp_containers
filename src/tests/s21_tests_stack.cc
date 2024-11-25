#include "s21_tests.h"

using namespace s21;

TEST(StackTest, DefaultConstructor) {
  s21::stack<int> stack;
  EXPECT_TRUE(stack.empty());
  EXPECT_EQ(stack.size(), 0);
}

TEST(StackTest, InitializerListConstructor) {
  s21::stack<int> stack{1, 2, 3, 4, 5};
  EXPECT_EQ(stack.size(), 5);
  EXPECT_EQ(stack.top(), 5);
}

TEST(StackTest, CopyConstructor) {
  s21::stack<int> stack1{1, 2, 3};
  s21::stack<int> stack2(stack1);
  EXPECT_EQ(stack1.size(), stack2.size());
  while (!stack1.empty()) {
    EXPECT_EQ(stack1.top(), stack2.top());
    stack1.pop();
    stack2.pop();
  }
}

TEST(StackTest, MoveConstructor) {
  s21::stack<int> stack1{1, 2, 3};
  size_t original_size = stack1.size();
  s21::stack<int> stack2(std::move(stack1));
  EXPECT_EQ(stack2.size(), original_size);
  EXPECT_TRUE(stack1.empty());
}

TEST(StackTest, AssignmentOperator) {
  s21::stack<int> stack1{1, 2, 3};
  s21::stack<int> stack2;
  stack2 = stack1;
  EXPECT_EQ(stack1.size(), stack2.size());
  while (!stack1.empty()) {
    EXPECT_EQ(stack1.top(), stack2.top());
    stack1.pop();
    stack2.pop();
  }
}

TEST(StackTest, MoveAssignmentOperator) {
  s21::stack<int> stack1{1, 2, 3};
  s21::stack<int> stack2;
  size_t original_size = stack1.size();
  stack2 = std::move(stack1);
  EXPECT_EQ(stack2.size(), original_size);
  EXPECT_TRUE(stack1.empty());
}

TEST(StackTest, PushAndTop) {
  s21::stack<std::string> stack;
  stack.push("first");
  stack.push("second");
  EXPECT_EQ(stack.top(), "second");
  EXPECT_EQ(stack.size(), 2);
}

TEST(StackTest, PopAndEmpty) {
  s21::stack<double> stack;
  stack.push(1.1);
  stack.push(2.2);
  stack.pop();
  EXPECT_EQ(stack.top(), 1.1);
  stack.pop();
  EXPECT_TRUE(stack.empty());
}

TEST(StackTest, Swap) {
  s21::stack<int> stack1{1, 2, 3};
  s21::stack<int> stack2{4, 5};
  stack1.swap(stack2);
  EXPECT_EQ(stack1.size(), 2);
  EXPECT_EQ(stack2.size(), 3);
  EXPECT_EQ(stack1.top(), 5);
  EXPECT_EQ(stack2.top(), 3);
}

TEST(StackTest, InsertManyBack) {
  s21::stack<int> stack;
  stack.insert_many_back(1, 2, 3, 4, 5);

  EXPECT_EQ(stack.top(), 5);
  stack.pop();
  EXPECT_EQ(stack.top(), 4);
  stack.pop();
  EXPECT_EQ(stack.top(), 3);
  stack.pop();
  EXPECT_EQ(stack.top(), 2);
  stack.pop();
  EXPECT_EQ(stack.top(), 1);
}

TEST(StackTest, InsertManyBackEmpty) {
  s21::stack<int> stack;
  stack.insert_many_back();
  EXPECT_TRUE(stack.empty());
}

TEST(StackTest, InsertManyBackSingle) {
  s21::stack<int> stack;
  stack.insert_many_back(42);
  EXPECT_EQ(stack.top(), 42);
  EXPECT_EQ(stack.size(), 1);
}

TEST(StackTest, InsertManyBackDifferentTypes) {
  s21::stack<std::string> stack;
  stack.insert_many_back("hello", "world", "test");

  EXPECT_EQ(stack.top(), "test");
  stack.pop();
  EXPECT_EQ(stack.top(), "world");
  stack.pop();
  EXPECT_EQ(stack.top(), "hello");
}

TEST(StackTest, InsertManyBackExistingElements) {
  s21::stack<int> stack;
  stack.push(1);
  stack.push(2);
  stack.insert_many_back(3, 4, 5);

  EXPECT_EQ(stack.top(), 5);
  stack.pop();
  EXPECT_EQ(stack.top(), 4);
  stack.pop();
  EXPECT_EQ(stack.top(), 3);
  stack.pop();
  EXPECT_EQ(stack.top(), 2);
  stack.pop();
  EXPECT_EQ(stack.top(), 1);
}
