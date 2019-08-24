#include <iostream>
#include <vector>
#include<string>
using namespace std;

int main()
{
	//weak_ptr은 하나 이상의 shared_ptr 인스턴스가 소유하는 객체에 대한 접근을 제공하지만, 소유자의 수에는 포함되지 않는 스마트 포인터입니다.
	//
	//shared_ptr은 참조 횟수(reference count)를 기반으로 동작하는 스마트 포인터입니다.
	//만약 서로가 상대방을 가리키는 shared_ptr를 가지고 있다면, 참조 횟수는 절대 0이 되지 않으므로 메모리는 영원히 해제되지 않습니다.
	//이렇게 서로가 상대방을 참조하고 있는 상황을 순환 참조(circular reference)라고 합니다.
	//weak_ptr은 바로 이러한 shared_ptr 인스턴스 사이의 순환 참조를 제거하기 위해서 사용됩니다.

	shared_ptr<int> sptr_01(new int(10));
	weak_ptr<int> wptr_01 = sptr_01;

	cout << sptr_01.use_count() << endl;
	cout << wptr_01.use_count() << endl;
	return 0;
}