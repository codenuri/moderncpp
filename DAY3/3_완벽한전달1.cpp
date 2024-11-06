// 완벽한전달1 - 113 page
#include <iostream>


// forwarding : 전달 받은 인자를 다른 함수에 보내는 것
// perfect forwarding
// => 전달 받은 인자를 어떤한 변경도 없이 다른 곳에 전달하는 것
//    (값, 타입, 상수성, value 속성등 어떠한 변화도 없어야 한다.)


void foo(int a)  {}
void goo(int& a) { a = 100; }

template<typename F>
//void chronometry(F f, int arg) // 복사본 생성. 완벽한 전달 안됨.
//void chronometry(F f, int& arg)  // 10을 받을수 없다.
void chronometry(F f, const int& arg)  // 상수성 추가.
{										// goo(arg) 는 에러!
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





