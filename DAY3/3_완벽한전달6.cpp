#include <iostream>

int& foo(int a, double d, int& n) { n = 100; return n; }

void f1() {}
void f2(int n) {}

// 정리 : 완벽한 전달을 하려면
// 1. 인자를 받을때 T&& 로 받아야 합니다.
// 2. 인자를 다른 함수에 보낼때 "std::forward<T>(arg)" 로 묶어야 합니다.
// 3. 반환값도 완벽히 돌려주려면 "decltype(auto)" 로 하세요
// 4. 인자 갯수에 상관없이 하려면 "가변인자 템플릿" 사용
//    (금요일 배우게됩니다.)

template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg)
{
	return f( std::forward<T>(arg)... );  
}

int main()
{
	int n = 10;

	chronometry(f1); // 인자없는 함수
	chronometry(f2, 3);
	
	int& ret = chronometry(foo, 5, 3.4, n);

	std::cout << n << std::endl; // 100
	ret = 300;
	std::cout << n << std::endl; // 300
}





