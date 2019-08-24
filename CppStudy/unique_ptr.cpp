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
	// C++11
	//unique_ptr�� �ϳ��� ����Ʈ �����͸��� Ư�� ��ü�� ������ �� �ֵ���, ��ü�� ������ ������ ������ ����Ʈ �������Դϴ�.
	//�� ����Ʈ �����ʹ� �ش� ��ü�� �������� ������ ���� ����, �Ҹ��ڰ� �ش� ��ü�� ������ �� �ֽ��ϴ�.
	//unique_ptr �ν��Ͻ��� move() ��� �Լ��� ���� �������� ������ ���� ������, ������ ���� �����ϴ�.
	//�������� �����Ǹ�, ���� unique_ptr �ν��Ͻ��� ���� �ش� ��ü�� �������� �ʰ� �缳���˴ϴ�.

	unique_ptr<int> ptr_01(new int(5));

	// ���� : ���Կ����� �Ұ� move����ؾ���
	//unique_ptr<int> ptr_02 = ptr_01;
	auto ptr_03 = move(ptr_01);

	// ptr02�� ����Ű�� �ִ� �޸� ������ ������.
	ptr_03.reset();                 
	// ptr01�� ����Ű�� �ִ� �޸� ������ ������.
	ptr_01.reset();                 

	// C++14
	// make_unique() �Լ��� ����ϸ� unique_ptr �ν��Ͻ��� �����ϰ� ������ �� �ֽ��ϴ�.
	//make_unique() �Լ��� ���޹��� �μ��� ����� ������ Ÿ���� ��ü�� �����ϰ�, ������ ��ü�� ����Ű�� unique_ptr�� ��ȯ�մϴ�.
	//�� �Լ��� ����ϸ�, ���� �߻��� ���� �����ϰ� ��ó�� �� �ֽ��ϴ�.
	auto hong = make_unique<Person>("�浿", 29);
	hong->ShowPersonInfo();

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