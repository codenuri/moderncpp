class Object
{
public:
	void foo(int code) {}		
};
void foo(int n) {}

int main()
{
	// #1. 일반 함수 포인터와 멤버 함수 포인터 만드는 법 알아 두세요
	void(*f1)(int) = &foo;	
	void(Object::*f2)(int) = &Object::foo;

	// #2. 일반 함수 포인터와 멤버 함수 포인터 사용하는 법 알아두세요
	f1(10);       // 일반 함수 포인터 사용
	(obj.*f2)(10);// 멤버 함수 포인터 사용
}

