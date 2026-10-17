#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

template <typename T1> class Stack
{
private:

	int top;
	vector <T1> stack;

public:

	Stack(){ top = -1; }
	void Push(T1);
	T1 Pop();
	int Size();
	void PrintStack (ofstream &);
};

template <class T1>
void Stack<T1>::Push(T1 added)
{
	top++;
	stack.push_back(added);
}

template <class T1>
T1 Stack<T1>::Pop()
{
	if (top == -1)
		return -1;
	T1 popped = stack[top];

	stack.pop_back();
	top--;
	return popped;
}

template <class T1>
int Stack<T1>::Size()
{
	return top+1;
}

template <class T1>
void Stack<T1>::PrintStack (ofstream &x)
{
	for (int i = top; i>=0; i--)
	{
		if (i == 0)
		{
			x << stack[i] << endl;
			break;
		}
		x << stack[i] << ", ";
	}
}

int main()
{
	Stack<float> IntStack;

	IntStack.Push(2.5);
	IntStack.Push(5.7);
	IntStack.Push(8.8);

	int test = IntStack.Pop();

	int size = IntStack.Size();

	ofstream file("something.txt");

	IntStack.PrintStack(file);

	return 0;
}
