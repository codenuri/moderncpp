// 1_�ʱ�ȭ6 - 60 page
#include <iostream>

struct Point
{
	int x;
	int y;

//	Point() {}
	Point() = default;
};

int main()
{
	int n1{ 0 };	// direct intialization
	int n2 = { 0 };	// copy initialization

	int n3;			// default initilization 
					// => �������� : �����Ⱚ, �������� : 0

	int n4{};		// value initialization
					// => primitive Ÿ�� : 0
					// => user define Ÿ�� : ����Ʈ ������ ȣ��

	std::cout << n4 << std::endl; // 0

	Point pt{};		// Point �� �����ڰ� ���ų�
					// "=default" �θ��� �����ڰ� �ִٸ�
					// => ��� ��� �� 0���� �ʱ�ȭ
					
					// ����ڰ� ���� �����ڰ� �ִٸ�
					// => �����ڸ� ȣ��, 0���� �ʱ�ȭ �ȵ�.

	std::cout << pt.x << std::endl;
}


