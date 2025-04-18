// FOLD - 237 page
#include <iostream>


template<typename ... Types> 
int Sum(Types ... args)
{
	// args     : 1,  2,  3,  4,  5,  6,  7,  8,  9, 10
	// 원하는것  : 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10

	int s = (args + ...);		// args 가 비어있으면 에러
//		    ( 1 + ( 2 + ( 3 + ( 4 + 5 ))))

//	int s = (... + args);
//			((((1 +2 )+ 3)+ 4)+5			

//	int s = (args + ... + 0);	// args 가 비어있어도 ok
//			( 1 + ( 2 + ( 3 + ( 4 + (5 + 0 ))))

	return s;
}

int main()
{
//	int n = Sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	int n = Sum();

	std::cout << n << std::endl;
}

// Fold Expression : 가변인자 템플릿의 모든 요소에 이항 연산을 수행 - C++17
// => 4가지 형태


// #1 Unary right fold  : (pack op ...)			(E1 op(... op(EN - 1 op EN)))
// #2 Unary left fold   : (... op pack)			(((E1 op E2) op ...) op EN)

// #3 Binary right fold : (pack op ... op init)	(E1 op(... op(EN−1 op(EN op I))))
// #4 Binary left fold  : (init op ... op pack)	((((I op E1) op E2) op ...) op EN)
//	=> Binary fold 는 Unary fold 에 초기값이 추가된것
