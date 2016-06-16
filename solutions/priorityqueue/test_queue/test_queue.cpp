#include "gtest.h"
#include "priorityqueue.h"
Data** createData() {
  Data **data = new Data*[10];
  for (int i = 0; i < 10; i++) {
    data[i] = new Data;
    data[i]->priorities = 10 - i;
  }
  return data;
}

TEST(PRIORITY_QUEUE, can_create_empty_queue) {
  ASSERT_NO_THROW(PriorityQueue *q = new PriorityQueue());
}

TEST(PRIORITY_QUEUE, can_create_copied_queue) {
  Data **data = createData();
  PriorityQueue *q = new PriorityQueue(data, 10);
  ASSERT_NO_THROW(PriorityQueue *nq = new PriorityQueue(*q));
}

TEST(PRIORITY_QUEUE, can_push_new_element) {
  PriorityQueue *q = new PriorityQueue();
  Data *key = new Data;
  key->priorities = 2;
  ASSERT_NO_THROW(q->push(key));
}

TEST(PRIORITY_QUEUE, can_pop_element) {
  Data **data = createData();
  PriorityQueue *q = new PriorityQueue(data, 10);
  ASSERT_NO_THROW(q->pop());
}

TEST(PRIORITY_QUEUE, isEmpty_when_queue_is_empty) {
  PriorityQueue *q = new PriorityQueue();
  bool f;
  if (q->isEmpty())
    f = true;
  else
    f = false;
  EXPECT_EQ(true, f);
}

TEST(PRIORITY_QUEUE, isEmpty_when_queue_is_not_empty) {
  PriorityQueue *q = new PriorityQueue();
  Data* key = new Data();
  key->priorities = 1;
  q->push(key);
  bool f;
  if (q->isEmpty())
    f = true;
  else
    f = false;
  EXPECT_EQ(false, f);
}

TEST(PRIORITY_QUEUE, isFull_when_queue_is_full) {
  Data **data = new Data*[maxSize];
  for (int i = 0; i < maxSize; i++) {
    data[i] = new Data;
    data[i]->priorities = maxSize - i;
  }
  PriorityQueue *q = new PriorityQueue(data, maxSize);
  bool f;
  if (q->isFull())
    f = true;
  else
    f = false;
  EXPECT_EQ(true, f);
}

TEST(PRIORITY_QUEUE, isFull_when_queue_is_not_full) {
  Data **data = createData();
  PriorityQueue *q = new PriorityQueue(data, 10);
  ASSERT_FALSE(q->isFull());
}
