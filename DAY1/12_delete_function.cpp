// 12_delete_function 37 page

class Point
{
	int x, y;
public:
	Point() {}
	Point(int a, int b) {}

	// 아래 6개 함수를 "special member function" 이라고 합니다.
	// => 사용자가 만들지 않으면 컴파일러가 제공합니다.
	// 
	// => 디폴트 생성자, 소멸자, 복사 생성자, 이동생성자
	//    복사 대입 연산자, 이동 대입 연산자

	// 컴파일러에게 만들지 못하게 하려면 "삭제" 하면됩니다.
	Point(const Point&) = delete; // C++11 함수 삭제 문법

};
int main()
{
	Point p1;
	Point p2(1, 2);
	Point p3(p2); // 컴파일러가 만들어주는 복사생성자사용
					// 복사 생성자가 삭제 되었다면 error
			// 주로 singleton 같은 디자인 패턴만들때사용
			// 내일 move 시간에 좀더 자세히
}