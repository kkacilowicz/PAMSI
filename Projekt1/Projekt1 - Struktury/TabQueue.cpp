#include "TabQueue.h"
#include <iostream>
using namespace std;


void TabQueue::enqueue(int e) {

	if (size()==capacity-1)
	{
		int* A;
		A = new int[capacity * 2];
		
		if (rear<front)
		{
			int i = 0;
			while (front<capacity)
			{
				A[i++] = Q[front++];
			}
			if (rear!=0)
			{
				int j = 0;
				while (j<rear)
				{
					A[i++] = Q[j++];
				}
			}
		}
		else if (rear>front)
		{
			int i = 0;
			while (front<rear)
			{
				A[i++]=Q[front++];
			}
		}



		front = 0;
		rear = capacity-1;
		delete[]Q;
		Q = A;
		
		capacity = (capacity * 2);
	}
	Q[rear] = e;
	if (rear==(capacity-1))
	{
		rear = 0;
	}
	else
	{
		rear = rear + 1;
	}
}


int TabQueue::dequeue() {
	if (isEmpty())
	{
		cout << "Kolejka pusta" << endl;
	}
	int tmp = Q[front];
	if (front==(capacity-1))
	{
		front = 0;
	}
	else
	{
		front = front + 1;
	}

	return tmp;


}

