#include <iostream>
#include <array>

using namespace std;

int main()
{
	array<int, 5> array_01{ 1, 2, 3, 4, 5 };

	cout << array_01[2] << endl;

	array_01[2] = 0;
	cout << array_01[2] << endl;

	// vector과 메소드가 전반적으로 동일

	/* 다른 메소드
	arr.data()
	배열을 포인터 타입으로 반환합니다.
	(배열의 첫번째 주소를 반환)

	arr.fill(val)
	과거의 C/C++ 배열은 원소를 바꾸어 주려면 반복문을 통해서 일일히 바꾸어 주어야 했습니다.
	편리하게 배열의 인자를 val으로 다 바꿔줍니다.

	*/

	cout << *(array_01.data() + 1) << endl;
	cout << *(array_01.data() + 2) << endl;

	return 0;
}