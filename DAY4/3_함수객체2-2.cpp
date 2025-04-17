#include <iostream>

// 함수 객체는 "동작" 뿐 아니라 "상태"도 있습니다.
// => "멤버 데이타"가 있다는 의미.
// => 생성자, 멤버 함수등도 활용 가능합니다.

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