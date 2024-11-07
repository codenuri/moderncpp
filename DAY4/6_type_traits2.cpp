#include <iostream>
#include <type_traits>

// 템플릿 인자 T가 포인터 인지 조사하는 기술

template<typename T> struct is_pointer
{
//	bool value = false; // 1. C++11 이전에는 이렇게 초기화 안됨
						// 2. 이렇게 하면 value 가 컴파일 시간 상수 아닌 변수

//	enum { value = false }; // C++11 이전에 유일한 방법

	static constexpr bool value = false; // 요즘은 이렇게 구현
};

template<typename T> struct is_pointer<T*>
{
//	enum { value = true };
	static constexpr bool value = true;
};



template<typename T> void foo(const T& a)
{
	// T : int,  int*
	if ( is_pointer<T>::value  )
		std::cout << "포인터" << std::endl;
	else
		std::cout << "포인터 아님" << std::endl;
}
int main()
{
	int n = 0;
	foo(n);
	foo(&n);
}
