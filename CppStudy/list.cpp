#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	/*
	 * 이중 연결 리스트(doubly linked list)라고 생각하면 됩니다.
	 * list는 시퀀스 컨테이너로 시퀀스 컨테이너가 갖는 모든 특징을 갖는다.
	 * list는 노드 기반 컨테이너로 at()과[] 연산자가 없으며 임의 접근 반복자가 아닌 양방향 반복자를 제공한다.
	 * 그래서 모든 원소를 탐색하려면 양방향 반복자의 연산인++, --를 사용한다.

	 * list의 가장 큰 특징 중 하나는 순 차열 중간에 원소를 삽입(insert), 제거(erase) 하더라도 상수 시간 복잡도의 수행 성능을 보인다는 점이다.
	 * 배열 기반 컨테이너 vector 나 deque 처럼 원소를 밀어내지 않고 노드를 서로 연결하기만 되기 때문이다.
	 * 또한 노드 기반 컨테이너의 삽입과 제거 동작은 반복자를 무효화시키지 않는다.
	 * 반복자가 가리키는 원소 자체가 제거되지 않는 한 반복자가 가리키는 원소는 그대로 존재한다.

	 * 하지만, 배열 기반 컨테이너(vector, deque)의 반복자는 원소의 삽입과 제거 동작이 발생하면 메모리가 재할당되거나 원소가 이동할 수 있으므로 반복자가 무효화된다.
	 * 노드 기반 컨테이너로 insert()나 erase()는 배열 기반보다 효율적으로 동작하며 값의 비교로 원소를 제거하는 remove(), remove_if()를 제공한다.

	 * 또한 list는 다른 list와 결합할 때 좋은 컨테이너이다.splice() 멤버 함수는 노드의 연결 연산만으로 두 list를 하나의 리스트로 결합할 수 있으며, merge() 멤버 함수는 두 list를 하나의 list로 정렬하며 결합한다.
	 * 또한 당양한 기능을 수행하는 reverse(), sort(), unique()등의 멤버 함수도 제공한다.
	 */

	list<int> list_1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	list<int> list_2(list_1);

	// list_2를 list_1로 합병/정렬한다. -> list는 오름차순으로 반드시 정렬되어있어야 한다.
	// 그렇지 않으면 오류난다.
	list_1.merge(list_2);
	for_each(list_1.begin(), list_1.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	// 비어있음
	for_each(list_2.begin(), list_2.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	// 해당 원소를 모두 제거
	list_1.remove(10);
	for_each(list_1.begin(), list_1.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	// 조건에 맞는 원소를 모두 제거
	list_1.remove_if([](int n) {return n < 5; });
	for_each(list_1.begin(), list_1.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	// 중복제거
	list_1.unique();
	for_each(list_1.begin(), list_1.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	// 내림차순
	list_1.sort(greater<int>());
	for_each(list_1.begin(), list_1.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	// 오름차순
	list_1.sort();
	for_each(list_1.begin(), list_1.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	list_2 = list_1;
	for_each(list_2.begin(), list_2.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	// list_1의 it부터 list2를 잘라서 붙임
	auto it = list_1.begin();
	it++;
	list_1.splice(it, list_2);
	for_each(list_1.begin(), list_1.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	// 비어있음
	for_each(list_2.begin(), list_2.end(), [](int n) {cout << n << ' '; });
	cout << endl;


	return 0;
}

