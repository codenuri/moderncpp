// 5_람다표현식1
#include <iostream>
#include <algorithm>
#include <functional>

// 

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

	// 위 한줄의 원리
	// => 컴파일러가 위 한줄을 아래 코드로 변경합니다.

	class CompilerGeneratedName
	{
	public:
		inline auto operator()(int a, int b) const
		{
			return a < b;
		}
	};

	std::sort(v.begin(), v.end(), CompilerGeneratedName{} );

}

// 람다 표현식
// => 함수 객체를 만드는 표기법입니다.
// => 람다 표현식이 없어도, 사용자가 직접 함수 객체 클래스 만들면 됩니다.

// 람다 표현식(lambda expression)
// => "표현식(expression)" 이므로 하나의 값을 만드는 코드!!
// => 결국 람다 표현식은 "임시객체(rvalue)" 를 만드는 표기법



