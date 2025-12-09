// 임시객체 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl;	}
};
int main()
{
//	Point pt(1, 2); // 이름이 있는 객체(pt 가 이름), named object
					// 수명 : 자신을 선언한 {} 을 벗어 날때 파괴

//	Point (1, 2);	// unnamed object. 
					// 수명 : 자신을 선언한 문장의 끝(; 만날때 파괴)

	Point(1,2), std::cout << "X\n";

	std::cout << "-------" << std::endl;
}





