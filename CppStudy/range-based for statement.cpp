#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// 일반 for문 (for statement)
	const int index = 5;
	int arr[index] = {0, 1, 2, 3, 4};
	for (int i = 0; i < index; i++)
	{
		cout << i << endl;
	}

	int fibonacci[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

	// 범위 기반 for문 (Ranged-based for loops)
	for (int number : fibonacci)
	{
		cout << number << endl;
	}

	// auto를 활용한 범위 기반 for문 (Ranged-based for loops and the auto keyword)
	for (auto number : fibonacci)
	{
		cout << number << endl;
	}

	// 값 복사 방지 (Not Copy)
	for (auto& number : fibonacci)
	{
		cout << number << endl;
	}

	// 읽기 전용 (Read Only)
	for (const auto& number : fibonacci)
	{
		cout << number << endl;
	}

	// 배열이 아닌 범위 기반 for문 (Ranged-based for loops and non-arrays)
	vector<int> fibonacci_vec = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
	for (const auto& number : fibonacci_vec)
	{
		cout << number << endl;
	}

	return 0;
}

