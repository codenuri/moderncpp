#include <iostream>
#include <string>
#include <vector>

// 왜 move가 중요한가 ? - 101 page 아래 있습니다.

// #1. 복사생성자(깊은복사)에 의한 swap
// => 자원 복제가 발생하므로 성능이 좋지 않습니다.

template<typename T>
void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

// #2. move 를 사용한 swap
// => 자원의 이동(포인터 복사)에 의한 swap
// => 성능이 좋습니다.
template<typename T>
void Swap(T& a, T& b)
{
	T tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);
}

int main()
{
	std::string s1 = "hello";
	std::string s2 = "world";
	Swap(s1, s2);
}
// move 에서 알아야 하는 것
// #1. swap 같은 알고리즘 작성시 적절하게 std::move() 사용하면 빨라진다는 것
// 
// #2. std::string 이 아닌 사용자가 만든 타입이 move 개념을 지원하려면 
//     어떻게해야 하는가 ?
//     => 핵심!!


