// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int main()
{
	int v1 = 10, v2 = 10;


//	auto f1 = [v1, v2](int a) mutable { v1 = 100; return a + v1 + v2; };

	auto f1 = [&v1, &v2](int a) { v1 = 100; return a + v1 + v2; };

	f1(0);  // main 함수의 원본 v1 변경

	std::cout << v1 << std::endl; // 100





	/*
	class CompilerGeneratedName
	{
		int& v1;
		int& v2;
	public:
		CompilerGeneratedName(int& a, int& b) : v1(a), v2(b) {}

		inline auto operator()(int a) const
		{
			v1 = 100;	// reference 는 결국 포인터
						// 이 코드는 v1 자체를 변경하는 것이 아니라
						// v1 이 가리키는 곳을 변경한것
						// 따라서 "상수 멤버 함수" 안에서도 사용가능. 

			return a + v1 + v2;
		}
	};
	auto f1 = CompilerGeneratedName{ v1, v2 }; 

	*/


}






