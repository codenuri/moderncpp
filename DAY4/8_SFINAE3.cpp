#include <iostream>

int foo(...) { std::cout << "..." << std::endl; return 0; }

template<typename T>
int foo(T a) 
{ 
	typename T::type n; // SFINAE 가 적용될까요 ?
					    // 에러가 나올까요 ?
	return 0; 
}


int main()
{
	foo(3); 
}
