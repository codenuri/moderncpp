// QA1.cpp
class Point
{
	int x, y;
public:
	Point(int a, int b) { }
	~Point() {  }
	Point(const Point&) {}
};
int main()
{
	// 아래 한줄을 완벽히 이해해 봅시다.
	Point pt = Point{ 1,2 };

	// C++98


	// C++11

	// C++17
}