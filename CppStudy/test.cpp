#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v;

	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.reserve(6);

	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);

	cout << v.size() << endl;
	cout << v.capacity() << endl;

	cout << "resize()" << endl;
	v.resize(5);
	for (auto& i : v)
	{
		cout << i << endl;
	}

	cout << v.size() << endl;
	cout << v.capacity() << endl;

	cout << "reserve()" << endl;
	v.reserve(4);
	for (auto& i : v)
	{
		cout << i << endl;
	}

	cout << v.size() << endl;
	cout << v.capacity() << endl;

	cout << "v2" << endl;
	vector<int> v2;

	for (int i = 0; i < 20; i++)
	{
		v2.push_back(1);
		cout << v2.size() << " " << v2.capacity() << endl;
	}

	cout << "iter_test" << endl;
	vector<int>::const_iterator iter;

	for (iter = v.begin(); iter != v.end(); iter++)
	{
		cout << *iter << endl;
	}



	return 0;
}

