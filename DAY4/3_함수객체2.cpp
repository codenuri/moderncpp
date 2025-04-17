#include <iostream>

// function object(�Լ� ��ü) - 131 page
// => () �����ڸ� ������ �ؼ� �Լ� ó�� ��밡���� ��ü

struct Plus
{
	int operator()(int a, int b) const 
	{
		return a + b;
	}
};

int main()
{
	Plus p;	// p �� �Լ��� �ƴ� ��ü �Դϴ�. Plus ��� ����ü Ÿ��

	int n = p(1, 2);	// ��ü p�� �Լ� ó�� ����մϴ�.
						// "�Լ� ��ü" ��� �մϴ�.

	int n1 = p.operator()(1, 2); // �̷��� ��� �Լ��̸��� ���� ����ص�
								 // �˴ϴ�.

	// �Ʒ� �ڵ忡�� a �� ����� ���� Ÿ���� ��ü���
	// a + b	// a.operator+(b)
	// a - b	// a.operator-(b)
	// a()		// a.operator()()
	// a(1, 2)	// a.operator()(1,2)
}
