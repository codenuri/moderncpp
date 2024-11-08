#include "tuple.h"
#include <iostream>


// 결국 부분 특수화 버전만 사용하고(N==0, N!= 0) 
// primary template 은 사용되지 않습니다.
// 선언만 있으면 됩니다.
template<int N, typename T>
struct tuple_element;

template<typename T, typename ... Ts>
struct tuple_element<0, tuple<T, Ts...> >
{
	using type = T;						// 0번째 요소타입
	using tupleType = tuple<T, Ts...>;	// 0번째 요소를 저장하는 tuple 타입
};

template<int N, typename T, typename ... Ts>
struct tuple_element<N, tuple<T, Ts...> >
{
	using type = typename tuple_element<N - 1, tuple<Ts...>>::type;
	using tupleType = typename tuple_element<N - 1, tuple<Ts...>>::tupleType;
};

template<int N, typename TP>
typename tuple_element<N, TP>::type&
get(TP& tp)
{
	return static_cast<typename tuple_element<N, TP>::tupleType&>(tp).value;
}

int main()
{
	tuple<int, double, char> t3(1, 3.4, 'A');
	
	get<0>(t3) = 10;

	printf("%d\n", get<0>(t3));

//	std::cout << get<0>(t3) << std::endl; // 10
//	std::cout << get<1>(t3) << std::endl; // 3.4
//	std::cout << get<2>(t3) << std::endl; // 'A'
}

// godbolt.org 접속. 위소스 넣으세요
// tuple.h 도 헤더 지우고, 소스로 넣으세요