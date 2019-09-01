#include <iostream>
#include <forward_list>
#include <algorithm>

using namespace std;

int main()
{
	/*
	�� STD::forward_list ���
	std::list�� �����(double linked list)�̶�� std::forward_list�� �ܹ���(single linked list)�̴�.
	�ܹ��� ���� ����Ʈ�� ������� std::list���� �޸� ��뷮�̳� ó�� �ӵ��鿡�� ���� �����ϴ�.
	double linked list�� �ʿ��ϴٸ� std::list��, single linked list�ε� ����ϴٸ� std::forward_list�� ����Ѵ�.

	�� std::forward_list Ư¡
	�ٸ� STL �����̳ʿ� �ִ� size �Լ��� �������� �ʴ´�.
	size�� ������ ���� ���Ѵ�.->size_t size = std::distance(list.begin(), list.end())
	back() ���� ������

	�� std::forward_list�� std::list
	std::list�� ��������� �̵� ���������� std::forward_list�� �� �������θ� �̵��� �� �ִ�.
	std::list���� ���� / ���� �ӵ��� ���� �ణ �� ������.
	������� std::list�� ���� �޸𸮸� ���� ����Ѵ�.�� ��� �Ӹ��� �ƴ�, �����̳� ��ü ����� �� �۴�.
	���԰� ������ ������ ����� ���� ��ҿ� ���ؼ��� �����ϴ�.(�ܹ����̹Ƿ� �翬�ϴ�)
	������ ���⼺�� ���� ���� ������ std::list���� �����ϴ� insert�� erase�� �������� �ʴ´�.
	*/

	forward_list<int> list_1{ 1,2,3,4,5,6,7,8,9,10 };

	for_each(list_1.begin(), list_1.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	auto it = list_1.begin();
	list_1.emplace_after(it, 5);
	for_each(list_1.begin(), list_1.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	list_1.emplace_front(9);
	for_each(list_1.begin(), list_1.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	list_1.pop_front();
	for_each(list_1.begin(), list_1.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	list_1.erase_after(it, list_1.end());
	for_each(list_1.begin(), list_1.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	return 0;
}