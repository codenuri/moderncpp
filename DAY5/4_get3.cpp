#include "tuple.h"
#include <iostream>

// 이 소스의 핵심 : tuple_element 만들기. - 이미 표준에도 있습니다.

// primary template
// => 사용자가 사용하는 모양을 잘 생각해서 만들면 됩니다.
template<int N, typename T>
struct tuple_element
{
//	using type = ? ; // 튜플 T의 N 번째 요소의 타입인 ? 를
					 // 여기서는 알수 없습니다.
					 // 알수 있도록 "부분 특수화" 해야 합니다.
};

// 이제 타입을 구할수 있도록 부분 특수화 해야 합니다
// => N == 0 일때 부터 생각해야 합니다
/*
template<typename T>
struct tuple_element<0, T>
{
	using type = ? ;	// 아직 튜플  T 에서 0번째 요소 타입알수 없습니다.
						// 잘못된 부분 특수화
};
*/
/*
template<typename ... Ts>
struct tuple_element<0, tuple<Ts...> >
{
	using type = ? ; // tuple 이라는 정보가 나타나도록 했지만
					 // 아직 0번째 타입을 알수없다.
					 // 잘못된 부분 특수화
};
*/

// N == 0 해결
// => 아래 처럼 알고싶은 정보가 나타나도록 부분 특수화 하는 것이 핵심
template<typename T, typename ... Ts>
struct tuple_element<0, tuple<T, Ts...> >
{
	using type = T ; 
};

// N != 0
template<int N, typename T, typename ... Ts>
struct tuple_element<N, tuple<T, Ts...> >
{
	// tuple<int, double, char> 의 2번째 타입은
	// tuple<     double, char> 의 1번째 타입이고
	// tuple<             char> 의 0번째 타입이다(N==0 이 해결)
	using type = T;
};



template<typename TP>
void foo(TP& tp)
{
	// TP : tuple<int, double, char>
	typename tuple_element<0, TP>::type n1;
	typename tuple_element<1, TP>::type n2;

	std::cout << typeid(n1).name() << std::endl; // int
	std::cout << typeid(n2).name() << std::endl; // double
}
int main()
{
	tuple<int, double, char> t3(1, 3.4, 'A');
	foo(t3);
}