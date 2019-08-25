#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	/*
		※ std::deque 특징
		크기가 가변적이다. (사실 std::array를 제외한 거의 모든 STL 컨테이너의 특징이다.)
		앞(front)과 뒤(back)에서의 삽입, 삭제 성능은 좋지만 중간에서의 삽입, 삭제는 그다지 좋지 않다.
		std::deque는 Stack과 Queue가 결합된 자료구조로써 연결 리스트보다 구현하기가 어렵다.
		std::vector처럼 랜덤 액세스가 가능하다.

		※ std::deque와 std::vector
		std::deque와 std::vector의 멤버 함수 기능이나 사용 방법은 거의 동일하다.
		std::vector는 뒤(back)에서의 삽입, 삭제 성능이 좋지만 std::deque는 앞(front), 뒤(back), 모두에서 좋다.
		std::deque의 앞, 뒤 삽입, 삭제 성능을 제외한 다른 위치에서의 삽입, 삭제는 std::vector가 더 좋다.

		처음과 끝 말고 중간에 원소의 삽입과 삭제를 빈번하게 사용한다면 데크 보다는 리스트(list)를 사용하는 것을 추천한다.
		deque는 앞과 뒤에서 삽입과 삭제 성능이 vector보다 더 좋다.
		deque는 앞과 뒤 삽입, 삭제를 제외한 기능은 vector보다 성능이 좋지 못하다.
	*/

	deque<int> dq({ 1, 2, 3, 4, 5 });

	for_each(dq.begin(), dq.end(), [](int n) {cout << n << endl; });

	dq.emplace_front(1);
	dq.emplace_front(2);

	for_each(dq.begin(), dq.end(), [](int n) {cout << n << endl; });

	deque<int>::iterator iter;
	deque<int>::iterator iter2;

	for (iter = dq.begin(); iter != dq.end(); ++iter) {
		cout << *iter << ' ';
	}
	cout << endl;

	iter = dq.begin() + 2;            // dq의 3번째 원소에 접근
	iter2 = dq.insert(iter, 500);    // 3번째 원소 자리에 500을 삽입한다.
	cout << *iter2 << endl;

	for_each(dq.begin(), dq.end(), [](int n) {cout << n << endl; });

	return 0;
}

