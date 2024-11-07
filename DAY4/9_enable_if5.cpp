#include <iostream>
#include <type_traits>

// if constexpr 은 C++17 에서 표준에 추가
// => C++17 이전에는 enable_if 등의 기술로 해결

// 포인터와 포인터가 아닌 알고리즘의 별도의 함수 템플릿으로 만든후에
// => enable_if 기술로 조건을 만족할때 만 사용되도록!!!

// github.com/aosp-mirror		(안드로이드 소스)
// platform system core 레포지토리
// libutils/include/utils 경로에서 TypeHelpers.h 파일
//								copy_type() 함수 찾으세요

template<typename T> 
std::enable_if_t< std::is_pointer_v<T>>
printv(const T& v)
{
	std::cout << v << " : " << *v << std::endl;
}

template<typename T> 
std::enable_if_t< !std::is_pointer_v<T>>
printv(const T& v)
{
	std::cout << v << std::endl;
}

int main()
{
	int n = 10;

	printv(n);
	printv(&n);
}
