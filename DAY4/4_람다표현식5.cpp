// 143 
#include <functional>
#include <vector>

void foo(int(*f)(int, int)) {} 

int main()
{
	// #1. 람다표현식을 담는 방법

	auto f1			   = [](int a, int b) { return a + b; };  

	int(*f2)(int, int) = [](int a, int b) { return a + b; };

	std::function<int(int, int)> f3 = [](int a, int b) { return a + b; };


	// #2. 인라인 치환 여부
	int ret1 = f1(1, 2);			// 이 코드는 컴파일러에 의해
//  int ret1 = f1.operator()(1,2)	// 이렇게 변경됩니다. 즉, 함수이름으로 호출
								    // 따라서 인라인 치환됩니다.

	int ret2 = f2(1, 2); // 인라인 치환 안됨
	int ret3 = f3(1, 2); // 인라인 치환 안됨.

	// => f1 에는 다른 람다 표현식 담을수 없음
	// => f2, f3 는 다른 람다 표현식 담을수 있음
	//----------------------------------------------------
	
	// 함수 포인터의 경우
	// => 캡쳐한 람다 표현식은 함수 포인터로 변경될수 없습니다.(마지막 예제)
	// => C언어와의 호환성이 필요할때 사용하세요
	foo( [](int a, int b) { return a + b; } );


	// #3. 여러개 람다 표현식을 컨테이너에 보관하고 싶다.

	std::vector<auto> v1; // ?

	std::vector<int(*)(int, int)> v2; // ?

	std::vector<std::function<int(int, int)> v3; // ?
}