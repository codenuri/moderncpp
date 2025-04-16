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
	Point(Point other) {}

};

int main()
{
	Point p1;		// 1 번 생성자
	Point p2(1, 2);	// 2 번 생성자 

	Point p3(p2);	// 컴파일러가 만드는 복사 생성자 사용				
}




