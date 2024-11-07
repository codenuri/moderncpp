#include <iostream>
#include <vector>
#include <functional>

// 아래 코드에서 문제점 찾으세요!!
int main()
{
//	auto f; // error. 초기화 되지 않은 auto 변수는 만들수 없음.

	std::function<int(int, int)> f;

	{
		int n = 10;

		f = [&n](int a, int b) { return a + b + n; };

		// f 는 멤버 데이타로 "n의 참조" 보관

	} // <<=== 그런데, 여기서 n 파괴

	int ret = f(1, 2); // 버그. 파괴된 n 사용. undefined 
}





