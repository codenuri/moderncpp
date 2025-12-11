// QA1.cpp
#include <iostream>


class Point
{
	int x, y;
public:
	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }

//private:
	Point(const Point&) { std::cout << "copy ctor" << std::endl; }
};
int main()
{
	// 아래 한줄을 완벽히 이해해 봅시다.
//	Point pt = Point{ 1,2 };
//	Point pt = Point( 1,2 );

	// 결국 위코드는 최적화 되어서 아래와 동일
	Point pt{ 1,2 }; // 성능저하 없음.

	Point&& r = Point{ 1,2 };
	// r은 객체를 가리키는 참조(내부는 포인터)
	// r사용시 주소를 따라가서 접근



	// C++98
	// 1. 우변의 표현식 때문에 임시객체가 생성됨. - 인자 2개 생성자 호출
	// 2. 임시객체를 복사 해서 pt 생성 - 복사 생성자 호출
	// => 만일 복사 생성자가 private 있었다면 컴파일 에러!
	// => 그런데, 대부분의 컴파일러는 "임시객체를 제거"하는 최적화 수행
	//    따라서 인자 2개 생성자 만 호출됨.(copy ellision 이라는 최적화)
	// => 단, "복사 생성자가 있어야 한다." 없으면 에러. 

	// C++11
	// 1. 우변의 표현식 때문에 임시객체가 생성됨. - 인자 2개 생성자 호출
	// 2. 임시객체를 이동 해서 pt 생성 - 이동 생성자 호출
	// 
	// => 만일 이동 생성자가 private 있었다면 컴파일 에러!
	// => 그런데, 대부분의 컴파일러는 "임시객체를 제거"하는 최적화 수행
	//    따라서 인자 2개 생성자 만 호출됨.(copy ellision 이라는 최적화)
	// => 단, "이동또는 복사 생성자가 있어야 한다." 
	// => 문법에 오류가 없어야 최적화
	// 
	// C++17
	// => copy ellision 이 최적화가 아닌 문법이 되었다.
	// => "mandantory copy ellision"
	// => 무조건 인자2개 생성자만 호출
	// => 복사 생성자 또는 이동 생성자가 private 에 있어도 에러 아님.
}
// 아래 처럼 확인 가능. 
// 또한 최적화를 막으려면 -fno-elide-constructors
// g++ 소스.cpp  -std=c++98
// g++ 소스.cpp  -std=c++11
// g++ 소스.cpp  -std=c++17