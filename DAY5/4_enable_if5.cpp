// printv 복사 - trait7 복사
#include <iostream>
#include <type_traits>

// 아래 코드는 C++17 부터 가능.
/*
template<typename T> void printv(const T& v)
{
	if constexpr (std::is_pointer_v<T>)
		std::cout << v << " : " << *v << std::endl;
	else
		std::cout << v << std::endl;
}
*/
// 아래 코드는 C++11 부터 사용가능. 
template<typename T> 

std::enable_if_t< std::is_pointer_v<T> > 

printv(const T& v)
{
	std::cout << "포인터 일때\n";
	std::cout << v << " : " << *v << std::endl;
}

template<typename T> 

std::enable_if_t< !std::is_pointer_v<T> >

printv(const T& v)
{	
	std::cout << "포인터 아닐때\n";
	std::cout << v << std::endl;
}


int main()
{
	int n = 10;

	printv(n); // !!
	printv(&n);
}


