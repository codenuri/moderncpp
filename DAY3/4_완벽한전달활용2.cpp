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
void* operator new (std::size_t sz)
{
	printf("operator new %zd\n", sz);

	return malloc(sz);
}

int main()
{
	// 스마트 포인터
	// # 1. 직접 객체 생성
	// 아래 코드는 동적 메모리를 몇번 할당 할까요 ?
	// 1. new Point() 에서 한번
	// 2. shared_ptr 생성자에서 "control block" 만들때 한번
	std::shared_ptr<Point> sp1(new Point(1,2));
}







