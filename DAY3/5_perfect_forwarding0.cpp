#include <iostream>

// 90 page 
void foo(int& a)		{ std::cout << "int&" << std::endl; }
void foo(const int& a)	{ std::cout << "const int&" << std::endl; }
void foo(int&& a)		{ std::cout << "int&&" << std::endl; }

int main()
{
	int n = 10;
	foo(n);		// int&
	foo(10);	// int&&

	int& r1 = n;
	foo(r1);	// int&


	int&& r2 = 10;
	foo(r2);	// int& 

	// int n = 0
	// Point pt{1,2};
	// 
	// Ÿ�԰� value category �� �� �����ϼ���

	//				Ÿ��				value category
	// n			int				lvalue		
	// 10			int				rvalue
	// pt			Point			lvalue	
	// Point{1,2}	Point			rvalue
	// r1			int&			lvalue
	// r2			int&&			lvalue ( r2��� �̸��� �ִ�)

	// foo(int&)  : int& Ÿ���� �ްڴٴ� ���� �ƴ϶� lvalue �� �ްڴ�
	// foo(int&&) : int&& Ÿ���� �ްڴٴ� ���� �ƴ϶� rvalue �� �ްڴ�

	foo(r2); // int& 

	// r2�� foo(int&&) �� �������� rvalue �� ĳ���� �ʿ�
	foo(static_cast<int&&>(r2)); // int&&
	foo(std::move((r2));		 // int&&

	// �����Ҷ�  ���ۿ��� �˻��� ������
	// "named rvalue reference is lvalue"
}







