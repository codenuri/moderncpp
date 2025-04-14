// 13_default_function - 41 page
#include <type_traits>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) {}

	// 아무 일도 하지 않은 디폴트 생성자가 필요하면

	// #1. 개발자가 직접 구현하는 방법
//	Point() {}

	// #2. 컴파일러에게 디폴트 생성자를 만들어 달라고 요청
	// => C++11 부터 제공 되는 아주 널리 사용되는 문법

	// 장점 #1. 보다 최적화된 기계어 생성(godbolt.org 참고)
	// 장점 #2. 디폴트 생성자가 아닌 복사, 이동 생성자는
	//			아무일도 하지 않은 것이 아니라, 중요한 일을 수행한다.
	//			= default 로 요청하면컴파일러가 완벽히 만들어준다.
	//			사용자가 직접 만들면 정확한 원리를 알아야 한다.
	//			내일 move 시간에 자세히
	Point() = default;
};

int main()
{
	Point p1;
	Point p2(1, 2);
}

// 1. "godbolt.org" 접속하세요
// 2. C++ 선택하세요
// 3. 위소스 복사해서 "godbolt.org" 왼쪽에 넣으세요



