#include <iostream>
#include <type_traits>

#define VALUE_CATEGORY( ... )		\
	if (std::is_lvalue_reference_v< decltype(( __VA_ARGS__ )) >)	\
		std::cout << "lvalue\n";									\
	else                                                            \
		std::cout << "rvalue(prvalue)\n";

int main()
{
	int n = 2;

	VALUE_CATEGORY(n);
	VALUE_CATEGORY(n++);
	VALUE_CATEGORY(n+2);
	VALUE_CATEGORY(10);
	VALUE_CATEGORY(3.4);
	VALUE_CATEGORY("hello");

	const int c = 10;
	VALUE_CATEGORY(c);



}
