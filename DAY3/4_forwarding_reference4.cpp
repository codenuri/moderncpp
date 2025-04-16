struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	Point pt(0, 0);

	// foo 함수에 lvalue 와 rvalue를 모두 보내고 싶다.
	foo(pt);
	foo(Point(0,0));
}

// 방법 #1. call by value
// 특징 : 복사본 생성된다.
void foo(Point pt) {}

// 방법 #2. call by const lvalue reference
// 특징 1 : 복사본은 없다.
// 특징 2 : const 속성이 추가된다. 원본은 그대로 받은 것은 아니다.
void foo(const Point& pt) {}

// C++98 기술은 위 2개만 가능
// C++11 부터 아래 기술도 가능

// 방법 #3. 2개의 foo 함수 제공
// 특징 : 복사본도 없고, 상수성도 추가되지 않는다.
// 단점 : 2개의 함수가 하는일이 동일하다면 중복된 코드
void foo(Point&  pt) {}
void foo(Point&& pt) {}

// 방법 #4. forwarding reference(T&&) 를 사용하면
// => "방법#3" 의 2개 함수를 자동생성한다.
// => Point 타입뿐 아니라 모든 타입에 대해서도 자동 생성
template<typename T> void foo(T&& a)
{
}

foo(pt);			// => void foo(Point&  pt) 생성
foo(Point{1,2});	// => void foo(Point&&  pt) 생성

// T&& 의 의미
// => lvalue, rvalue 를 모두 복사본 없이 인자로 받을수 있는 템플릿이 
//    필요 했습니다.
// => 그래서 T&& 만의 추론 규칙을 도입해서 만든것
// foo(n) 에서 int n 이지만, T = int 가 아닌 T = int& 로 추론하기로 약속