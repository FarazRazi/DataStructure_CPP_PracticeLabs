#include "pch.h"
#include "Header.h"

TEST(TestEnqueue, T1) {
	Queue < int> obj;
	for (int i = 2; i <= 10; i = i + 2) {
		obj.enqueue(i);
		EXPECT_EQ(i, obj.getRear()->getData());
	}

}
TEST(TestDequeue, T2) {
	Queue < int> obj;
	for (int i = 2; i <= 10; i = i + 2) {
		obj.enqueue(i);

	}
	for (int i = 10; i <= 2; i = i - 2) {
		obj.dequeue();
		EXPECT_EQ(i, obj.Front());
	}

}
TEST(TestIsEmpty, T3) {
	Queue < int> obj;
	obj.enqueue(3);
	EXPECT_EQ(false, obj.isEmpty());

	obj.dequeue();
	EXPECT_EQ(true, obj.isEmpty());

}
TEST(TestRoundRobin, T4) {

	Queue <Task> q1;
	//Queue <Task> q2;
	Task t1(1, 50);
	Task t2(2, 30);
	Task t3(3, 80);
	Task t4(4, 100);

	q1.enqueue(t1);
	q1.enqueue(t2);
	q1.enqueue(t3);
	q1.enqueue(t4);
	roundRobin(q1, 30);


}

TEST(TestQueueConcat, T5) {

	string str = "Data Structures and Algorithms";
	Queue<char>obj = queueConcat(str);
	int i = 0;
	while (!obj.isEmpty() && i != str.length()) {
		if (str[i] != ' ') {
			EXPECT_EQ(str[i], obj.Front());
			obj.dequeue();

		}i++;
	}


}