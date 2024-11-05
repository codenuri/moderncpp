// 1_초기화9. - 63 page
#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point(int)      { std::cout << "int" << std::endl;	}
	Point(int, int) { std::cout << "int, int" << std::endl; }
	Point(std::initializer_list<int> e) { std::cout << "initializer_list<int>" << std::endl; }
};
int main()
{
	Point p1(1);		// Point(int) 호출

	Point p2(1, 2);		// Point(int, int)

	Point p3({ 1,2 });	// Point(std::initializer_list<int> e)

	Point p4{ 1,2 };	// 핵심 
						// 1. Point(std::initializer_list<int> e) 사용, 
						// 2. 1이 없는 경우 Point(int, int) 사용

	Point p5(1, 2, 3); // error. Point(int, int, int) 생성자는 없다.

	Point p6{ 1, 2, 3 }; // ok. Point(std::initializer_list<int> e)

	Point p7 = { 1,2,3 };// ok

	// 핵심 : 생성자 인자로 std::initializer_list<int> 를 받는것이 있다면
	//	      객체의 초기화를 "배열" 형태로 할수 있다.
	//	      std::vector, std::list 초기화를 위해 만든 것!!
	std::vector<int> v1 = { 1,2,3,4,5 };
	std::vector<int> v2 { 1,2,3,4,5 };
}


