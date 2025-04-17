#include <functional>
class Dialog
{
public:
	void close1(int a) {}
	static void close2(int a) {}
};
void foo(int a) {}

int main()
{
	// 다음중 에러를 찾으세요
	void(*f1)(int) = &foo;				// ok
//	void(*f2)(int) = &Dialog::close1;	// ERROR. 멤버 함수는 this 가 추가된다
	void(*f3)(int) = &Dialog::close2;	// ok.    static 은 this 추가 안됨

	// #1. 일반 함수 포인터에 멤버 함수의 주소를 담을수 없습니다.
	// #2. 일반 함수 포인터에 static 멤버 함수의 주소를 담을수 있습니다.

	// #3. 멤버 함수 주소는 아래처럼 담아야 합니다.
	// => 멤버 함수 포인터 라고 합니다.
	void(Dialog::*f2)(int) = &Dialog::close1;

	
	// #4. 멤버 함수 포인터 사용법(호출하는 방법)
	f2(10); // error. 객체가 없습니다.

	Dialog dlg;
//	dlg.f2(10); // error. Dialog 안에는 f2라는 멤버가 없습니다.

	// 이럴때 사용하는 연산자가 "pointer to member(.*)" 라는 연산자입니다

	dlg.*f2(10); // error. 연산자 우선순위 문제

	(dlg.*f2)(10); // ok.. 이 코드가 멤버 함수 포인터로 
					// 실제 멤버 함수를 호출하는 코드

	// #5. 사용법을 동일하게 할수 없을까 ?
	f1(10);			// 일반 함수 포인터
	(dlg.*f2)(10);	// 멤버 함수 포인터

	f2(&dlg, 10); // 이렇게 호출할수 있다면 어떨까 ?
					// "uniform call syntax" 라고 "창시자가 제안했으나
					//채택 안됨

	// 대신 아래 도구를 만들었음- C++17
	// <functional> 헤더
	std::invoke(f1, 10);			// f1(10)
	std::invoke(f2, &dlg, 10);		// (dlg.*f2)(10)

}