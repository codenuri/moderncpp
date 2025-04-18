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
	
	// 기반 클래스로 부터 물려 받은 value 접근하려면
	// => "기반 클래스 참조" 타입으로 캐스팅
	cout << (static_cast<Base&>(d)).value << endl; 
		
	(static_cast<Base&>(d)).value = 30;	

}