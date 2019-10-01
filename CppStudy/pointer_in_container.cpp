#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class TestClass
{
public:
	int n_;

	TestClass() : n_(0) {};
	TestClass(int n) : n_(n) {};
	~TestClass() { cout << n_ << " deleted" << endl; }
	void printTestClass() { cout << n_ << endl; }
};

int main()
{

	/*
		������ ������ ����
		- ��ü ������ ������尡 ����
		- �θ� ������������ �����Ͽ� �������� Ȱ�� �� �� �ִ�

		������ ������ ����
		- �޸� ���� ����� �ִ� (����Ʈ �����ͷ� �ذᰡ��)
		- �ּҰ��� �ƴ� ���� ���� ��� ��ü�� ���� ������ �̷�������� �Ű� �Ἥ �����ؾ��Ѵ�.
		��� Move ������ ���� �� ��, ���� ������ ������ ���� ����������
		�θ� �����͸� �̿��� ���� �θ� ����
		�ڽ� ��ü���� �������� ���� ������ ���� GOOD!
	*/

	vector<TestClass*> v1;
	v1.reserve(10);

	v1.emplace_back(new TestClass(10));
	v1.emplace_back(new TestClass(20));
	v1.emplace_back(new TestClass(30));

	// �ݺ��ڷ� ����.
	auto iter = v1.begin();
	(*iter)->printTestClass();

	//v1.pop_back();  // memory leak!!
	//v1.clear(); // memory leak!!
	//����� ��ü�� �������� �Ҹ�����ִ� �ڵ尡 ���� �����̳��� ���� �Լ��� �����ϸ�,
	//�����͸� ���ư��� �ش� ������ ��ü�� �״�� �����־ �޸� ���� �߻��մϴ�.

	// �������� ���� ���ָ� ���������� �����Ҵ��� ��ü�� �����մϴ�.
	delete v1.back();
	v1.pop_back();

	for (auto t : v1) delete t;
	v1.clear();

	vector<shared_ptr<TestClass>> v2;
	v2.reserve(10);

	v2.emplace_back(make_shared<TestClass>(10));
	v2.emplace_back(make_shared<TestClass>(20));
	v2.emplace_back(make_shared<TestClass>(30));

	// �ݺ��ڷ� ��ҿ� ����.
	auto iter2 = v2.begin() + 1;
	(*iter2)->printTestClass();

	v2.pop_back();
	v2.clear();

	return 0;

}