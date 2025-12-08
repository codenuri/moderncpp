// 12_delete_function 37 page

class Point
{
	int x, y;
public:
	Point() {}				// 1 번 생성자
	Point(int a, int b) {}	// 2 번 생성자

	// C++ 클래스는 사용자가 만들지 않으면 컴파일러가 자동으로 만들어주는
	// 멤버 함수가 있습니다.
	// => 디폴트 생성자, 소멸자, 복사 생성자, 대입자 연산자....
	// => 만들기 못하게 하려면 C++11 delete function 문법
	
	Point(const Point&) = delete; // 복사 생성자 만들지 말라는 의미
};
int main()
{
	Point p1;		// ok. 1번 생성자 호출
	Point p2(1, 2);	// ok. 2번 생성자 호출
	Point p3(p2);	// 컴파일러가 제공하는 복사 생성자 호출
}