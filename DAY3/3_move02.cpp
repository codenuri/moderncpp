// move 사전 지식
// 복사생성자 모양을 생각해 봅시다.
class Point
{
	int x, y;
public:
	Point() {}				// 1
	Point(int a, int b) {}	// 2

	// 컴파일러가 만드는 복사 생성자를 생각해 봅시다
	// => 자신과 동일한 타입의 인자를 한개 받아야 합니다.

	// #1. call by value
	// => 복사 생성자가 무한히 호출되는 표현.
	// => 컴파일 에러
	// => 복사 생성자 만들때 인자로 call by value 를 사용할수 없다.
//	Point(Point pt) {}

	// #2. call by refrence
	// => 컴파일 가능.
	// => 그런데, rvalue 를 받을수 없다.
	// => Point pt = foo(); 가 안됨
	// Point(Point& pt) {}

	// #3. call by const refrence
	// => lvalue, rvalue 를 모두 받을수 있다.
	// => 그래서, 컴파일러가 만들어 주는 복사 생성자의 모양은
	//    아래와 같이 const lvalue reference 사용!!
	// => 아래 코드가 정확한 코드
	// => 아래 코드는 안만들어도, 컴파일러가 제공합니다.
	Point(const Point& pt) : x{ pt.x }, y{ pt.y } {}
};

Point foo()
{
	Point pt{ 1,2 };
	return pt;
}
int main()
{
	Point p1;			// 1번 생성자
	Point p2(1, 2);		// 2번 생성자
	Point p3(p2);		// 컴파일러가 만드는 복사 생성자 사용				
	Point p4 = foo();
}




