struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
};
// 방법 #1. call by value
// => 복사본 생성
// void foo(Point pt) {}

// 방법 #2. call by const lvalue reference
// => 복사본 생성 안됨
// => 하지만 상수성 추가, 
// => "원본 그대로 받은것 아님"
//void foo(const Point& pt) {}

// C++98 : 위 2가지 방법외에는 없다. 즉, 원본 그래도 받는 기술 없음. 
// C++11 : 아래 2개 방법 추가

// 방법 #3. call by non-const reference, 를 2개
void foo(Point&  p) {}
void foo(Point&& p) {}

// 방법 #4. T&& 를 사용하면 "방법 #3" 을 자동생성할수 있다.
// => "방법 #3" 의 2개 함수 구현이 동일하면 한개의 템플릿으로 자동생성
// => 또한 Point 뿐 아니라, 모든 타입의 lvalue, rvalue 를 어떠한 변화없이 
//    그대로 받을수 있다.
template<typename T>
void foo(T&& p)
{

}


int main()
{
	Point pt{ 0, 0 };

	// foo 함수에 lvalue 와 rvalue를 모두 보내고 싶다.
	foo(pt);
	foo(Point{ 0,0 });
}
