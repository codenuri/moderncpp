// 13_default_function - 41 page
#include <type_traits>
#include <iostream>

class Point
{
	int x, y;
public:
//	Point() {}  // 사용자가 만드는 디폴트 생성자
				// 그런데, 아무 일도 하지 않은 디폴트 생성자가 필요하면
				// 이렇게 하는 것은 좋지 않은 코드

	Point() = default; // 좋은 코드
						// 컴파일러에게 디폴트 생성자를 만들어 달라고 요청

	Point(int a, int b) {} // 
};

int main()
{
	Point p1;
	Point p2(1, 2); // 인자가 2개인 생성자 호출
}

// 왜 = default 를 사용하나요 ?

// 1. 컴파일러는 복사 생성자를 만들지 않으면 복사 생성자 제공..
// 단, 사용자가 이동생성자를 만들면(내일) 복사 생성자 제공안함. 
// => 이경우 = default 로 요청하면 된다.(내일 나오고, 아주 중요!! 핵심!!)

// 2. = default 요청시 컴파일러는 구현을 완벽히 알고 있다.
// => 최선의 최적화 코드를 만들어 낸다.
// => 위 코드 처럼 아무 일도 하지 않은 디폴트 생성자가 필요하면
//    = default 로 요청하는 것이 최선


