#include <iostream>
#include <string>
#include <vector>

// 왜 move가 중요한가 ? - 101 page 아래 있습니다.

// 아래 코드는 깊은 복사 기반의 swap 입니다.
// => 느립니다.
// => C++98 시절 표준 "std::swap"
/*
template<typename T>
void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}
*/
// 아래 코드는 move 기반 swap 입니다.
// => 아주 빠릅니다.
// => 메모리 자체의 교환이 아닌 주소의 교환!!
// => C++11 시절 표준 "std::swap"
template<typename T>
void Swap(T& a, T& b)
{
	T tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);
}

int main()
{
	std::string s1 = "to be or not to be";
	std::string s2 = "abcd efg hijk lmn";
	Swap(s1, s2);
}


// 왜 move 를 중요시 하는가 ?
// 그리고, 무엇을 알아야 하는가 ?
// 
// 1. 일부 알고리즘 작성시 "복사" 보다 "move" 를 사용하면 빠르게 동작합니다.
// => std::swap()
// => 버퍼 복사등.
// => 사용자들이 만드는 코드에서 "적절히 std::move()" 를 사용할수 있어야 합니다.

// 2. 사용자가 만드는 클래스도 move 를 지원하려면 어떻게 해야 하나 ?
// People p1{"kim", 20};
// People p2 = std::move(p1); // 이 코드를 지원하려면 People 을 어떻게 만들어야 하나?
// => 약간 어려운 내용
// => move 의 근본 원리(다음예제 부터)

