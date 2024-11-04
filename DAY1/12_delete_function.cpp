// 12_delete_function 37 page

class Point
{
	int x = 0, y = 0;
public:
	Point() {}
	Point(int a, int b) {}

	// 복사 생성자는 사용자가 만들지 않으면 컴파일러가 제공합니다.
	// 컴파일러에게 만들지 말라고 하려면 "삭제" 해달라고 하면됩니다.
	Point(const Point&) = delete; // "함수 삭제 문법"
								// 싱글톤 패턴등에서 널리사용
};
int main()
{
	Point p1;
	Point p2(1, 2);
	Point p3(p2); // 컴파일러가 만들어주는 복사생성자사용
				  // 복사 생성자가 삭제되었으므로 error. 
}
