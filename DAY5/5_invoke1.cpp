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


	// #4. 멤버함수 포인터로 함수 호출하기
//	f(0); // error. 객체가 없다. ( obj.함수이름(0) 처럼 호출되야 한다)

//	Object obj;
//	obj.f(10);	// error. obj 안에 "f" 라는 함수가 없다.


	// 핵심 : pointer to member 라는 연산자 필요
	//		 .*   ->*

//	obj.*f(10); // error. 연산자 우선순위 문제
				// .* 보다 ( 연산자가 우선순위가 높다

	(obj.*f)(10); // 이코드가 멤버 함수 포인터로 멤버함수를 호출하는 코드
}
