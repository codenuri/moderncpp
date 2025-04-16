#include <iostream>
#include <string>
#include <vector>

// �� move�� �߿��Ѱ� ? - 101 page 

// �Ʒ� �ڵ�� "����" ������ swap �Դϴ�.
// => �����ϴ�.
/*
template<typename T>
void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}
*/
// �Ʒ� �ڵ�� �̵�(move) ������ swap �Դϴ�.
// => ���� ������ �����մϴ�.
template<typename T>
void Swap(T& a, T& b)
{
	T tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);
}

int main()
{
	std::string s1 = "hello";
	std::string s2 = "world";

	Swap(s1, s2);
}



// move ���� �˾ƾ� �ϴ� ��
// #1. swap, ���ۺ��� ���� �˰��� �ۼ��� �����ϰ� move �� ����ϸ� �������ϴ�.

// #2. std::string �� �ƴ� �츮�� ���� Ŭ������ move �� �����ϰ� �Ϸ���??
