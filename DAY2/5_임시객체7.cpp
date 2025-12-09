#include <iostream>
// 85 page
struct Base
{
	int value{ 10 };
};
struct Derived : public Base
{
	// 기반 클래스와 동일한 이름의 멤버 추가해도 됩니다.
	int value{ 20 };
};
int main()
{
	Derived d;
	std::cout << d.value << std::endl; 	// 20. Derived 멤버가 우선 

	// Base 멤버에 접근하려면 캐스팅
	std::cout << static_cast<Base>(d).value << std::endl; 	// 10
	std::cout << static_cast<Base&>(d).value << std::endl; 	// 10

	// static_cast<Base>(d).value : d 를 복사해서 Base temporary 생성한것
	// 								temporary.value 접근

	// static_cast<Base&>(d).value : d 를 Base 처럼 생각해서 value 접근해 달라.
	//								temporary 생성 안됨

	static_cast<Base>(d).value = 30; // error
	static_cast<Base&>(d).value = 30; // ok

	// 내일 배우는 내용
//	Base b1 = static_cast<Base>(d).value; // move
//	Base b2 = static_cast<Base&>(d).value; // copy
}

// temporary
// 1. 사용자가 의도적으로 만들기도 하고 
// => 주로 함수 인자로 전달할때
// => draw_line( Point{0, 0}, Point{5,5});

// 2. 특정 코드 때문에 생성되기도 합니다.
// => 값을 반환하는 함수
// => 값으로 캐스팅

// 언제 temporary 가 생성되는지 이해해야 하고( Counter 예제 )
// => 버그가 나지 않게 적절히 & 리턴 활용해야 합니다.

// 참조 반환 하는 경우
// => 파괴되지 않는 것만 가능합니다.
// => return *this
// => return 멤버변수
// => return 참조 인자로 받은것을 다시 반환
// => "return 지역변수" => 는 절대 안됨

class Sample
{
public:
	int data = 0;
	
	int& get() 
	{
		return data; // ok
	}
}







