// thiscall 이야기

class Point
{
	int x, y;
public:
	void set(int a, int b) // void set(Point* this, int a, int b)
	{
		x = a;				//	this->x = a;
		y = b;				//	this->y = b;
	}

	static void foo(int a, int b) {}
};
int main()
{
	Point::foo(1, 2);

	Point p1, p2;
	p1.set(10, 20); // 이 한줄의 정확한 원리를 생각해 봅시다.
	p2.set(10, 20); // set(&p2, 10, 20)

	// 핵심 #1. 멤버 함수는 호출시 객체 주소가 같이 전달됩니다 - thiscall 
	// 핵심 #2. 멤버 함수 주소는 일반 함수 포인터에 담을수 없다. -this 가 전달될수없다
	// 핵심 #3. static 멤버 함수 주소는 일반 함수 포인터에 담을수 있다. - this 추가 안되는 함수
	void(*f)(int, int) = &Point::set; // error
	void(*f)(int, int) = &Point::foo; // ok. 
}