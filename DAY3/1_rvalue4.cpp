#include <iostream>
#include <type_traits>

int main()
{
	int n = 0;

	n = 10; // ok

	(n + 1) = 10; // error. "n + 1" 표현식(코드)는 rvalue
	(n = 1) = 10; // ok.    "n = 1" 의 최종결과는 n, 즉 lvalue

	// decltype(expression)
	// => expression 을 조사하는 도구. 타입, value category
	// => 규칙 1. expression 이 이름만 있는 경우, 선언을 보고 조사
	// => 규칙 2. expression 이 "이름+다른코드" 라면
	//	          expression lvalue 인경우 => 참조 타입
	//			  expression prvalue 인경우 => 값 타입
	//			  expression xvalue 인경우 => rvalue참조(&&) 타입

//	using Type = decltype(n + 1); // int
	using Type = decltype(n = 1); // int&

	// Type 이 참조인지 조사하는 기술 - 금요일 자세히 배웁니다.
	if (std::is_lvalue_reference_v<Type>)
		std::cout << "lvalue\n";
	else if (std::is_rvalue_reference_v<Type>)
		std::cout << "rvalue(xvalue)\n";
	else	// 값 타입
		std::cout << "rvalue(prvalue)\n";

}