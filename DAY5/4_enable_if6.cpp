#include <iostream>
#include <type_traits>

// enable_if 기술
// => 문법이라기 보다는 "코딩 테크닉에 가깝습니다."
// => 아주 어려운것은 아니지만 항상 코드가 복잡해 보입니다.
// => 단점 반환 타입이 가독성이 좋지 않습니다.
// 
// C++20 부터
// => 이 기술을 문법화 하게 되었습니다.
// => requires 키워드 추가

template<typename T> requires std::is_pointer_v<T>
void printv(const T& v)
{
	std::cout << "포인터 일때\n";
	std::cout << v << " : " << *v << std::endl;
}

template<typename T> requires (!std::is_pointer_v<T>)
void printv(const T& v)
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


