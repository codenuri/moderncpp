// 5_임시객체7.cpp 추가후
// => git 에 코드 있습니다. 복사해 오세요

#include <iostream>

class Counter
{
public:
	int cnt{ 0 };

	Counter increment()
	{
		++cnt;
		return *this;
	}

	Counter() = default;

	~Counter() { std::cout << cnt << " 를 가진 객체 파괴\n"; }

	Counter(const Counter& other) : cnt(other.cnt)
	{
		std::cout << cnt << " 를 가진 객체를 복사해서 객체 생성\n";
	}

};

int main()
{
	Counter c;

	// 아래 처럼 멤버 함수를 연속으로 호출하는 것을
	// => method chaining 이라고 하고 요즘 많은 언어에서 유행합니다.
	std::cout << "------------------------------------\n";
	c.increment().increment().increment();
	std::cout << "------------------------------------\n";

	std::cout << c.cnt << std::endl;
}