#include <iostream>

template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}

template<typename ... Types>
void Show(Types ... args)
{
	// #1. 어떠한 이항 연산자도 올수 있고, 어떤 값도 초기값이 될수 있습니다.
	( std::cout << ... << args );
//	   init	    op ... op args
//  ((( std::cout << 1) << 2 ) << 3

	
	// #2. fold expresson 은 "pack 이름" 뿐 아니라 
	// "pack 이름을 사용하는 패턴" 도 사용가능
	( printv(args) , ... );
	// pack       op ... 
	// printv(1) , ( printv(2), ( printv(3) ) ) )
}

int main()
{
	Show(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
}

// #1 Unary right fold  : (pack op ...)			(E1 op(... op(EN - 1 op EN)))
// #2 Unary left fold   : (... op pack)			(((E1 op E2) op ...) op EN)

// #3 Binary right fold : (pack op ... op init)	(E1 op(... op(EN−1 op(EN op I))))
// #4 Binary left fold  : (init op ... op pack)	((((I op E1) op E2) op ...) op EN)


