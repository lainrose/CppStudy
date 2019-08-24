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
	// C++11
	//unique_ptr은 하나의 스마트 포인터만이 특정 객체를 소유할 수 있도록, 객체에 소유권 개념을 도입한 스마트 포인터입니다.
	//이 스마트 포인터는 해당 객체의 소유권을 가지고 있을 때만, 소멸자가 해당 객체를 삭제할 수 있습니다.
	//unique_ptr 인스턴스는 move() 멤버 함수를 통해 소유권을 이전할 수는 있지만, 복사할 수는 없습니다.
	//소유권이 이전되면, 이전 unique_ptr 인스턴스는 더는 해당 객체를 소유하지 않게 재설정됩니다.

	unique_ptr<int> ptr_01(new int(5));

	// 오류 : 대입연산자 불가 move사용해야함
	//unique_ptr<int> ptr_02 = ptr_01;
	auto ptr_03 = move(ptr_01);

	// ptr02가 가리키고 있는 메모리 영역을 삭제함.
	ptr_03.reset();                 
	// ptr01가 가리키고 있는 메모리 영역을 삭제함.
	ptr_01.reset();                 

	// C++14
	// make_unique() 함수를 사용하면 unique_ptr 인스턴스를 안전하게 생성할 수 있습니다.
	//make_unique() 함수는 전달받은 인수를 사용해 지정된 타입의 객체를 생성하고, 생성된 객체를 가리키는 unique_ptr을 반환합니다.
	//이 함수를 사용하면, 예외 발생에 대해 안전하게 대처할 수 있습니다.
	auto hong = make_unique<Person>("길동", 29);
	hong->ShowPersonInfo();

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