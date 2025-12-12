#include <iostream>

template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}

template<typename ... Types> void foo(Types ... args)
{
	// args : 1, 2, 3
//	printv(args...);	// printv(1,2,3) 이므로 error

	printv(args)...;   // printv(1), printv(2), printv(3) 의 의도
						// 하지만 error

	// pack expansion 이 가능한 위치
	// 1. 함수 인자의 () 안 : goo(args...)
	// 2. {} 초기화 안     : int x[3] = { args... }
	// 3. 템플릿 인자      : std::tuple<Types...>
	// 그 외는 안됨

	// printv 에 3개를 보내려면
	// C++11/14 시절
	int x[] = { 0, (printv(args), 0)... }; // { (printv(1), 0), (printv(2), 0), (printv(3), 0)

	// C++17 이후
	// => fold expression 사용 
}


int main()
{
	foo(1, 2, 3);
}

