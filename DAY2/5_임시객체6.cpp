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

	Counter() = default; // 디폴트 생성자

	Counter( const Counter& c) : cnt{c.cnt}
	{
		std::cout << "복사생성자 호출됨. 생성된 객체 cnt = " << cnt << std::endl;
	}

	~Counter() 
	{
		std::cout << "Counter 파괴 : cnt = " << cnt << std::endl;
	}
};

int main()
{
	Counter c;
	std::cout << "---------------------------------\n";
	c.increment().increment().increment();
	std::cout << "---------------------------------\n";

	std::cout << c.cnt << std::endl; // 결과 예측해 보세요
}