#include <type_traits>

// 17_static_if - 51 page

// 아래 코드는 "A" 부분이 에러일까요 ?

template<typename T> void foo(T a)
{
	// if : 실행시간 제어문
	//		조건식의 결과를 컴파일 시간에 알수 있고, false 로 결정되어고
	//      {} 은 항상 "template => 함수 생성"에 포함
	//	    물론 최적화 단계에서 제거 될수 있지만,
	//		"A" 부분은 최적화 이전, 문법 확인 단계에서 컴파일 에러. 
	/*
	if (false)
	{
		*a = 10; // "A"
	}
	*/

	// C++17 : if constexpr 
	// => 컴파일 시간 제어문
	// => 조건식의 결과는 반드시 컴파일 시간에 알수 있어야 하고
	// => 조건식이 false 라면 "template => 실제 함수 생성"에서 포함하지 않고 제거
	if constexpr (false)
	{
		*a = 10; // "A"
	}

	// 실제 활용은 위처럼 무조건 false 가 아닌
	// => T 의 타입 정보등을 조사하는 것

	if constexpr (sizeof(T) > 4)
	{
		// T 가 4바이트보다 큰 타입이면 이 부분 포함 안됨
	}

	if constexpr (std::is_pointer_v<T>)
	{
		// T가 포인터 라면 이부분 제외
	}

}

int main()
{
	foo(0); 
}

