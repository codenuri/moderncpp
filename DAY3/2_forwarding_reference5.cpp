struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
};
// 방법 #1. call by value
// => 복사본 생성
// void foo(Point p) {}

// 방법 #2. call by const lvalue reference
// => 복사본 없음.
// => 상수성 추가됨. 수정할수없고, std::move 도 사용못함.
void foo(const Point& p) {}

// lvalue, rvalue 모두 복사본없고, 상수성 추가 되지 않게.. 그대로 받고 싶다.
// => C++98 안됨. 
// => C++11 부터 가능
// => 왜??? 상수성없이 받아야 하나요 ? "완벽한 전달을 위해서"
// 
// 방법 #3. 2개의 함수
void foo(Point& p) {}
void foo(Point&& p) {}

// 방법 #4. T&& 를 사용하면 "3번의 2개함수"를 자동생성가능합니다.
template<typename T>
void foo(T&& p)
{
}

int main()
{
	Point pt(0, 0);

	// foo 함수에 lvalue 와 rvalue를 모두 보내고 싶다.
	foo(pt);
	foo(Point(0,0));
}
