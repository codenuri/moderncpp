#include <iostream>

class Counter 
{
public:
	int cnt = 0;

	Counter increment()
	{
		++cnt;
		return *this;
	}
};

int main()
{
	Counter c;
	c.increment().increment().increment();

	std::cout << c.cnt << std::endl; // 결과 예측해 보세요
}