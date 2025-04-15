// 3_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};
// 임시객체와 함수 반환값 -  82 page

void f1(Point  pt) {}	// call by value     : 복사본 객체 생성
void f2(Point& pt) {}	// call by reference : 복사본 생성 안됨

/*
int main()
{
	Point p{ 0, 0 };
	f1(p);
	f2(p);
}
*/
//-----------------------------------------



Point pt{ 1, 2 };

Point foo()	// return by value : 리턴용 복사본 생성해서 반환
{				
	return pt;	// pt 가 아닌 pt를 복사한 임시객체를 만들고
				// 임시객체가 반환된것
				// return Point{pt};
				// 리턴용 임시객체는 함수 호출 문장의 끝에서 파괴
}

Point& goo()	// return by reference
{				// => 리턴용 임시객체를 만들지 말라는 의미. 
	return pt;
}

int main()
{
	foo().x = 10;	// error. "임시객체.x = 10" 인데, 임시객체는  lvalue 가
					//         될수 없다.

	goo().x = 10;	// ok.  "pt별명.x = 10"
}



