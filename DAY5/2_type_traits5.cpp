#include <iostream>
#include <type_traits>

// 참고 : C++ 표준
// remove_pointer 는 있지만 remove_all_pointer 는 없음. 

template<typename T> struct remove_all_pointer
{
	using type = T;
};

template<typename T> struct remove_all_pointer<T*>
{
	// 컴파일 시간 재귀를 사용해서 모든 포인터 제거
	// => 재귀의 종료는 "T 가 더이상 포인터가 아닌 경우", primary 사용하므로 종료!
	using type = typename remove_all_pointer<T>::type ;
};

int main()
{
	remove_all_pointer<int***>::type n;
}
