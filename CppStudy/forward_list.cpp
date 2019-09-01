#include <iostream>
#include <forward_list>
#include <algorithm>

using namespace std;

int main()
{
	/*
	※ STD::forward_list 요약
	std::list가 양방향(double linked list)이라면 std::forward_list는 단방향(single linked list)이다.
	단방향 연결 리스트라 양방향인 std::list보다 메모리 사용량이나 처리 속도면에서 조금 유리하다.
	double linked list가 필요하다면 std::list를, single linked list로도 충분하다면 std::forward_list를 사용한다.

	※ std::forward_list 특징
	다른 STL 컨테이너에 있는 size 함수를 제공하지 않는다.
	size는 다음과 같이 구한다.->size_t size = std::distance(list.begin(), list.end())
	back() 관련 미지원

	※ std::forward_list와 std::list
	std::list는 양방향으로 이동 가능하지만 std::forward_list는 한 방향으로만 이동할 수 있다.
	std::list보다 삽입 / 삭제 속도가 아주 약간 더 빠르다.
	양방향인 std::list에 비해 메모리를 적게 사용한다.각 요소 뿐만이 아닌, 컨테이너 자체 사이즈도 더 작다.
	삽입과 삭제는 지정한 요소의 다음 요소에 한해서만 가능하다.(단방향이므로 당연하다)
	구현의 복잡성과 성능 문제 때문에 std::list에서 제공하는 insert와 erase를 제공하지 않는다.
	*/

	forward_list<int> list_1{ 1,2,3,4,5,6,7,8,9,10 };

	for_each(list_1.begin(), list_1.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	auto it = list_1.begin();
	list_1.emplace_after(it, 5);
	for_each(list_1.begin(), list_1.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	list_1.emplace_front(9);
	for_each(list_1.begin(), list_1.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	list_1.pop_front();
	for_each(list_1.begin(), list_1.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	list_1.erase_after(it, list_1.end());
	for_each(list_1.begin(), list_1.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	return 0;
}