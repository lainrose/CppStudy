#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Rect
{
public:
	int w, h;

	Rect(int w, int h)
	{
		this->w = w;
		this->h = h;
	}

	bool operator > (const Rect& rect) const { return w * h > rect.w * rect.h; }

};

int main()
{
	priority_queue<Rect, vector<Rect>, greater<Rect>> queue;

	queue.push(Rect(1,5));
	queue.push(Rect(7, 6));
	queue.push(Rect(1, 2));
	queue.push(Rect(3, 4));
	queue.push(Rect(8, 2));


	while (!queue.empty())
	{
		auto i = queue.top();
		cout << i.w << "," << i.h << endl;
		queue.pop();
	}

	return 0;
}
