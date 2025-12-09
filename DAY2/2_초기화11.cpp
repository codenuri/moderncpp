//  65 page..
// aggregate initialization
// aggregate type
// => 생성자가 없어도 {}로 초기화 할수 있는 것들
// => 배열, 구조체등..
struct Point
{
	int x, y;
//	Point()				: x{ 0 }, y{ 0 } {}	// 1
//	Point(int a, int b) : x{ a }, y{ b } {}	// 2

	void print() {} // 멤버 함수가 있다면, aggregate 일까 ? 아닐까 ?
					// Point 는 aggregate 타입

//	Point() {}			// 이 코드가 있으면 aggregate 아님
//	Point() = default; // 이 코드가 있어도 aggregate 타입

	virtual void foo() {} // 이 코드가 있으면 aggregate 아님
				
	// 결국 "순수한 구조체인가 ? C++ 클래스 특징인가 ?" 
};

int main()
{
	Point p1;	
	Point p2 = { 1, 2 };
		// Point 가 
		// C 스타일 구조체(POD, Plain Old Data) 라면 = {} 초기화는 당연한 코드
		// 가상함수등을 가진다면 순수한 구조체 아님. ={} 사용하려면 생성자 필요
}
