#include <iostream>
#include <vector>
#include <functional>

// 아래 코드에서 문제점 찾으세요!!
int main()
{
	std::function<int(int, int)> f;

	{
		int n = 10;

		f = [&n](int a, int b) { return a + b + n; };
	}

	int ret = f(1, 2);
}





