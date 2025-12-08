#include <iostream>

// 6_위임생성자 - 24page
// => 하나의 생성자에서 다른 생성자를 호출하는 문법


class Point
{
public:
	int x, y;
public:
	Point() : Point(0, 0)  // 이 코드가 핵심. 하나의 생성자에서 다른 생성자를 호출하는 기술
	{						// C++11 delegate constructor 라는 문법

		// 여기서 다른 생성자를 호출할수 없을까 ?
		// => 여기서 다른 생성자 호출할수 없습니다.
	//	Point(0, 0); // 컴파일 에러는 아님
						// 이 코드는 "임시객체(temporary)" 를 만드는 코드(내일 배우는 주제)
	}
	Point(int a, int b) : x(a), y(b)
	{
		// 이 안에 복잡한 초기화 관련 코드가 있다. 
	}
};
int main()
{
	Point p;
	std::cout << p.x << std::endl;

}

// 생성자에서 다른 생성자 호출이 왜 어려운 주제인가 ?
// godbolt.org 에 아래 코드 만들어 보세요
#include <new>
class Data
{
public:
	Data() {}
};

class Sample
{
	Data data;
public:
	Sample() 
	{
	}
	Sample(int a) 
	{
	}
};
int main()
{
	Sample s1;
	Sample s2(0);

}