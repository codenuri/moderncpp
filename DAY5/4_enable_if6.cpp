#include <iostream>
#include <type_traits>


// C++20 부터 template 만들때 requires clause 라는 것을 붙일수 있습니다.
// => enable_if 를 문법으로 발전시킨것

template<typename T> requires std::is_pointer_v<T>
void printv(const T& v)
{
	std::cout << "포인터 " << v << " : " << *v << std::endl;
}

template<typename T> requires (!std::is_pointer_v<T>)
void printv(const T& v) 
{
	std::cout << "포인터 아님 " << v << std::endl;
}



int main()
{
	int n = 10;
	double d = 3.4;

	printv(n);
	printv(d);
	printv(&n);
}

