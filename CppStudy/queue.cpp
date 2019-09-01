#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> queue;

	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
	queue.push(5);

	cout << queue.front() << endl;
	cout << queue.back() << endl;

	queue.pop();

	while (!queue.empty())
	{
		cout << endl;
		cout << queue.front() << ' ';
		cout << queue.back() << ' ';
		queue.pop();
	}

}
