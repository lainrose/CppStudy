#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> stack;

	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);

	cout << stack.top() << endl;

	stack.pop();
	stack.pop();

	while (!stack.empty())
	{
		cout << stack.top() << ' ';
		stack.pop();
	}

}
