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
	Point p1(1);		// Point(int) 생성자 호출
	Point p2(1, 2);		// Point(int, int)
	Point p3({ 1,2 });	// Point(std::initializer_list<int> e)

	// 아래 코드가 핵심!!!
	Point p4{ 1,2 };	// 1. Point(std::initializer_list<int> e) 사용
						// 2. 1이 없다면 Point(int, int) 사용


	Point p5(1, 2, 3);  // error. Point(int, int, int) 는 없다

	Point p6{ 1, 2, 3 }; // ok. Point(std::initializer_list<int> e) 사용

	Point p7 = { 1,2,3 };// ok. explicit 생성자 아님..

	// 결론, 생성자 인자로 "std::initializer_list<int>"를 사용하면
	// => {} 초기화로 인자를 몇개라도 보낼수 있다.
	
	// 아래 코드를 지원하기 위해 추가된 문법
	std::vector<int> v1 = { 1,2,3,4,5 };
	std::vector<int> v2{ 1,2,3,4,5 };
}


