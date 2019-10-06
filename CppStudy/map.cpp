#include <iostream>
#include <map>
#include <string>

using namespace std;

template <typename key, typename value>
void PrintMap(map<key, value>& items) {
	// ���� ��� ���ҵ��� ����ϱ�
	cout << "-------------" << endl;
	for (const auto& item : items) {
		cout << item.first << " " << item.second << endl;
	}
}

int main() {
	map<string, double> pitcher_list;

	// ����� 2017�� 7�� 4�� ���� ���� ����� �����Դϴ�.

	// ���� insert �Լ��� pair ��ü�� ���ڷ� �޽��ϴ�.
	pitcher_list.insert(pair<string, double>("�ڼ���", 2.23));
	pitcher_list.insert(pair<string, double>("��Ŀ ", 2.93));

	pitcher_list.insert(pair<string, double>("�Ǿ��� ", 2.95));

	// Ÿ���� �������� �ʾƵ� ������ make_pair �Լ���
	// pair ��ü�� ���� �� �� �ֽ��ϴ�.
	pitcher_list.insert(make_pair("������", 3.04));
	pitcher_list.insert(make_pair("����� ", 3.05));
	pitcher_list.insert(make_pair("���� ", 3.09));

	// Ȥ�� insert �� �Ⱦ����� [] �� �ٷ�
	// ���Ҹ� �߰��� �� �ֽ��ϴ�.
	pitcher_list["����Ʈ"] = 3.56;
	pitcher_list["������"] = 3.76;
	pitcher_list["�̸�"] = 3.90;

	PrintMap(pitcher_list);

	cout << "�ڼ��� �������? :: " << pitcher_list["�ڼ���"] << endl;

	// �ش�Ű�� �̹� �����Ѵٸ� �����.
	pitcher_list["�ڼ���"] = 9.99;
	cout << "�ڼ����� ������ �������? :: " << pitcher_list["�ڼ���"] << endl;

	// �̹� ������ �� insert�� ���õȴ�.
	pitcher_list.insert(make_pair("�ڼ���", 1.11));
	cout << "�ڼ����� ������ �������? :: " << pitcher_list["�ڼ���"] << endl;

	// [] �����ڰ�, �ʿ� ���� Ű�� �����ϰ� �Ǹ�,
	// �ڵ����� ���� ����Ʈ �����ڸ� ȣ���ؼ� ���Ҹ� �߰��Ѵ�.
	cout << "-------------" << endl;
	cout << "��������? :: " << pitcher_list["������"] << endl;
	PrintMap(pitcher_list);

	// �����ϰ� find�� ã��
	auto it = pitcher_list.find("�̽¿�");
	if (it != pitcher_list.end())
	{
		cout << it->first << " --> " << it->second << endl;
	}
	else
	{
		cout << "False" << endl;
	}

}