#include <iostream>
#include <vector>
#include<string>
using namespace std;

int main()
{
	//weak_ptr�� �ϳ� �̻��� shared_ptr �ν��Ͻ��� �����ϴ� ��ü�� ���� ������ ����������, �������� ������ ���Ե��� �ʴ� ����Ʈ �������Դϴ�.
	//
	//shared_ptr�� ���� Ƚ��(reference count)�� ������� �����ϴ� ����Ʈ �������Դϴ�.
	//���� ���ΰ� ������ ����Ű�� shared_ptr�� ������ �ִٸ�, ���� Ƚ���� ���� 0�� ���� �����Ƿ� �޸𸮴� ������ �������� �ʽ��ϴ�.
	//�̷��� ���ΰ� ������ �����ϰ� �ִ� ��Ȳ�� ��ȯ ����(circular reference)��� �մϴ�.
	//weak_ptr�� �ٷ� �̷��� shared_ptr �ν��Ͻ� ������ ��ȯ ������ �����ϱ� ���ؼ� ���˴ϴ�.

	shared_ptr<int> sptr_01(new int(10));
	weak_ptr<int> wptr_01 = sptr_01;

	cout << sptr_01.use_count() << endl;
	cout << wptr_01.use_count() << endl;
	return 0;
}