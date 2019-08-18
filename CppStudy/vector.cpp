#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// �� vector ����
	vector<int> v;

	// �⺻��(0)���� �ʱ�ȭ �� 5���� ���Ҹ� ������ vector ����
	vector<int> v(5);

	// �⺻��(2)���� �ʱ�ȭ �� 5���� ���Ҹ� ������ vector ����
	vector<int> v(5, 2);

	// v�� �����ؼ� ����
	vector<int> v2(v);

	// ���Ұ� ��� ������
	if(v == v2) return 0;
	// ���Ұ� �ϳ��� �ٸ���
	if (v != v2) return 0;
	// ���ڿ� ó�� �� >= ����
	if (v > v2) return 0;
	// ���ڿ� ó�� �� <= ����
	if (v < v2) return 0;

	// 2�� ������ 5���� ���� �Ҵ�
	v.assign(5, 2);

	// index��° ���Ҹ� ����
	// v[idx] ���� �ӵ��� ��������, ������ �����ϹǷ� ����
	int index = 2;
	v.at(index);

	// index��° ���Ҹ� ����
	// ������ �������� �����Ƿ�, v.at(index)���� ����
	v[index];

	// ù ��° ���Ҹ� ����
	v.front();

	// ��� ���Ҹ� ����
	// ���Ҹ� �����ϰ� �޸𸮴� ����
	// size�� �پ��� capacity�� �״�� ����
	v.clear();

	// ������ ���� �ڿ� 7�� ����
	v.push_back(7);

	// ������ ���Ҹ� ����
	v.pop_back();

	// ù ��° ���Ҹ� ����Ŵ
	v.begin();

	// �������� ������ ����Ŵ
	v.end();

	//���͸� ����� ù ��° ���Ҹ� ����Ŵ
	v.rbegin();

	//���͸� ����� ������ ������ ����Ŵ
	v.rend();

	// n���� ���Ҹ� ������ ��ġ�� ���� (���� �Ҵ�)
	// �������� �۰� �Ҵ��ϸ� ���ο��� ����
	v.reserve(5);

	// ������ ũ�⸦ ����
	// ������ ũ�Ⱑ �� Ŀ�� ��� default�� 0���� �ʱ�ȭ
	/*
	resize�Լ���.���ο뷮�� �� ���س��� ����ϴ� ���̴�.
	���࿡ ����� 10���� �س��� ���.������ ������� 10�̵ȴ�.
	10���� ū �����Ͱ� ������ ���� ��ҵ��� �������� �ȴ�.
	���θ� 10������ ���� ä���� ������� 10���� �����ϰ� �ȴ�.
	*/
	v.resize(5);

	// ������ ũ�⸦ ����
	// ������ ũ�Ⱑ �� Ŀ�� ��� 3���� �ʱ�ȭ

	v.resize(5, 3);

	/*
	resize() �� ���, vector �����̳ʿ��ٰ� ��Ҹ� �߰��ϰ� �ʱ�ȭ(����Ʈ ���� ȣ��)�� �Ѵ�.
	���ڷ� ���޵� resize �� ������ ���� �÷��� �������� ũ�ٸ� �̸� vector �� �� �ִ� ��ȿ�� ��ҵ��� ������ �ʴ´�.

	�ݸ鿡 reserve() �� ���޵� ��(����) ��ŭ�� �޸𸮸� �Ҵ��ϴ� ������ �Ѵ�.
	�߿��� �� reserve() �Լ��� ��� ��ü�� �߰������� �ʴ´ٴ� ���̴�.
	*/


	// ������ ũ�⸦ ��ȯ
	v.size();

	// ������ �Ҵ�� ũ�⸦ ����
	v.capacity();

	// v�� v2�� ���ҿ� capacity�� �ٲ�
	// v�� capacity�� ���� �� ���(�Ҵ܉� �޷θ��� ���α׷��� ������ ���� ���ְ� ���� ��)
	// v2�� capacity�� 0�� �ӽ� ��ü�� ���� ����
	v2.swap(v);
	vector<int>().swap(v);

	// ���Ͱ� ������� true ��ȯ
	v.empty();

	// �ش� ��ġ�� 2�� ����
	v.insert(v.begin(), 2);

	// �ش� ��ġ�� 2�� 4�� ����
	v.insert(v.begin(), 2, 4);

	// �ش� ��ġ�� ���� ����
	v.erase(v.end());

	// vector iterator ���
	vector<int>::const_iterator iter;

	for (iter = v.begin(); iter != v.end(); ++iter)
	{
		cout << *iter << endl;
	}

	//erase ��� �� ���ǻ���
	// ������ �����Ͱ� ������ ������� ������ ������ �����͸� ����ų �� ����
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		if (*it == 20)
			it = v.erase(it);
	}

	//�Ʒ��� ���� ����ؾ� ����
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

