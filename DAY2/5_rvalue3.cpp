#include <iostream>
#include <type_traits>

int main()
{
	int n = 2;
	
	// decltype(expression)
	// => 표현식의 타입과 value category 를 조사할수 있다.
	// => expression 이 lvalue 라면 참조 타입
	// => expression 이 rvalue 라면 값 타입

	if (std::is_lvalue_reference_v< decltype( ( n ) ) >)
		std::cout << "lvalue\n";
	else 
		std::cout << "rvalue(prvalue)\n";

}
