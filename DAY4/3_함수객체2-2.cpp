#include <iostream>

class URandom
{
public:	
	int operator()()
	{
		return rand() % 10;
	}
};

URandom urand;	// 함수가 아닌 객체 입니다.
				// () 연산자가 재정의되어서 함수 처럼 사용가능





int main()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << urand() << std::endl;
	}
}