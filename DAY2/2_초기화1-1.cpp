#include <iostream>

int x = 10;

class Test
{
	int value1 = 0;		// 좋은 코드 사용하세요
	int value2 = ++x;	// 나쁜 코드, 절대 사용하지 마세요. 가독성 저하!
public:
	Test() {}					// Test() : value1(0), value2(++x) {}
	Test(int n) : value2(n) {}	// Test() : value1(0), value2(n) {}
};

int main()
{
	Test t1;
	Test t2(5);

	// 결과를 예측해 보세요
	std::cout << x << std::endl; // 11
}
