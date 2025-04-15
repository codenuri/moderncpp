#include <iostream>
// 85 page


struct Base
{
	int value{ 10 };
};
struct Derived : public Base
{
	int value{ 20 };
};
int main()
{
	Derived d;

	std::cout << d.value << std::endl;  // Derived 가 추가한 value 20

	// 기반 클래스(Base)에서 상속받은 value 접근하려면 캐스팅 필요
	std::cout << static_cast<Base>(d).value << std::endl; // 10
	std::cout << static_cast<Base&>(d).value << std::endl;

	// static_cast<Base>(d) : d를 복사해서 Base 타입의 임시객체만든것
	// static_cast<Base&>(d) : d를 Base 타입 처럼 생각해 달라는것


	static_cast<Base>(d).value = 30;	// error. 
										// 임시객체.value = 30
	static_cast<Base&>(d).value = 30;	// ok
										// d를Base처럼생각해서.value = 30
}
// 결국 임시객체는
// 1. 사용자가 의도적으로 만들기도 합니다.
//    draw_line( Point{0,0}, Point{1,1} )

// 2. 사용자가 작성한 코드 때문에 생성되기도 합니다
// => 값을 반환하는 함수  : Point foo() { return pt;}
// => 값타입으로 캐스팅   : static_cast<Base>(d)

// 언제 임시객체가 생성되는지 아는 것이 중요합니다.!!!

