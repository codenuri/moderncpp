// 6_����_��������ĸ��1 - 146
#include <iostream>

int main()
{
//	Point pt = Point{ 0, 0 } // => Point pt{0,0}

	int v1 = 10, v2 = 10;

	// ���� ǥ���� : () �����ڰ� ��� ��� �Լ� �Դϴ�.
	// mutable ���� ǥ����  : () �����ڰ� ��� ��� �Լ��� �ƴմϴ�.
	auto f1 = [v1, v2](int a) mutable { v1 = 100; return a + v1 + v2; }; 


	f1(0); // v1 = 100 �����. ������ ����ǥ���İ�ü���� ���纻�� ����Ȱ�


	std::cout << v1 << std::endl; // 10


	std::cout << sizeof(f1) << std::endl; // ???



	/*
	// �������� ĸ���� ����
	class CompilerGeneratedName
	{
		// ���������� ĸ���ϸ� ��� ����Ÿ�� �߰� �˴ϴ�.
		int v1;
		int v2;
	public:
		CompilerGeneratedName(int a, int b) : v1(a), v2(b) {}

//		inline auto operator()(int a) const 
		inline auto operator()(int a)			// mutable ���� ǥ����
		{
			v1 = 100;
			return a + v1 + v2;
		}
	};
	auto f1 = CompilerGeneratedName{ v1, v2 }; // main ���������� ���������ڷ�����

	*/


}






