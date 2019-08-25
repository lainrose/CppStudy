#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	/*
		�� std::deque Ư¡
		ũ�Ⱑ �������̴�. (��� std::array�� ������ ���� ��� STL �����̳��� Ư¡�̴�.)
		��(front)�� ��(back)������ ����, ���� ������ ������ �߰������� ����, ������ �״��� ���� �ʴ�.
		std::deque�� Stack�� Queue�� ���յ� �ڷᱸ���ν� ���� ����Ʈ���� �����ϱⰡ ��ƴ�.
		std::vectoró�� ���� �׼����� �����ϴ�.

		�� std::deque�� std::vector
		std::deque�� std::vector�� ��� �Լ� ����̳� ��� ����� ���� �����ϴ�.
		std::vector�� ��(back)������ ����, ���� ������ ������ std::deque�� ��(front), ��(back), ��ο��� ����.
		std::deque�� ��, �� ����, ���� ������ ������ �ٸ� ��ġ������ ����, ������ std::vector�� �� ����.

		ó���� �� ���� �߰��� ������ ���԰� ������ ����ϰ� ����Ѵٸ� ��ũ ���ٴ� ����Ʈ(list)�� ����ϴ� ���� ��õ�Ѵ�.
		deque�� �հ� �ڿ��� ���԰� ���� ������ vector���� �� ����.
		deque�� �հ� �� ����, ������ ������ ����� vector���� ������ ���� ���ϴ�.
	*/

	deque<int> dq({ 1, 2, 3, 4, 5 });

	for_each(dq.begin(), dq.end(), [](int n) {cout << n << endl; });

	dq.emplace_front(1);
	dq.emplace_front(2);

	for_each(dq.begin(), dq.end(), [](int n) {cout << n << endl; });

	deque<int>::iterator iter;
	deque<int>::iterator iter2;

	for (iter = dq.begin(); iter != dq.end(); ++iter) {
		cout << *iter << ' ';
	}
	cout << endl;

	iter = dq.begin() + 2;            // dq�� 3��° ���ҿ� ����
	iter2 = dq.insert(iter, 500);    // 3��° ���� �ڸ��� 500�� �����Ѵ�.
	cout << *iter2 << endl;

	for_each(dq.begin(), dq.end(), [](int n) {cout << n << endl; });

	return 0;
}

