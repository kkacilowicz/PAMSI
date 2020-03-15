#pragma once
class TabQueue
{
private:
	int capacity;
	int* Q;
	int front;
	int rear;

public:
	TabQueue(int cap) {
		capacity = cap;
		Q = new int[capacity];
			front = 0;
			rear = 0;
	}
	~TabQueue(){delete[] Q;}
	bool isEmpty() { return front==rear; }
	int size() { return ((capacity - front + rear)%capacity); }
	void enqueue(int e);
	int dequeue();
	int infront() { return Q[front]; }
	int cap(){return capacity;}
};



