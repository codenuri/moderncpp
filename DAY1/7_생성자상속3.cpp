#include <list>
#include <iostream>

// STL ���� ���� �Ļ��� Ŭ������ ����� ���ô�.
// 1. ��� ����Ÿ�� �߰��ϸ�
// => �����ڸ� ���� ����Ÿ�� �ʱ�ȭ �ϴ� ���� ��Ģ �Դϴ�.

// 2. ��� ����Ÿ�� �߰����� �ʰ�, ��� �Լ��� �߰��Ѵٸ�

template<typename T, typename Alloc = std::allocator<T> >
class MyList : public std::list<T, Alloc>
{
public:
	using std::list<T, Alloc>::list;

	void print()
	{
		for (auto& e : *this)
			std::cout << e << ", ";
		std::cout << std::endl;
	}
};

int main()
{
	MyList<int> st1(10, 3); // 10���� 3���� �ʱ�ȭ
	MyList<double> st2(10);

	st1.print();
}




