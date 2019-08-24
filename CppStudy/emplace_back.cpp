#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class SomeClass
{
public:
	int i;
	int j;
	string str;

	SomeClass() = default;

	SomeClass(int i, int j, string str)
	{
		this->i = i;
		this->j = j;
		this->str = str;
	}
};
int main()
{

	// push_back�� �����ϱ� ���� ��ü�� �����(����) �����߰�
	// ���������� �� �ӽð�ü�� �����(����) �ؼ� �ִ´�.
	// �� 2���� ���簡 �̷����

	// emplace_back�� ����ϸ� �޸� �̵��� �߻��Ͽ� ���� ���
	// ���� ���� ���ø� ���ڷ� ȿ������ �ۼ�

	vector<SomeClass> v;
	v.push_back(SomeClass(1, 2, "3"));
	v.emplace_back(1, 2, "4");

	for_each(v.begin(), v.end(), [](auto& v) { cout << v.i << v.j << v.str << endl; });

	return 0;
}