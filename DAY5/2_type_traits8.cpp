#include <iostream>
#include <type_traits>

int main()
{
	int n = 10;

	(n + 3) = 10;	// error. n + 3 은 rvalue
	(n = 3) = 10;   // ok     n = 3 은 lvalue

	// decltype(expr) : 규칙 2. expr 이 lvalue 라면 참조 타입, 아니면 값 타입
	
	

	if (std::is_lvalue_reference_v<  decltype( (n = 3) )  > == true)
	{
			std::cout << "lvalue\n";
	}

}
