#include <iostream>
#include <type_traits>

// decltype(expression)
// => expression 의 result 를 조사하는 도구
// => type 과 value category 조사

// expression 이 lvalue 라면 : 참조 타입
// expression 이 rvalue 라면 : 값 타입
int main()
{
	int n = 0;

	n * 3 + 2;

//	using T = decltype(n * 3 + 2);
//	using T = decltype(n); // 이렇게조사하면 규칙 #1 사용
						   // lvalue, rvalue 조사가 아니라 선언으로 결정
	using T = decltype((n)); // 규칙 #2를 사용하게 하기 위해
							//  expression 을 () 로 묶은것

	if (std::is_lvalue_reference_v<T>) // T 가 참조인지 조사하는것
	{
		std::cout << "lvalue\n";
	}
	else
	{
		std::cout << "rvalue\n";
	}
}
// 언어 버전 C++17로 설정하고 실행해 보세요. 