#include <iostream>
#include <bitset>

// 일반 함수 
// => 동작만 있고, 상태가 없다.!
// => 실행중에 만들어진 데이타를 보관했다가 다음번 호출시 사용하고 싶을때
//    저장할 장소가 없다.
// => 전역변수등이 필요하다.

// 0 ~ 9 사이의 "중복 되지 않는" 난수를 반환하는 함수
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
