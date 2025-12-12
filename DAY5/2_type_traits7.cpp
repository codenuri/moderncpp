#include <iostream>
#include <type_traits>

template<typename T> void printv(const T& v)
{
	// if : 조건이 false 라면 실행되지 않지만, template instantiation 에는 포함됨
	//      => 생성된 함수에 코드가 포함된다는 의미

	// if constexpr : 조건이 false 라면 template instantiation 에는 포함 하지 말라
	//      => C++17 기술
	if constexpr ( std::is_pointer_v<T>  )
		std::cout << v << " : " << *v << std::endl;
	else
		std::cout << v << std::endl;
}


int main()
{
	int n = 10;

	printv(n); // !!
	printv(&n);
}

