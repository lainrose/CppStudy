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
		포인터 저장의 장점
		- 객체 복사의 오버헤드가 없다
		- 부모 포인터형으로 저장하여 다형성을 활용 할 수 있다

		포인터 저장의 단점
		- 메모리 릭의 우려가 있다 (스마트 포인터로 해결가능)
		- 주소값이 아닌 실제 참조 대상 객체에 대해 연산이 이루어지도록 신경 써서 구현해야한다.
		사실 Move 개념이 도입 된 후, 복사 방지의 장점은 많이 없어졌지만
		부모 포인터를 이용해 같은 부모를 가진
		자식 객체들을 묶음으로 관리 가능한 점은 GOOD!
	*/

	vector<TestClass*> v1;
	v1.reserve(10);

	v1.emplace_back(new TestClass(10));
	v1.emplace_back(new TestClass(20));
	v1.emplace_back(new TestClass(30));

	// 반복자로 접근.
	auto iter = v1.begin();
	(*iter)->printTestClass();

	//v1.pop_back();  // memory leak!!
	//v1.clear(); // memory leak!!
	//저장된 객체를 수동으로 소멸시켜주는 코드가 없이 컨테이너의 삭제 함수를 실행하면,
	//포인터만 날아가고 해당 번지의 객체는 그대로 남아있어서 메모리 릭이 발생합니다.

	// 수동으로 해제 해주면 정상적으로 동적할당한 객체를 해제합니다.
	delete v1.back();
	v1.pop_back();

	for (auto t : v1) delete t;
	v1.clear();

	vector<shared_ptr<TestClass>> v2;
	v2.reserve(10);

	v2.emplace_back(make_shared<TestClass>(10));
	v2.emplace_back(make_shared<TestClass>(20));
	v2.emplace_back(make_shared<TestClass>(30));

	// 반복자로 요소에 접근.
	auto iter2 = v2.begin() + 1;
	(*iter2)->printTestClass();

	v2.pop_back();
	v2.clear();

	return 0;

}