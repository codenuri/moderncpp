// 8_nullptr2
#include <iostream>

void foo(int* p) {}

int main()
{
	forward_parameter(&foo, 0); 
	forward_parameter(&foo, nullptr);
}

template<typename F, typename ARG>
void forward_parameter(F f, ARG arg) 
{
	f(arg); 
}






