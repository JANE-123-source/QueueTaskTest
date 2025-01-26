#include "pch.h"
#include "C:\Users\chian\source\repos\QueueTaskCode\QueueFunction.cpp"


// Test Case 1: Test if a new queue is empty
TEST(QueueTest, NewQueueIsInit) {

    Queue q;

    Queue_init(&q);

    EXPECT_EQ(-1, q.front);
    EXPECT_EQ(-1, q.rear); ;  // The queue should be empty initially
}

// Test Case 2: enqueue operation
TEST(QueueTest, Enqueue) {
    Queue q;
    Queue_init(&q);

    Queue_enqueue(&q, 10);
    EXPECT_FALSE(Queue_isEmpty(&q));
    EXPECT_EQ(q.front, 0);
    EXPECT_EQ(q.rear, 0);
    EXPECT_EQ(Queue_peek(&q), 10);

    Queue_enqueue(&q, 20);
    EXPECT_EQ(q.rear, 1);
    EXPECT_EQ(Queue_peek(&q), 10);  // The front element should still be 10
}

// Test Case 3: dequeue operation
TEST(QueueTest, Dequeue) {
    Queue q;
    Queue_init(&q);

    Queue_enqueue(&q, 10);
    Queue_enqueue(&q, 20);

    // Dequeue the first element
    Queue_dequeue(&q);
    EXPECT_EQ(q.front, 1);  // The front pointer should move to the next element
    EXPECT_EQ(q.rear, 1);   // The rear should still be 1
    EXPECT_EQ(Queue_peek(&q), 20);  // The front element should now be 20

}

// Test Case 4: Full queue scenario
TEST(QueueTest, FullQueue) {
    Queue q;
    Queue_init(&q);

    Queue_enqueue(&q, 10);
    Queue_enqueue(&q, 20);
    Queue_enqueue(&q, 30);
    Queue_enqueue(&q, 40);
    Queue_enqueue(&q, 50);
    Queue_enqueue(&q, 60);
    Queue_enqueue(&q, 70);
    Queue_enqueue(&q, 80);
    Queue_enqueue(&q, 90);
    Queue_enqueue(&q, 100);


    // Try to enqueue one more element, should fail because the queue is full
    Queue_enqueue(&q, 110);

    // Check that the size of the queue is still 5, and front and rear are correct
    EXPECT_EQ(q.rear, 9);  // Rear should be at the last element
    EXPECT_EQ(q.front, 0); // Front should still be 0
}
