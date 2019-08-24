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

	// push_back에 삽입하기 위해 객체를 만들어(복사) 전달했고
	// 내부적으로 또 임시객체를 만들어(복사) 해서 넣는다.
	// 총 2번의 복사가 이루어짐

	// emplace_back를 사용하면 메모리 이동이 발생하여 성능 향상
	// 또한 가변 템플릿 인자로 효율적인 작성

	vector<SomeClass> v;
	v.push_back(SomeClass(1, 2, "3"));
	v.emplace_back(1, 2, "4");

	for_each(v.begin(), v.end(), [](auto& v) { cout << v.i << v.j << v.str << endl; });

	return 0;
}