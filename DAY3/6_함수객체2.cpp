#include <iostream>

// 함수객체와 const member function
// => 함수 객체 만들때 대부분 operator() 는 상수멤버 함수로 하게 됩니다.
// => 나중에 "람다 표현식" 배울때 이 부분이 중요!

struct Plus
{
	int operator()(int a, int b) const
	{
		return a + b;
	}
};

// 함수객체의 크기가 작다면 call by value 도 가능하지만
// 크기가 큰 것도 있을수 있으므로 보통 const T& 사용
template<typename T> void foo(const T& f)
{
	int ret = f(1, 2); // f.operator()(1,2) 인데
						// 상수객체는 "상수 멤버 함수"만 호출할수있다.
}

int main()
{
	Plus p;
	foo(p);
}
