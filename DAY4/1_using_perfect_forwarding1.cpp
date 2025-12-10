// 완벽한전달활용
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
	
	// 1. Point 객체를 생성해서 넣기
//	Point pt{ 1, 2 };
//	v.push_back(pt);

	// 2. 임시객체 형태로 넣기
	// => 1번과 차이점은 "임시객체" 이므로 push_back() 이후 즉시 파괴
	// => 소멸자 호출이 ---- 출력 보다 먼저
//	v.push_back(Point{ 1,1 });

	// 3. 객체를 만들어서 전달하지 말고
	//    객체를 만들기 위한 생성자 인자를 전달하자.

	v.emplace_back(1, 2);
	// => 이 함수 안에서 내부적으로 new Point{1,2} 해서
	//    자신의 버퍼에 보관
	// => 즉, 외부에서는 Point 객체를 만든적이 없다.
	// => emplace_back 은 어떻게 만들까요 ? 다음예제

	std::cout << "-----" << std::endl;
}

