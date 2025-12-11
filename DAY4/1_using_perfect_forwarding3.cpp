#include <thread>
#include <memory>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "copy ctor" << std::endl; }
};

void* operator new(std::size_t sz)
{
	printf("%zd byte 할당\n", sz);

	return malloc(sz);
}

int main()
{
	// 스마트 포인터
	// 1. 직접 객체 생성
	// 아래 코드는 동적 메모리를 몇번 할당 할까요 ? 2번
	// #1. 사용자 코드의 "new Point(1,2)" 에서 8 바이트 할당
	// #2. shared_ptr 의 생성자에서 "new control block" 할당 - 24 ~ 30 정도
	//std::shared_ptr<Point> sp1( new Point(1,2) );


	// #2. std::make_shared
	// => sizeof(Point) + sizeof(Controlbock) 를 한번에 할당
	// => 메모리 파편화를 막고, 메모리 크기도 줄어든다.
	//    (같이 할당하면 정보가 줄어 든다.)
	std::shared_ptr<Point> sp1 = std::make_shared<Point>(1, 2);
}







