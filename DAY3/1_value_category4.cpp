#include <iostream>
#include <type_traits>

#define VALUE_CATEGORY(...)											\
	if (std::is_lvalue_reference_v< decltype(( __VA_ARGS__ )) >)	\
		std::cout << "lvalue\n";									\
	else                                                            \
		std::cout << "rvalue\n";


int main()
{
	int n = 0;

	VALUE_CATEGORY(n);		// lvalue
	VALUE_CATEGORY(n+2);
	VALUE_CATEGORY(++n);	// lvalue
	VALUE_CATEGORY(n++);
	VALUE_CATEGORY(10);

	std::string s = "AA";
	VALUE_CATEGORY(s);		// lvalue
	VALUE_CATEGORY(std::string{"aa"}); // 임시객체, rvalue


	VALUE_CATEGORY(10);		// 정수, 실수 리터럴은 rvalue	
	VALUE_CATEGORY("AAA");	// 문자열 리터럴만 lvalue
							// => 문자열 리터럴은 코드메모리가아닌
							// => 데이타 메모리(상수메모리) 사용

//	&10;    // error
	&"AAA"; // ok
}
