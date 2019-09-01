#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	/*
	 * ���� ���� ����Ʈ(doubly linked list)��� �����ϸ� �˴ϴ�.
	 * list�� ������ �����̳ʷ� ������ �����̳ʰ� ���� ��� Ư¡�� ���´�.
	 * list�� ��� ��� �����̳ʷ� at()��[] �����ڰ� ������ ���� ���� �ݺ��ڰ� �ƴ� ����� �ݺ��ڸ� �����Ѵ�.
	 * �׷��� ��� ���Ҹ� Ž���Ϸ��� ����� �ݺ����� ������++, --�� ����Ѵ�.

	 * list�� ���� ū Ư¡ �� �ϳ��� �� ���� �߰��� ���Ҹ� ����(insert), ����(erase) �ϴ��� ��� �ð� ���⵵�� ���� ������ ���δٴ� ���̴�.
	 * �迭 ��� �����̳� vector �� deque ó�� ���Ҹ� �о�� �ʰ� ��带 ���� �����ϱ⸸ �Ǳ� �����̴�.
	 * ���� ��� ��� �����̳��� ���԰� ���� ������ �ݺ��ڸ� ��ȿȭ��Ű�� �ʴ´�.
	 * �ݺ��ڰ� ����Ű�� ���� ��ü�� ���ŵ��� �ʴ� �� �ݺ��ڰ� ����Ű�� ���Ҵ� �״�� �����Ѵ�.

	 * ������, �迭 ��� �����̳�(vector, deque)�� �ݺ��ڴ� ������ ���԰� ���� ������ �߻��ϸ� �޸𸮰� ���Ҵ�ǰų� ���Ұ� �̵��� �� �����Ƿ� �ݺ��ڰ� ��ȿȭ�ȴ�.
	 * ��� ��� �����̳ʷ� insert()�� erase()�� �迭 ��ݺ��� ȿ�������� �����ϸ� ���� �񱳷� ���Ҹ� �����ϴ� remove(), remove_if()�� �����Ѵ�.

	 * ���� list�� �ٸ� list�� ������ �� ���� �����̳��̴�.splice() ��� �Լ��� ����� ���� ���길���� �� list�� �ϳ��� ����Ʈ�� ������ �� ������, merge() ��� �Լ��� �� list�� �ϳ��� list�� �����ϸ� �����Ѵ�.
	 * ���� ����� ����� �����ϴ� reverse(), sort(), unique()���� ��� �Լ��� �����Ѵ�.
	 */

	list<int> list_1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	list<int> list_2(list_1);

	// list_2�� list_1�� �պ�/�����Ѵ�. -> list�� ������������ �ݵ�� ���ĵǾ��־�� �Ѵ�.
	// �׷��� ������ ��������.
	list_1.merge(list_2);
	for_each(list_1.begin(), list_1.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	// �������
	for_each(list_2.begin(), list_2.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	// �ش� ���Ҹ� ��� ����
	list_1.remove(10);
	for_each(list_1.begin(), list_1.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	// ���ǿ� �´� ���Ҹ� ��� ����
	list_1.remove_if([](int n) {return n < 5; });
	for_each(list_1.begin(), list_1.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	// �ߺ�����
	list_1.unique();
	for_each(list_1.begin(), list_1.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	// ��������
	list_1.sort(greater<int>());
	for_each(list_1.begin(), list_1.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	// ��������
	list_1.sort();
	for_each(list_1.begin(), list_1.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	list_2 = list_1;
	for_each(list_2.begin(), list_2.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	// list_1�� it���� list2�� �߶� ����
	auto it = list_1.begin();
	it++;
	list_1.splice(it, list_2);
	for_each(list_1.begin(), list_1.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	// �������
	for_each(list_2.begin(), list_2.end(), [](int n) {cout << n << ' '; });
	cout << endl;


	return 0;
}

