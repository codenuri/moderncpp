#include <iostream>

int x = 10;

class Test
{
	int value1 = 0;		// ok. 좋은 코드
	int value2 = ++x;	// 에러는 아니지만 절대 사용하지 마세요
						// 혼란스러운 코드 입니다..
public:
	Test() {}					// value1(0), value2(++x)
	Test(int n) : value2(n) {}	// value1(0)
};

int main()
{
	Test t1;
	Test t2(5);

	// 아래 코드의 실행결과를 예측해 보세요 
	std::cout << x << std::endl; // 10 ? 11 ? 12  ===> 11
}