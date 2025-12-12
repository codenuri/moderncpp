#include <iostream>
using namespace std;

struct Base
{
	int value = 10;
};
struct Derived : public Base
{
	int value = 20;
};
int main()
{
	Derived d;

	cout << d.value << endl; // 20

	// 이름이 동일한 멤버 데이타가 있을때
	// 기반 클래스 멤버 데이타에 접근하려면
	// => 기반 클래스 참조 타입으로 캐스팅하세요
	// => 값 캐스팅은 임시객체
	cout << (static_cast<Base>(d)).value << endl;  
	cout << (static_cast<Base&>(d)).value << endl; 
		
	(static_cast<Base>(d)).value = 30; // error
	(static_cast<Base&>(d)).value = 30;// ok	

}
