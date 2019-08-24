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
	Person(const string& name, int age); // 기초 클래스 생성자의 선언
	~Person() { cout << "소멸자가 호출되었습니다." << endl; }
	void ShowPersonInfo();
};


int main()
{
	//shared_ptr은 하나의 특정 객체를 참조하는 스마트 포인터가 총 몇 개인지를 참조하는 스마트 포인터입니다.
	//이렇게 참조하고 있는 스마트 포인터의 개수를 참조 횟수(reference count)라고 합니다.
	//참조 횟수는 특정 객체에 새로운 shared_ptr이 추가될 때마다 1씩 증가하며, 수명이 다할 때마다 1씩 감소합니다.
	//따라서 마지막 shared_ptr의 수명이 다하여, 참조 횟수가 0이 되면 delete 키워드를 사용하여 메모리를 자동으로 해제합니다.

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

	auto hong = make_shared<Person>("길동", 29);
	cout << "현재 소유자 수 : " << hong.use_count() << endl;

	auto han = hong;
	cout << "현재 소유자 수 : " << hong.use_count() << endl;

	han.reset(); // shared_ptr인 han을 해제함.
	cout << "현재 소유자 수 : " << hong.use_count() << endl;


	return 0;
}

Person::Person(const string& name, int age) // 기초 클래스 생성자의 정의
{
	name_ = name;
	age_ = age;
	cout << "생성자가 호출되었습니다." << endl;
}

void Person::ShowPersonInfo()
{
	std::cout << name_ << "의 나이는 " << age_ << "살입니다." << endl;
}