// 8_완벽한전달활용
#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "copy ctor" << std::endl; }
};
int main()
{
	std::vector<Point> v;
	
	// vector에 요소 넣기. 
	
	// 방법 #1. 객체를 만든후에 넣기
	// => 복습할때 꼭 실행해서 화면 출력 결과 확인하세요
//	Point pt(1, 2);
//	v.push_back(pt);


	// 방법 #2. 임시객체 형태로 넣기
//	v.push_back( Point(1, 2) );


	// 방법 #3. 객체를 만들어서 전달하지 말고
	// => 객체를 만들기 위한 생성자 인자를 전달하자.
	// => 즉, x, y 값을 전달해서 Point 객체는 vector 내부에서 직접만들ㄷ록

	v.emplace_back(1, 2);
			// 이 함수가 내부적으로 new Point(1, 2) 로 객체 생성


	std::cout << "-----" << std::endl;
}


