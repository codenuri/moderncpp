// 1_임시객체1 - 77 page
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
//	Point pt(1, 2); // "이름이 있는 객체(named object)"
					// 이름이 있으므로 여러문장에서 접근 가능
					// 수명 : 자신을 선언한 {} 을 벗어날때 파괴

//	Point(1, 2);	// "이름이 없는 객체(unnamed object)"
					// 이름이 없으므로 다른 문장에서 접근 안됨
					// 수명 : 자신을 선언한 문장의 끝(;)

	Point(1, 2), std::cout << "X\n";

	std::cout << "-------" << std::endl;
}





