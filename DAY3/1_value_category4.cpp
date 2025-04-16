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

	VALUE_CATEGORY(n);
	VALUE_CATEGORY(n+2);
	VALUE_CATEGORY(++n);
	VALUE_CATEGORY(n++);
	VALUE_CATEGORY(10);

	std::string s = "AA";
	VALUE_CATEGORY(s);
	VALUE_CATEGORY(std::string{"aa"}); // ÀÓ½Ã°´Ã¼ 

}
