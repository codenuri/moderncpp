// 1_�ӽð�ü1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl;	}
};

int main()
{
//	Point pt(1, 2); // "�̸��� �ִ� ��ü(named object)"
					// �̸��� �����Ƿ� �������忡�� ���� ����
					// ���� : �ڽ��� ������ {} �� ����� �ı�

//	Point(1, 2);	// "�̸��� ���� ��ü(unnamed object)"
					// �̸��� �����Ƿ� �ٸ� ���忡�� ���� �ȵ�
					// ���� : �ڽ��� ������ ������ ��(;)
					// "temporary(�ӽð�ü)" ��� �θ��ϴ�.
					// C++ �� �ƴ϶� ���� �ٸ����� �ִ� ����(��κ� �߰�޿��� �ٷ�� )

	Point(1, 2), std::cout << "X\n";


	std::cout << "-------" << std::endl;
}





