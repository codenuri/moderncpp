#include <iostream>
#include <algorithm>
#include <functional>

// 람다 표현식의 원리 - 140p

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

	// 람다 표현식
	// => "함수객체"를 만들어 달라는 요청. 
	// lambda expression 의 최종 결과 : 임시객체, prvalue
	
	// 클로져(Closure)
	// => 람다표현식이 만드는 임시객체

	// 위 한줄을 컴파일러가 아래 처럼 변경합니다.
	
	class CompilerGeneratedName  // ( ClosureType )
	{
	public:
		inline auto operator()(int a, int b) const
		{
			return a < b;
		}
	};
	std::sort(v.begin(), v.end(), CompilerGeneratedName{} );

}





