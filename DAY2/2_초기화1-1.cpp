#include <iostream>

int x = 10;

class Test
{
	int value1 = 0;		// ok. ���� �ڵ�
	int value2 = ++x;	// ������ �ƴ����� ���� ������� ������
						// ȥ�������� �ڵ� �Դϴ�..
public:
	Test() {}					// value1(0), value2(++x)
	Test(int n) : value2(n) {}	// value1(0)
};

int main()
{
	Test t1;
	Test t2(5);

	// �Ʒ� �ڵ��� �������� ������ ������ 
	std::cout << x << std::endl; // 10 ? 11 ? 12  ===> 11
}