#include <iostream>
#include <bitset>

// 함수 객체
// => 동작 뿐 아니라, 상태를 가진다(멤버 데이타가 있다는 의미)
// => 생성자/소멸자 등도 활용 가능하다.

class URandom
{
	std::bitset<10> bs; // 10 개 비트를 관리하는 STL
	bool recycle;
public:
	URandom(bool b = false) : recycle{ b }
	{
//		bs.set(3); // 3번째 비트만 1로
		bs.set();  // 모든 비트를 1로
	}
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
