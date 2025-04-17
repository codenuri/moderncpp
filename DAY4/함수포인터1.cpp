// 함수 포인터1.cpp

class Point
{
	int x, y;
public:
	// 핵심 #1. 멤버 함수는 인자로 "this" 가 추가됩니다. - "this call"
	void set(int a, int b)	// void set(Point* this, int a, int b)
	{						// {
		x = a;				//		this->x = a;		
		y = b;				//		this->y = b;
	}						// }

	// 핵심 #1. static 멤버 함수는 인자로 "this" 가 추가 안됩니다.
	static void foo(int n)	// void foo(int n)
	{						// {
		x = a;				//		this->x = a; 로 변경해야 하는데
							//				this가 없기때문에 에러
							//		그래서 static 멤버 함수는
							//		멤버 데이타 접근 안됩니다.
	}
};
int main()
{
	Point::foo(3); // 객체 없이 호출
					// call foo(3)

	Point p1;
	Point p2;

	p1.set(10, 20); // 이 한줄의 원리를 생각해 봅시다.
					// set(&p1, 10, 20) 으로 변경합니다.
}