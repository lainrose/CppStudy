#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// 빈 vector 생성
	vector<int> v;

	// 기본값(0)으로 초기화 된 5개의 원소를 가지는 vector 생성
	vector<int> v(5);

	// 기본값(2)으로 초기화 된 5개의 원소를 가지는 vector 생성
	vector<int> v(5, 2);

	// v를 복사해서 생성
	vector<int> v2(v);

	// 원소가 모두 같은지
	if(v == v2) return 0;
	// 원소가 하나라도 다른지
	if (v != v2) return 0;
	// 문자열 처럼 비교 >= 가능
	if (v > v2) return 0;
	// 문자열 처럼 비교 <= 가능
	if (v < v2) return 0;

	// 2의 값으로 5개의 원소 할당
	v.assign(5, 2);

	// index번째 원소를 참조
	// v[idx] 보다 속도는 느리지만, 범위를 점검하므로 안전
	int index = 2;
	v.at(index);

	// index번째 원소를 참조
	// 범위를 점검하지 않으므로, v.at(index)보다 빠름
	v[index];

	// 첫 번째 원소를 참조
	v.front();

	// 모든 원소를 제거
	// 원소만 제거하고 메모리는 남음
	// size만 줄어들고 capacity는 그대로 남음
	v.clear();

	// 마지막 원소 뒤에 7을 삽입
	v.push_back(7);

	// 마지막 원소를 제거
	v.pop_back();

	// 첫 번째 원소를 가리킴
	v.begin();

	// 마지막의 다음을 가리킴
	v.end();

	//벡터를 뒤집어서 첫 번째 원소를 가리킴
	v.rbegin();

	//벡터를 뒤집어서 마지의 다음을 가리킴
	v.rend();

	// n개의 원소를 저장할 위치를 예약 (동적 할당)
	// 기존보다 작게 할당하면 내부에서 무시
	v.reserve(5);

	// 벡터의 크기를 변경
	// 벡터의 크기가 더 커진 경우 default인 0으로 초기화
	/*
	resize함수는.내부용량을 딱 정해놓고 사용하는 것이다.
	만약에 사이즈를 10으로 해놨을 경우.무조건 사이즈는 10이된다.
	10보다 큰 데이터가 들어오면 끝의 요소들은 버려지게 된다.
	내부를 10개보다 적게 채워도 사이즈는 10으로 유지하게 된다.
	*/
	v.resize(5);

	// 벡터의 크기를 변경
	// 벡터의 크기가 더 커진 경우 3으로 초기화

	v.resize(5, 3);

	/*
	resize() 의 경우, vector 컨테이너에다가 요소를 추가하고 초기화(디폴트 생성 호출)를 한다.
	인자로 전달된 resize 할 갯수가 전의 컬렉션 개수보다 크다면 미리 vector 에 들어가 있던 유효한 요소들은 변하지 않는다.

	반면에 reserve() 는 전달된 값(개수) 만큼의 메모리를 할당하는 역할을 한다.
	중요한 건 reserve() 함수로 요소 자체가 추가되지는 않는다는 점이다.
	*/


	// 벡터의 크기를 반환
	v.size();

	// 벡터의 할당된 크기를 리턴
	v.capacity();

	// v와 v2의 원소와 capacity를 바꿈
	// v의 capacity를 없앨 때 사용(할단됭 메로리를 프로그램이 끝나기 전에 없애고 싶을 때)
	// v2를 capacity가 0인 임시 객체로 만들어서 스왑
	v2.swap(v);
	vector<int>().swap(v);

	// 벡터가 비었으면 true 반환
	v.empty();

	// 해당 위치에 2를 삽입
	v.insert(v.begin(), 2);

	// 해당 위치에 2를 4개 삽입
	v.insert(v.begin(), 2, 4);

	// 해당 위치의 값을 제거
	v.erase(v.end());

	// vector iterator 사용
	vector<int>::const_iterator iter;

	for (iter = v.begin(); iter != v.end(); ++iter)
	{
		cout << *iter << endl;
	}

	//erase 사용 시 주의사항
	// 삭제시 데이터가 앞으로 당겨지기 때문에 엉뚱한 포인터를 가리킬 수 있음
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		if (*it == 20)
			it = v.erase(it);
	}

	//아래와 같이 사용해야 안전
	for (vector<int>::size_type i = 0; i < v.size(); )
	{
		if (v[i] == 20)
			v.erase(v.begin() + i);
		else
			i++;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end();)
	{
		if (*it == 20)
			it = v.erase(it);
		else
			it++;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end();)
	{
		if (*it == 20)
			v.erase(it++);
		else
			it++;
	}

	return 0;
}

