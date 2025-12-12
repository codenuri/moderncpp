#include <iostream>
#include <type_traits>

// T가 포인터 인지 조사하는 기술

// #1. primary template struct 을 만들고 false 반환(value = false 라는 의미)
// #2. 조건을 만족하는 partial specialization 에서 true 반환


template<typename T> struct is_pointer
{
//	bool value = false;		// 1. C++98 시절에는 필드 초기화 없음.
							// 2. value 가 변수임. 컴파일 시간에 활용안됨

//	enum { value = false }; // C++98 시절에 "컴파일 시간에 활용 가능하고", 
							//			    "구조체 안에서 값을 넣을수 있는" 유일한 방법
							// "enum hack" 이라고 불리던 기술. 
	
	// C++11 부터는 enum 이 아닌 constexpr 사용
	// => static constexpr 은 필드 초기화 가능. 외부 정의 필요없음.
	// => value 가 int 가 아닌 bool 타입. 보다 명확해짐
	static constexpr bool value = false;
};

template<typename T> struct is_pointer<T*>
{
//	enum { value = true };
	static constexpr bool value = true;
};

template<typename T> void foo(const T& a)
{
	// T : int, int*
	if ( is_pointer<T>::value )
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
