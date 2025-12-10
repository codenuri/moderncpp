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
	// => 
	Point(Point pt) {}

};

int main()
{
	Point p1;			// 1번 생성자
	Point p2(1, 2);		// 2번 생성자
	Point p3(p2);		// 컴파일러가 만드는 복사 생성자 사용				
}




