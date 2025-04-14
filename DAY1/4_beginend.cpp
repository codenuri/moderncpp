// 4_beginend - 16 page
#include <vector>
#include <list>
#include <iostream>

int main()
{
	//std::vector<int> v = { 1,2,3,4,5 };
	//std::list<int>   v = { 1,2,3,4,5 };
	int v[5] = { 1,2,3,4,5 };

	// STL ���� �ݺ��ڸ� ������ ���

	// #1. C++98 ��Ÿ�� 
	// => �����̳� ����� �º��� Ÿ���� �����Ǿ�� �մϴ�.
	// => ���� �ʽ��ϴ�. ������� ������
//	std::vector<int>::iterator p1 = v.begin();
//	std::vector<int>::iterator p2 = v.end();

	// #2. C++11 ���� ���� ��Ÿ��
	// 1. auto ����ϼ���
//	auto p1 = v.begin();
//	auto p2 = v.end();


	// 2. ��� �Լ� begin ��� �Ϲ� �Լ� begin ���
	// ���� : v�� raw array �� ��� ����.
	auto p1 = std::begin(v);
	auto p2 = std::end(v);

}

// �Ʒ� ���� �ڵ忡�� ���ڷ� �迭�� �ü� �ִٰ� �����Ҷ� ���
template<typename T>
void use_container(T& c)
{
	auto p = c.begin(); // c�� �迭�̸� ����
	auto p = std::begin(c); // c�� �迭�̶� ok
}