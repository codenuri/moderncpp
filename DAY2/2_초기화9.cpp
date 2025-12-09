// 63 page
#include <iostream>
#include <vector>

// std::initializer_list<int>  와 생성자
// => std::initializer_list<int> 를 만든 주된 이유는 "생성자"에서 사용하려고!

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
	// 아래 코드가 어떤 생성자를 사용할지 생각해 보세요
	Point p1(1);		// Point(int)
	Point p2(1, 2);		// Point(int, int)
	Point p3({ 1,2 });	// Point(std::initializer_list<int>)

	Point p4{ 1,2 };	// 핵심
						// 1. Point(std::initializer_list<int>) 있다면 호출
						// 2. (1)이 없다면 Point(int, int)

	Point p5(1, 2, 3);  // error. Point(int, int, int) 생성자는 없다

	Point p6{ 1, 2, 3 }; // ok. Point(std::initializer_list<int>) 사용

	Point p7 = { 1,2,3 }; // ok. 
						// Point(std::initializer_list<int>)는 explicit 아님

	// 핵심 
	// => 생성자 인자로 std::initializer_list 를 사용하면
	// => {} 초기화시에 "인자의 갯수를 가변"으로 사용할수 있습니다.

	// C++11 만들때 STL 을 아래 처럼 사용하게 하고 싶었습니다.
	// => 이때, 근간이 되는 어떤 문법이 필요 했습니다.
	// => 해결책이 std::initializer_list 라는 존재이고
	// => 생성자에서만 특별하게 동작(위 p4 규칙) 하는 문법을 만든것
	std::vector<int> v1 = { 1,2,3,4,5 };
	std::vector<int> v2{ 1,2,3,4,5 };
}


