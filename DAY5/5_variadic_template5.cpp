#include <iostream>

template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}


template<typename ... Types> void foo(Types ... args)
{
//	printv(args...);	// printv(E1, E2, E3) 로 코드가 생성
						// printv 인자는 한개이므로 error

	printv(args)...; // 의도 : printv(E1), printv(E2), printv(E3) 
					 // 하지만 error

	// 핵심 : pack expansion 은  모든 위치에서 할수 있는것은 아니다
	// 1. 함수 호출의 () 안에서   : goo( args...)
	// 2. {} 의 초기화 안에서     : int x[] = {args...}
	// 3. 템플릿 인자의 <> 안에서 만 가능. : tuple<Types...> 

}


int main()
{
	foo(1, 2, 3);
}

