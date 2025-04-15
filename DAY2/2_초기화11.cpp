// 1_초기화11 - 65 page..
// aggregate initialization
// => 생성자가 없어도 {}로 초기화 가능한 것들을 "aggregate" 타입이라고
//    합니다.
// => 배열, C 언어 구조체등이 있습니다.

// POD : Plain Old Data, C와 같은 타입이라는 의미.
//
struct Point
{
	int x, y;

//	Point()             : x(0), y(0) {}	// 1
//	Point(int a, int b) : x(a), y(b) {}	// 2

//	Point() {}		// 사용자가 디폴트 생성자 제공
					// 이제 Point 는 POD 아님. = {} 초기화 안됨
					// aggregate type 아님.
		
//	Point() = default;	// 이 생성자가 있을때
						// C++17 : aggregate 타입
						// C++20 : aggregate 타입 아님.

//	void foo() {} // 멤버 함수가 있어도 "aggregate"
	
	virtual void goo() {} // 가상함수.
						  // aggregate 아님
};

int main()
{
	Point p1;	
	Point p2 = { 1, 2 };

	// 핵심. 아래 코드를 2가지로 생각하세요
	Point p3 = { 1, 2 }; // 1. C언어의 전통적인 구조체 초기화 기술
						 // 2. 인자가 2개또는 std::initializer_list
						//     생성자 호출하는 코드
}