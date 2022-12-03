#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Queue.h"
#include <iostream>

TEST_CASE("Queue") {
    Queue q;
    CHECK_EQ(q.size(), 0);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    CHECK_EQ(q.size(), 3);
    CHECK_EQ(q.get(0)->data, 3);
    CHECK_EQ(q.get(1)->data, 2);
    CHECK_EQ(q.get(2)->data, 1);
    CHECK_EQ(q.dequeue(), 1);
    CHECK_EQ(q.dequeue(), 2);
    q.enqueue(4);
    CHECK_EQ(q.dequeue(), 3);
    CHECK_EQ(q.dequeue(), 4);
}

