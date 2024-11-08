#include <iostream>
#include <functional>

void goo(int a, double d) {}

class Object
{
public:
	void foo(int a, double d) {}
};



template<typename F, typename ... Ts>
decltype(auto) chronometry(F f, Ts&& ... args)
{
//	return f(std::forward<Ts>(args)...); // 일반함수만 가능

	return std::invoke(f, std::forward<Ts>(args)...); // 멤버함수도 가능
}

int main()
{
	chronometry(goo, 1, 3.4); // goo(1, 3.4)

	Object obj;
	chronometry(&Object::foo, &obj, 1, 3.4); // obj.foo(1, 3.4)
}

// 일반 함수는 "함수이름" => "함수 주소" 로 암시적 형변환 가능하지만
// 멤버 함수는 반드시 & 연산자 필요