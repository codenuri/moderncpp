#include <iostream>

// 0 ~ 9 사이의 "중복되지 않은 난수" 를 반환하는 함수
int urand()
{
	return rand() % 10;
}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << urand() << std::endl;
	}
}