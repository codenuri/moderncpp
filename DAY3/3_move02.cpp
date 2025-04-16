// move 를 이해 하려면 "복사 생성자" 부터 정확히 알아야 합니다.
// 
// 복사생성자 모양을 생각해 봅시다.
class Point
{
	int x, y;
public:
	Point() {}				// 1
	Point(int a, int b) {}	// 2

	// 복사 생성자를 직접 만들어 봅시다.

	// #1. 인자를 call by value
	// => 이 표기법은 "복사생성자가 무한히 호출" 되는 표기법
	// => 복사 생성자 인자는 "값 타입"이 될수 없습니다
//	Point(Point other) {}

	// #2. 인자는 non-const lvalue reference
	// => 컴파일 에러는 아님.
	// => 임시객체(rvalue) 를 받을수 없다.
	// => Point ret = foo() 코드가 컴파일 에러!
//	Point(Point& other) {}

	// #3. const lvalue reference
	// => lvalue 와 rvalue 를 모두 받을수 있다.
	// => 이런 이유 때문에 복사 생성자의 인자를 "const lvalue reference"로
	//    만드는 것입니다.
	Point(const Point& other) : x(other.x), y(other.y) {}

};

Point foo() { return Point{ 1,1 }; }

int main()
{
	Point p1;		// 1 번 생성자
	Point p2(1, 2);	// 2 번 생성자 

	Point p3(p2);	// 컴파일러가 만드는 복사 생성자 사용	
					// Point other = p2

	Point ret = foo(); // Point ret(foo());
}




