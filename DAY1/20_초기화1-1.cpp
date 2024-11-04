#include <iostream>

int x = 10;

class Test
{
	int value1 = 0;	
	int value2 = ++x;	// 이 위치에 절대 이런 코드는 사용하지 마세요
						// 위 처럼 literal 초기화만 사용하세요
public:
	Test() {}					// Test()      : value1(0), value2(++x) {}
	Test(int n) : value2(n) {}  // Test(int n) : value1(0), value2(n) {}
};
int main()
{
	Test t1;		// 이때는 ++x 수행
	Test t2(5);		// ++x 실행안됨.

	std::cout << x << std::endl; // 결과.. 예측해보세요. ?
								 // 11
}
