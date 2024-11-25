#include "s21_tests.h"

TEST(QueueTest, DefaultConstructor) {
  s21::queue<int> queue;
  EXPECT_TRUE(queue.empty());
  EXPECT_EQ(queue.size(), 0);
}

TEST(QueueTest, InitializerListConstructor) {
  s21::queue<int> queue{1, 2, 3, 4, 5};
  EXPECT_EQ(queue.size(), 5);
  EXPECT_EQ(queue.front(), 1);
  EXPECT_EQ(queue.back(), 5);
}

TEST(QueueTest, CopyConstructor) {
  s21::queue<int> queue1{1, 2, 3};
  s21::queue<int> queue2(queue1);
  EXPECT_EQ(queue2.size(), 3);
  EXPECT_EQ(queue2.front(), 1);
  EXPECT_EQ(queue2.back(), 3);
}

TEST(QueueTest, MoveConstructor) {
  s21::queue<int> queue1{1, 2, 3};
  s21::queue<int> queue2(std::move(queue1));
  EXPECT_EQ(queue2.size(), 3);
  EXPECT_EQ(queue2.front(), 1);
  EXPECT_EQ(queue2.back(), 3);
  EXPECT_TRUE(queue1.empty());
}

TEST(QueueTest, AssignmentOperator) {
  s21::queue<int> queue1{1, 2, 3};
  s21::queue<int> queue2;
  queue2 = queue1;
  EXPECT_EQ(queue2.size(), 3);
  EXPECT_EQ(queue2.front(), 1);
  EXPECT_EQ(queue2.back(), 3);
}

TEST(QueueMoveAssignmentTest, MoveAssignmentOperator) {
  s21::queue<int> queue1;
  queue1.push(1);
  queue1.push(2);
  queue1.push(3);

  s21::queue<int> queue2;
  queue2 = std::move(queue1);

  EXPECT_EQ(queue2.front(), 1);
  queue2.pop();
  EXPECT_EQ(queue2.front(), 2);
  queue2.pop();
  EXPECT_EQ(queue2.front(), 3);
  EXPECT_EQ(queue2.size(), 1);

  EXPECT_EQ(queue1.size(), 0);
  EXPECT_EQ(queue1.empty(), true);
}

TEST(QueueMoveAssignmentTest, EmptyQueueMoveAssignment) {
  s21::queue<int> queue1;
  s21::queue<int> queue2;
  queue2.push(1);

  queue2 = std::move(queue1);
  EXPECT_TRUE(queue2.empty());
}

TEST(QueueMoveAssignmentTest, DifferentSizeQueues) {
  s21::queue<int> queue1;
  for (int i = 0; i < 5; ++i) {
    queue1.push(i);
  }

  s21::queue<int> queue2;
  queue2.push(100);

  queue2 = std::move(queue1);

  EXPECT_EQ(queue2.size(), 5);
  for (int i = 0; i < 5; ++i) {
    EXPECT_EQ(queue2.front(), i);
    queue2.pop();
  }
  EXPECT_TRUE(queue1.empty());
}

TEST(QueueTest, PushAndPop) {
  s21::queue<int> queue;
  queue.push(1);
  queue.push(2);
  queue.push(3);
  EXPECT_EQ(queue.size(), 3);
  EXPECT_EQ(queue.front(), 1);

  queue.pop();
  EXPECT_EQ(queue.size(), 2);
  EXPECT_EQ(queue.front(), 2);

  queue.pop();
  EXPECT_EQ(queue.size(), 1);
  EXPECT_EQ(queue.front(), 3);
}

TEST(QueueTest, Swap) {
  s21::queue<int> queue1{1, 2, 3};
  s21::queue<int> queue2{4, 5};
  queue1.swap(queue2);

  EXPECT_EQ(queue1.size(), 2);
  EXPECT_EQ(queue1.front(), 4);
  EXPECT_EQ(queue1.back(), 5);

  EXPECT_EQ(queue2.size(), 3);
  EXPECT_EQ(queue2.front(), 1);
  EXPECT_EQ(queue2.back(), 3);
}

TEST(QueueTest, EmptyQueue) {
  s21::queue<int> queue;
  EXPECT_TRUE(queue.empty());
  queue.push(1);
  EXPECT_FALSE(queue.empty());
  queue.pop();
  EXPECT_TRUE(queue.empty());
}

TEST(QueueTest, NonPrimitiveType) {
  s21::queue<std::string> queue;
  queue.push("Hello");
  queue.push("World");
  EXPECT_EQ(queue.front(), "Hello");
  EXPECT_EQ(queue.back(), "World");
  EXPECT_EQ(queue.size(), 2);
}

TEST(QueueTest, FrontAndBackModification) {
  s21::queue<int> queue{1, 2, 3};
  queue.front() = 10;
  queue.back() = 30;
  EXPECT_EQ(queue.front(), 10);
  EXPECT_EQ(queue.back(), 30);
}

TEST(QueueTest, MultipleOperations) {
  s21::queue<int> queue;
  for (int i = 0; i < 5; ++i) {
    queue.push(i);
  }
  EXPECT_EQ(queue.size(), 5);
  EXPECT_EQ(queue.front(), 0);
  EXPECT_EQ(queue.back(), 4);

  for (int i = 0; i < 3; ++i) {
    queue.pop();
  }
  EXPECT_EQ(queue.size(), 2);
  EXPECT_EQ(queue.front(), 3);
  EXPECT_EQ(queue.back(), 4);
}

TEST(QueueInsertManyBack, BasicTypes) {
  s21::queue<int> queue;
  queue.insert_many_back(1, 2, 3, 4, 5);

  EXPECT_EQ(queue.front(), 1);
  queue.pop();
  EXPECT_EQ(queue.front(), 2);
  queue.pop();
  EXPECT_EQ(queue.front(), 3);
  queue.pop();
  EXPECT_EQ(queue.front(), 4);
  queue.pop();
  EXPECT_EQ(queue.front(), 5);
}

TEST(QueueInsertManyBack, EmptyInsert) {
  s21::queue<int> queue;
  queue.insert_many_back();
  EXPECT_TRUE(queue.empty());
}

TEST(QueueInsertManyBack, SingleElement) {
  s21::queue<std::string> queue;
  queue.insert_many_back(std::string("test"));
  EXPECT_EQ(queue.front(), "test");
}

TEST(QueueInsertManyBack, MixedTypes) {
  s21::queue<std::string> queue;
  queue.insert_many_back("first", std::string("second"), "third");

  EXPECT_EQ(queue.front(), "first");
  queue.pop();
  EXPECT_EQ(queue.front(), "second");
  queue.pop();
  EXPECT_EQ(queue.front(), "third");
}

TEST(QueueInsertManyBack, InsertAfterPop) {
  s21::queue<int> queue;
  queue.push(1);
  queue.pop();
  queue.insert_many_back(2, 3, 4);

  EXPECT_EQ(queue.front(), 2);
  queue.pop();
  EXPECT_EQ(queue.front(), 3);
  queue.pop();
  EXPECT_EQ(queue.front(), 4);
}