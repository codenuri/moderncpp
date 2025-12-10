#include <iostream>
#include <type_traits>

#define print_value_category(...)	\
	if ( std::is_lvalue_reference_v<decltype( (__VA_ARGS__))>)	\
		printf("[ %s ] is lvalue\n", #__VA_ARGS__);				\
	else  if ( std::is_rvalue_reference_v<decltype((__VA_ARGS__))>)	\
		printf("[ %s ] is rvalue(xvalue)\n", #__VA_ARGS__);			\
	else \
		printf("[ %s ] is rvalue(prvalue)\n", #__VA_ARGS__);			

int main()
{
	int n = 0;
	print_value_category(n);
	print_value_category(n = 3);
	print_value_category(n+1);
	print_value_category(++n);
	print_value_category(n++);

	// 아래 결과 예측해 보세요
	// => 문자열 리터럴은 "메모리 사용" 합니다. 그래서 lvalue
	// => 그외의 모든 리터럴은 rvalue 입니다
	print_value_category(3);		// prvalue
	print_value_category(3.4);		// prvalue
	print_value_category("hello");	// lvalue 


	// print_value_category
	// => 구현은 지금 이해 못해도 됩니다.
	// => 그런데, rvalue/lvalue 공부 하실때 활용하시면 도움이 됩니다.
	//    
}