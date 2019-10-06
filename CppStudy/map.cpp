#include <iostream>
#include <map>
#include <string>

using namespace std;

template <typename key, typename value>
void PrintMap(map<key, value>& items) {
	// 맵의 모든 원소들을 출력하기
	cout << "-------------" << endl;
	for (const auto& item : items) {
		cout << item.first << " " << item.second << endl;
	}
}

int main() {
	map<string, double> pitcher_list;

	// 참고로 2017년 7월 4일 현재 투수 방어율 순위입니다.

	// 맵의 insert 함수는 pair 객체를 인자로 받습니다.
	pitcher_list.insert(pair<string, double>("박세웅", 2.23));
	pitcher_list.insert(pair<string, double>("해커 ", 2.93));

	pitcher_list.insert(pair<string, double>("피어밴드 ", 2.95));

	// 타입을 지정하지 않아도 간단히 make_pair 함수로
	// pair 객체를 만들 수 도 있습니다.
	pitcher_list.insert(make_pair("차우찬", 3.04));
	pitcher_list.insert(make_pair("장원준 ", 3.05));
	pitcher_list.insert(make_pair("헥터 ", 3.09));

	// 혹은 insert 를 안쓰더라도 [] 로 바로
	// 원소를 추가할 수 있습니다.
	pitcher_list["니퍼트"] = 3.56;
	pitcher_list["박종훈"] = 3.76;
	pitcher_list["켈리"] = 3.90;

	PrintMap(pitcher_list);

	cout << "박세웅 방어율은? :: " << pitcher_list["박세웅"] << endl;

	// 해당키가 이미 존재한다면 덮어쓴다.
	pitcher_list["박세웅"] = 9.99;
	cout << "박세웅의 수정된 방어율은? :: " << pitcher_list["박세웅"] << endl;

	// 이미 존재할 때 insert는 무시된다.
	pitcher_list.insert(make_pair("박세웅", 1.11));
	cout << "박세웅의 수정된 방어율은? :: " << pitcher_list["박세웅"] << endl;

	// [] 연산자가, 맵에 없는 키를 참조하게 되면,
	// 자동으로 값의 디폴트 생성자를 호출해서 원소를 추가한다.
	cout << "-------------" << endl;
	cout << "류현진은? :: " << pitcher_list["류현진"] << endl;
	PrintMap(pitcher_list);

	// 안전하게 find로 찾기
	auto it = pitcher_list.find("이승엽");
	if (it != pitcher_list.end())
	{
		cout << it->first << " --> " << it->second << endl;
	}
	else
	{
		cout << "False" << endl;
	}

}