// 1_초기화11 - 65 page..
// aggregate initialization


// aggregate type 
// => 생성자가 없어도 {} 로 초기화 가능한 타입
// => 구조체, 배열, 공용체등.. 
struct Point
{
	int x, y;

//	Point()             : x(0), y(0) {}	// 1
//	Point(int a, int b) : x(a), y(b) {}	// 2

//	Point() {}			// <== 이 코드가 있으면 aggregate 아님
//	Point() = default;	// <== 이 코드가 있어도 aggregate.

//	virtual void foo() {}// <== 이 코드가 있으면 aggregate 아님

	void foo() {}	// <== 이 코드가 있어도 aggregate.
};

int main()
{
	Point p1;	
	Point p2 = { 1, 2 };
}
