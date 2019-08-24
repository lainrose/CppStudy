#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

using namespace std;

template< typename Func >
void Test(Func func)
{
	func();
}

int main()
{

	//'lambda 함수' 또는 '무명 함수' 라고 부르기도 한다.
	//lambda는 함수 오브젝트 이다.
	//C++의 표현력을 증가시켜 준다.
	//STL의 알고리즘을 더 간편하게 사용할 수 있다.
	//규격에서는 lambda는 특별한 타입을 가지고 있다고 한다.
	//단!decltype나 sizeof 에서 사용 할 수 없다.

	// [] Lambda capture
	// ()Parameter
	// {} Body 
	// () Call lambda

	[] { std::cout << "Hello World!" << std::endl; } ();

	auto func = [] { std::cout << "Hello World!" << std::endl; };
	func();

	Test(func);

	auto func1 = [](float n) { std::cout << "I have " << n << " girl friends" << std::endl; };
	func1(3);
	func1(12);

	auto func2 = [] { return 3.14; };
	auto func3 = [](float f) {return f;};
	auto func4 = []() -> float { return 3.14; };

	func1(func2());
	func1(func3(3.14f));
	func1(func4());

	vector<int> v1({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });

	int sum = 0;
	for_each(v1.begin(), v1.end(), [&](int n) { std::cout << n << ", "; });
	for_each(v1.begin(), v1.end(), [&](int n) {sum += n; });
	cout << "sum : " << sum << endl;

	cout << "---------" << endl;

	//Scope의 모든 변수를 참조로 capture 할 때는[&], 특정 변수를 참조로 capture 할 때는[&변수]
	//Scope의 모든 변수를 복사로 capture 할 때는[=], 특정 변수를 복사로 capture 할 때는[변수]
	int x = 100;
	[&]() {std::cout << x << std::endl; // print x = 100
			x = 200;} ();
	cout << x << std::endl; // print x = 200

	[=]() {std::cout << x << std::endl;} ();	// it works good!
	/*
		Error
		[=]() {std::cout << x << std::endl;
				x = 200; } (); 
	*/

	cout << "---------" << endl;
	x = 100;
	[=]() {std::cout << x << std::endl;} ();		// print x = 100
	[=]() mutable {std::cout << x << std::endl;		// print x = 100
					x = 200;}();					// x = 200
	std::cout << x << std::endl; // print x = 100

	/*
		[&, n1, n2] {}; //n3, n4, n5 reference || n1, n2 copy
		[=, &n1, &n2] {}; // n3, n4, n5 copy || n1, n2 reference

		[n1, n1] {}; // Error!! Already Use Same variable!
		[&, &n1] {}; // Error!! Already Use Default Reference
		[=, n1] {} // Error!! Already Use Default Copy
	*/

	std::function<int(int)> factorial = [&factorial](int x) -> int {
		return x <= 1 ? 1 : x * factorial(x - 1);
	};

	std::cout << "factorial(5): " << factorial(5) << std::endl;

	return 0;
}