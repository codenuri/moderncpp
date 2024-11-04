#include <iostream>
#include <type_traits>

// 결국 아래 코드는 "매크로의 조건부 컴파일(#ifdef...)" 와 유사하게
// 조건을 만족하는 것만 코드로 남기고 제거하는 코드입니다.

// 그런데, 매크로는 전처리기라서 템플릿 인자 T를 조사할 방법이 없습니다.

// 아래 코드는 컴파일러가 하게 되므로 다양하게 T를 조사할수 있습니다.

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