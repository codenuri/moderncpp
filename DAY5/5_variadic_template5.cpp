#include <iostream>
#include <tuple>

template<typename ... Types> void foo(Types ... args)
{
	// args 에 있는 모든 요소를 꺼내고 싶다면

	// args 에서 2번째 요소만 꺼내고 싶다. => C++26 부터 가능
	// int n = args...[2]; // pack indexing 문법

	// args 에서 요소는 꺼내는 모든 기술
	// 1. pack expansion      - C++11
	// 2. recursive 유사 기술  - C++11
	// 3. fold expression     - C++17
	// 4. pack indexing       - C++26

	// #1. pack expansion
	int x[] = { args... };

}


int main()
{
	foo(1, 2, 3);
}

