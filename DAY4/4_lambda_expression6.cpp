#include <iostream>
#include <vector>
#include <functional>

int main()
{
	// #1. 람다표현식을 담는 방법
	auto f1 = [](int a, int b) { return a + b; };	// #1. auto
	
	int(*f2)(int, int) = [](int a, int b) { return a + b; }; // #2. 함수포인터
						// 임시객체

	std::function<int(int, int)> f3 = [](int a, int b) { return a + b; }; 
															// #3. std::function

	// 아래 코드의 인라인 치환성에 대해서 생각해보세요
	f1(1, 2); // f1.operator()(1,2) 인라인 치환 가능성 아주 높음.
	f2(1, 2); // 함수주소를 변수에 담아서 사용 - 인라인 치환 안됨
	f3(1, 2); // 결국 주소를 보관했다가 호출. 인라인 치환안됨


	// #2. 람다표현식과 컨테이너
	// => std::vector, 배열 등의 컨테이너 : 같은 타입만 보관가능
	// => 모든 람다 표현식은 다른 타입
	// => 타입성을 유지하면서 보관할 방법은 없음
//	std::vector<auto> v; // error. 이런 코드는 안됨.

	std::vector<int(*)(int, int)> v1; // 가능하지만 권장 안함
								     // 캡쳐한 람다 보관안됨.

	std::vector< std::function<int(int, int)> > v2; // ok. 최선의 방법
													// 캡쳐한 람다도 가능.
	v1.push_back([](int a, int b) { return a + b; });
	v1.push_back([](int a, int b) { return a - b; });

	v2.push_back([](int a, int b) { return a + b; });
	v2.push_back([](int a, int b) { return a - b; });

	int n1 = v1[0](1, 2);
	int n2 = v2[0](1, 2);

}




