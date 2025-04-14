#include <list>
#include <iostream>

// STL ���� ���� �Ļ��� Ŭ������ ����� ���ô�.
// 1. ��� ����Ÿ�� �߰��ϸ�
// => �����ڸ� ���� ����Ÿ�� �ʱ�ȭ �ϴ� ���� ��Ģ �Դϴ�.

// 2. ��� ����Ÿ�� �߰����� �ʰ�, ��� �Լ��� �߰��Ѵٸ�

class MyList : public std::list<int>
{
public:
	void print()
	{
		for (auto& e : *this)
			std::cout << e << ", ";
		std::cout << std::endl;
	}

	// MyList �� std::list �� �����ϰ� ����ϰ� �Ϸ���
	// C++98 : std::list�� ��� �����ڸ� MyList �� ������ �մϴ�.
//	MyList(int size, int value) : std::list<int>(size, value) {}
//	MyList(int size)			: std::list<int>(size) {}

	// C++11 : ������ ��� ���� ����ϸ� �˴ϴ�.
	using std::list<int>::list;
};

int main()
{
	MyList st1(10, 3); // 10���� 3���� �ʱ�ȭ
	MyList st2(10);
}




