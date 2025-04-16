#include <iostream>
#include <string>
#include <vector>

// 왜 move가 중요한가 ? - 101 page 

// 아래 코드는 "복사" 에의한 swap 입니다.
// => 느립니다.
/*
template<typename T>
void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}
*/
// 아래 코드는 이동(move) 에의한 swap 입니다.
// => 아주 빠르게 동작합니다.
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
// #1. swap, 버퍼복사 등의 알고리즘 작성시 적절하게 move 를 사용하면 빨라집니다.

// #2. std::string 이 아닌 우리가 만든 클래스가 move 를 지원하게 하려면??
