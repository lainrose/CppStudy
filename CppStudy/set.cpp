#include <iostream>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

template <typename T>
void printSet(std::set<T>& s) {
	// 셋의 모든 원소들을 출력하기
	for (const auto& elem : s) {
		std::cout << elem << " " << std::endl; 
	}
}

template <typename T, typename C>
void printSet1(std::set<T, C>& s) {
	// 셋의 모든 원소들을 출력하기
	for (const auto& elem : s) {
		std::cout << elem << " " << std::endl;
	}
}

class TestClass {

private:
	int priority;
	string jobDesc;

public:
	TestClass(int priority, std::string job_desc)
		: priority(priority), jobDesc(job_desc) {}

	//  내부적으로 정렬 시에 상수 반복자를 사용하기때문에 const 사용
	bool operator<(const TestClass& t) const {
		if (priority == t.priority) {
			return jobDesc < t.jobDesc;
		}
		return priority > t.priority;
	}

	friend std::ostream& operator<<(std::ostream& o, const TestClass& td);
	friend struct TodoCmp;

};

std::ostream& operator<<(std::ostream& o, const TestClass& td) {
	o << "[ 중요도: " << td.priority << "] " << td.jobDesc << endl;
	return o;
}

struct TodoCmp {
	bool operator()(const TestClass& t1, const TestClass& t2) const {
		if (t1.priority == t2.priority) {
			return t1.jobDesc < t2.jobDesc;
		}
		return t1.priority > t2.priority;
	}
};

int main()
{

	// 정렬된 상태를 유지하며 추가
	// 원소를 추가하거나 지우는 작업은 O(log N)
	// 중복 X
	set<int> s({ 1, 1, 3, 3, 5, 5, 7, 7, 9, 9 });
	s.insert(2);
	s.insert(4);
	s.insert(6);
	s.insert(8);
	s.insert(10);

	cout << "순서대로 정렬되서 나온다" << endl;
	printSet(s);

	std::cout << "-------------" << std::endl;

	// set.find O(log N) | vector.find O(N)
	cout << "10 이 s 의 원소인가요? :: ";
	if (s.find(10) != s.end()) 
	{
		cout << "Yes" << endl;
	}
	else 
	{
		cout << "No" << endl;
	}

	cout << "15 가 s 의 원소인가요? :: ";
	if (s.find(15) != s.end()) 
	{
		cout << "Yes" << endl;
	}
	else 
	{
		cout << "No" << endl;
	}

	std::cout << "-------------" << std::endl;

	set<TestClass> todos;

	todos.insert(TestClass(1, "농구 하기"));
	todos.insert(TestClass(2, "수학 숙제 하기"));
	todos.insert(TestClass(1, "프로그래밍 프로젝트"));
	todos.insert(TestClass(3, "친구 만나기"));
	todos.insert(TestClass(2, "영화 보기"));

	printSet(todos);

	std::cout << "-------------" << std::endl;
	std::cout << "숙제를 끝냈다면!" << std::endl;
	todos.erase(todos.find(TestClass(2, "수학 숙제 하기")));
	printSet(todos);

	std::cout << "-------------" << std::endl;

	set<TestClass, TodoCmp> todos1;

	todos1.insert(TestClass(1, "농구 하기"));
	todos1.insert(TestClass(2, "수학 숙제 하기"));
	todos1.insert(TestClass(1, "프로그래밍 프로젝트"));
	todos1.insert(TestClass(3, "친구 만나기"));
	todos1.insert(TestClass(2, "영화 보기"));

	printSet(todos);

	std::cout << "-------------" << std::endl;
	std::cout << "숙제를 끝냈다면!" << std::endl;
	todos1.erase(todos1.find(TestClass(1, "프로그래밍 프로젝트")));
	printSet1(todos1);

	return 0;
}