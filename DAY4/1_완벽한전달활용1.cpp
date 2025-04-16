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
	
	// 방법 #1. Point 객체를 생성한후 넣기
//	Point pt(1, 2);
//	v.push_back(pt);


	// 방법 #2. 임시객체 형태로 전달
//	v.push_back(Point{ 1, 2 });
//	v.push_back({ 1, 2 }); //  위와 동일


	// 방법	#3. 이 예제의 핵심!!!!!
	// => 객체를 전달하지 말고,
	//    객체를 만들기 위한 생성자 인자를 전달하자

	v.emplace_back(1, 2);
		// => 이 함수가 내부적으로 자신의 버퍼에
		// => new Point(1,2) 로 객체를 생성.

		// 1, 2 ===> emplace_back(a, b) 
		//			 a, b 를 다시 Point 생성자에 전달 ===> Point(x, y)

		// 즉, emplace_back 은 자신이 받은 인자를
		// Point 생성자로 전달합니다
		// => 완벽한 전달 기술이 필요 합니다.

	std::cout << "-----" << std::endl;
}
// STL container 사용시

// 1. primitive 타입을 저장하는 컨테이너 
// => std::vector<int> v;
// => push_xxx() 또는 emplace_xxx() 모두 좋습니다.
// => 그냥, 가독성을 위해 push_xxx() 하세요



// 2. 사용자 정의 타입을 값으로 저장하는 컨테이너
// => std::vector<Point> v;
// => push_xxx() 보다는 emplace_xxx() 가 좋습니다.

// push_back()	==> emplace_back();
// push_front()	==> emplace_front();
// insert()	    ==> emplace();


// 3. 사용자 정의 타입의 포인터를 보관하는 컨테이너
// => 그냥 push_xxx 하면 됩니다.

// 4. 컨테이너는 레퍼런스를 저장할수 없습니다.
// std::vector<Point&> v; // error..  
