#include <iostream>
#include <type_traits>

template<typename T>
void foo(T& a)
{
	// std::is_pointer_v<T> : T가 포인터 인지 조사
	//						  컴파일 시간에 조사(목요일날 자세히)
	if constexpr (std::is_pointer_v<T>)
	{
		std::cout << "포인터에 최적화된 알고리즘\n";
	}
	else if constexpr( std::is_reference_v<T> )
		std::cout << "레퍼런스 최적화된 알고리즘\n";
	else
		std::cout << "그외 알고리즘\n";
}
int main()
{
	int n = 0;
	foo(&n);
}