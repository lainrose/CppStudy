#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// �Ϲ� for�� (for statement)
	const int index = 5;
	int arr[index] = {0, 1, 2, 3, 4};
	for (int i = 0; i < index; i++)
	{
		cout << i << endl;
	}

	int fibonacci[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

	// ���� ��� for�� (Ranged-based for loops)
	for (int number : fibonacci)
	{
		cout << number << endl;
	}

	// auto�� Ȱ���� ���� ��� for�� (Ranged-based for loops and the auto keyword)
	for (auto number : fibonacci)
	{
		cout << number << endl;
	}

	// �� ���� ���� (Not Copy)
	for (auto& number : fibonacci)
	{
		cout << number << endl;
	}

	// �б� ���� (Read Only)
	for (const auto& number : fibonacci)
	{
		cout << number << endl;
	}

	// �迭�� �ƴ� ���� ��� for�� (Ranged-based for loops and non-arrays)
	vector<int> fibonacci_vec = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
	for (const auto& number : fibonacci_vec)
	{
		cout << number << endl;
	}

	return 0;
}

