// 완벽한전달1 - 113 page
#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

template<typename F>
void chronometry(F f, int arg)
{
	// <<===== 여기서 시간 기록
	f(arg); // 함수호출
	// <<===== 다시 시간 측정후 걸린시간 출력
}

int main()
{
	int n = 10;

	chrometry(foo, 10); // foo(10);
	chrometry(goo, n);  // goo(n);

	std::cout << n << std::endl;
}





