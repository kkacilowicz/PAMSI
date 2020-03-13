#include "TabStack.h"
#include <iostream>

int TabStack::pop()
{
    return S[top--];
}

void TabStack::push(int e)
{
	if (top==(capacity-1))
	{
		int* A;
		A = new int[capacity * 2];
		for (int i = 0; i < capacity; i++)
		{
			A[i] = S[i];
			
		}
		delete []S;
		S = A;
		capacity = (capacity * 2);
	}
	top++;
	S[top] = e;

}

void TabStack::display()
{
	for (int i = 0; i <= top; i++)
	{
		std::cout << S[i] << " "; 
	}
	std::cout << " \n";
}
