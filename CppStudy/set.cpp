#include <iostream>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

template <typename T>
void printSet(std::set<T>& s) {
	// ���� ��� ���ҵ��� ����ϱ�
	for (const auto& elem : s) {
		std::cout << elem << " " << std::endl; 
	}
}

template <typename T, typename C>
void printSet1(std::set<T, C>& s) {
	// ���� ��� ���ҵ��� ����ϱ�
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

	//  ���������� ���� �ÿ� ��� �ݺ��ڸ� ����ϱ⶧���� const ���
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
	o << "[ �߿䵵: " << td.priority << "] " << td.jobDesc << endl;
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

	// ���ĵ� ���¸� �����ϸ� �߰�
	// ���Ҹ� �߰��ϰų� ����� �۾��� O(log N)
	// �ߺ� X
	set<int> s({ 1, 1, 3, 3, 5, 5, 7, 7, 9, 9 });
	s.insert(2);
	s.insert(4);
	s.insert(6);
	s.insert(8);
	s.insert(10);

	cout << "������� ���ĵǼ� ���´�" << endl;
	printSet(s);

	std::cout << "-------------" << std::endl;

	// set.find O(log N) | vector.find O(N)
	cout << "10 �� s �� �����ΰ���? :: ";
	if (s.find(10) != s.end()) 
	{
		cout << "Yes" << endl;
	}
	else 
	{
		cout << "No" << endl;
	}

	cout << "15 �� s �� �����ΰ���? :: ";
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

	todos.insert(TestClass(1, "�� �ϱ�"));
	todos.insert(TestClass(2, "���� ���� �ϱ�"));
	todos.insert(TestClass(1, "���α׷��� ������Ʈ"));
	todos.insert(TestClass(3, "ģ�� ������"));
	todos.insert(TestClass(2, "��ȭ ����"));

	printSet(todos);

	std::cout << "-------------" << std::endl;
	std::cout << "������ ���´ٸ�!" << std::endl;
	todos.erase(todos.find(TestClass(2, "���� ���� �ϱ�")));
	printSet(todos);

	std::cout << "-------------" << std::endl;

	set<TestClass, TodoCmp> todos1;

	todos1.insert(TestClass(1, "�� �ϱ�"));
	todos1.insert(TestClass(2, "���� ���� �ϱ�"));
	todos1.insert(TestClass(1, "���α׷��� ������Ʈ"));
	todos1.insert(TestClass(3, "ģ�� ������"));
	todos1.insert(TestClass(2, "��ȭ ����"));

	printSet(todos);

	std::cout << "-------------" << std::endl;
	std::cout << "������ ���´ٸ�!" << std::endl;
	todos1.erase(todos1.find(TestClass(1, "���α׷��� ������Ʈ")));
	printSet1(todos1);

	return 0;
}