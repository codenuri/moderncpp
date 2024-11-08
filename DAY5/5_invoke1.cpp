class Object
{
public:
	void f1(int code) {}		// void f1(Object* this, int code) {}
	static void f2(int code) {} // void f2(int code) {}
};
void foo(int n) {}

int main()
{
	// #1. 일반 함수포인터에 멤버함수의 주소를 담을수 없다.
	// #2. 일반 함수포인터에 static 멤버함수의 주소를 담을수 있다.
	void(*f1)(int) = &foo;			// ok
//	void(*f2)(int) = &Object::f1;	// error
	void(*f3)(int) = &Object::f2;	// ok

	// #3. 멤버 함수의 주소를 담는 "멤버함수포인터" 만들기
	void(Object::*f)(int) = &Object::f1;
}
