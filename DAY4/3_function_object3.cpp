#include <iostream>
#include <bitset>


class URandom
{
public:
	int operator()()
	{
		return rand() % 10;
	}
};

URandom urand; // urand 는 객체 지만 함수 처럼 사용가능합니다.


int main()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << urand() << std::endl;
	}
}
