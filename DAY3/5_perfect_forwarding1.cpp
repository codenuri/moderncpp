// 7_완벽한전달1 - 113 page
#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

// perfect forwarding(완벽한 전달) 이란 ?
// => 인자로 받은 값을 다른 함수에 전달할때
// => 원본 그대로 어떠한 변화도 없이 전달하는 기술
// => 이 기술만 있다면, 다양한 훌륭한 라이브러리를 구축할수 있다.(내일 다양한 활용)

// 함수의 성능을 측정하는 함수
template<typename F>
void chronometry(F f, const int& arg)
{
	// <=============== 현재 시간 기록
	f(arg);			//  함수 호출
	// <=============== 소요 시간 출력
}

int main()
{
	int n = 10;

	chronometry(foo, 10); // foo(10);
	chronometry(goo, n);  // goo(n);

	std::cout << n << std::endl;
}
