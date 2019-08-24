#include <iostream>
#include <vector>
#include<string>
using namespace std;

class Person
{
private:

	string name_;
	int age_;

public:
	Person(const string& name, int age); // ���� Ŭ���� �������� ����
	~Person() { cout << "�Ҹ��ڰ� ȣ��Ǿ����ϴ�." << endl; }
	void ShowPersonInfo();
};


int main()
{
	//shared_ptr�� �ϳ��� Ư�� ��ü�� �����ϴ� ����Ʈ �����Ͱ� �� �� �������� �����ϴ� ����Ʈ �������Դϴ�.
	//�̷��� �����ϰ� �ִ� ����Ʈ �������� ������ ���� Ƚ��(reference count)��� �մϴ�.
	//���� Ƚ���� Ư�� ��ü�� ���ο� shared_ptr�� �߰��� ������ 1�� �����ϸ�, ������ ���� ������ 1�� �����մϴ�.
	//���� ������ shared_ptr�� ������ ���Ͽ�, ���� Ƚ���� 0�� �Ǹ� delete Ű���带 ����Ͽ� �޸𸮸� �ڵ����� �����մϴ�.

	shared_ptr<int> ptr_01(new int(5));
	cout << ptr_01.use_count() << endl;
	cout << *ptr_01 << endl;
	cout << &(*ptr_01) << endl;

	auto ptr_02(ptr_01);
	cout << ptr_01.use_count() << endl;
	cout << *ptr_02 << endl;
	cout << &(*ptr_02) << endl;

	auto ptr_03(ptr_01);
	cout << ptr_01.use_count() << endl;
	cout << *ptr_03 << endl;
	cout << &(*ptr_03) << endl;

	ptr_03.reset();
	ptr_02.reset();

	auto hong = make_shared<Person>("�浿", 29);
	cout << "���� ������ �� : " << hong.use_count() << endl;

	auto han = hong;
	cout << "���� ������ �� : " << hong.use_count() << endl;

	han.reset(); // shared_ptr�� han�� ������.
	cout << "���� ������ �� : " << hong.use_count() << endl;


	return 0;
}

Person::Person(const string& name, int age) // ���� Ŭ���� �������� ����
{
	name_ = name;
	age_ = age;
	cout << "�����ڰ� ȣ��Ǿ����ϴ�." << endl;
}

void Person::ShowPersonInfo()
{
	std::cout << name_ << "�� ���̴� " << age_ << "���Դϴ�." << endl;
}