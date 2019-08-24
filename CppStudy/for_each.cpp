#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(int i)
{
	cout << i << endl;
}

int main()
{
	// std::for_each(first, last, fn())
	//���� ���� ���ҵ鿡 ���� �Լ��� �����ŵ�ϴ�.
	//���� ��(first ���� last �� ����) ���ҵ� ������ ���� �Լ� fn �� �����Ѵ�.����� �Լ��� ���ϰ��� ���õ˴ϴ�.
	//first, last : ���ҵ��� ���۰� ���� ����Ű�� �ݺ��ڵ�.�� �� Ȯ���ϴ� ������[first, last) �� ���ǵ˴ϴ�.
	//first �� ����Ű�� ���Ҵ� ���Ե����� last �� ����Ű�� ���Ҵ� ���Ե��� �ʽ��ϴ�.
	//fn : ���ڸ� �ϳ��� �޴� �Լ� ��ü.���� ���� ���ҵ� ������ ���� �Լ� fn �� ȣ���ϰ� �˴ϴ�.

	vector<int> v({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });

	for_each(v.begin(), v.end(), print);

	return 0;
}