// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	// capture by reference
	// => 멤버 데이타는 값이 아닌 참조로 해달라는것
	// => 원본 지역변수 수정가능
	auto f2 = [&v1, &v2](int a) { v1 = 100; return a + v1 + v2; }; 

	f2(0);

	std::cout << v1 << std::endl; // 100

	/*
	class CompilerGeneratedName
	{
		int& v1;
		int& v2;
	public:
		CompilerGeneratedName(int& n1, int& n2) : v1(n1), v2(n2) {}

		inline auto operator()(int a) const	
		{
			v1 = 100;	
			return a + v1 + v2;
		}
	};
	*/
}





