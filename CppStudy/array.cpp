#include <iostream>
#include <array>

using namespace std;

int main()
{
	array<int, 5> array_01{ 1, 2, 3, 4, 5 };

	cout << array_01[2] << endl;

	array_01[2] = 0;
	cout << array_01[2] << endl;

	// vector�� �޼ҵ尡 ���������� ����

	/* �ٸ� �޼ҵ�
	arr.data()
	�迭�� ������ Ÿ������ ��ȯ�մϴ�.
	(�迭�� ù��° �ּҸ� ��ȯ)

	arr.fill(val)
	������ C/C++ �迭�� ���Ҹ� �ٲپ� �ַ��� �ݺ����� ���ؼ� ������ �ٲپ� �־�� �߽��ϴ�.
	���ϰ� �迭�� ���ڸ� val���� �� �ٲ��ݴϴ�.

	*/

	cout << *(array_01.data() + 1) << endl;
	cout << *(array_01.data() + 2) << endl;

	return 0;
}