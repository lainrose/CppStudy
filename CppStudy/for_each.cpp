#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(int i)
{
	cout << i << endl;
}

int main()
{
	// std::for_each(first, last, fn())
	//범위 내에 원소들에 대해 함수를 실행시킵니다.
	//범위 내(first 부터 last 전 까지) 원소들 각각에 대해 함수 fn 을 실행한다.참고로 함수의 리턴값은 무시됩니다.
	//first, last : 원소들의 시작과 끝을 가리키는 반복자들.이 때 확인하는 범위는[first, last) 로 정의됩니다.
	//first 가 가리키는 원소는 포함되지만 last 가 가리키는 원소는 포함되지 않습니다.
	//fn : 인자를 하나만 받는 함수 객체.범위 내에 원소들 각각에 대해 함수 fn 을 호출하게 됩니다.

	vector<int> v({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });

	for_each(v.begin(), v.end(), print);

	return 0;
}