#include <iostream>
#include <algorithm>
#include <functional>

// 람다 표현식의 원리

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

	// ------------------------------------------------------------
	// 위 한줄을 보고 컴파일러는 아래 의미의 코드를 생성합니다.

	class CompilerGeneratedName
	{
	public:
		inline auto operator()(int a, int b) const
		{
			return a < b;
		}
	};

	std::sort(v.begin(), v.end(), CompilerGeneratedName{} );


	// 결국 람다 표현식은 "함수객체를 자동으로 만드는 표기법"
	// 람다 표현식(expression) 인데 "expression 이므로" 하나의 값 생성
	// => 결국 위 임시객체 만든것
	// => 람다 표현식의 최종 결과는 "rvalue" 입니다.
}





