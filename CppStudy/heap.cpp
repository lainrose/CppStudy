#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> v1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for_each(v1.begin(), v1.end(), [](int& n) { cout << n << ' ';});
	
	cout << endl;

	make_heap(v1.begin(), v1.end());    // �ִ� ��
	for_each(v1.begin(), v1.end(), [](int& n) { cout << n << ' '; });

	cout << endl;

	make_heap(v1.begin(), v1.end(), [](int t1, int t2) {return t1 < t2; }); // �ִ� ��, ���ٵ� ��� ����
	for_each(v1.begin(), v1.end(), [](int& n) { cout << n << ' '; });

	cout << endl;

	v1.push_back(100);
	push_heap(v1.begin(), v1.end()); // �ִ� ���� 100
	for_each(v1.begin(), v1.end(), [](int& n) { cout << n << ' '; });

	cout << endl;

	pop_heap(v1.begin(), v1.end());
	v1.back();		// ���� �ִ�(10) �� �����ɴϴ�.
	v1.pop_back();	// �ִ��� �����մϴ�.
	for_each(v1.begin(), v1.end(), [](int& n) { cout << n << ' '; });

	cout << endl;

	random_shuffle(v1.begin(), v1.end());
	for_each(v1.begin(), v1.end(), [](int& n) { cout << n << ' '; });

	cout << endl;

	//sort_heap(v1.begin(), v1.end()); //����...����
	for_each(v1.begin(), v1.end(), [](int& n) { cout << n << ' '; });

	cout << endl;

	return 0;
}