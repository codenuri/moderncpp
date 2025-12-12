#include <iostream>

class Object
{
public:
	Object() = default;
	Object(const Object& obj) { std::cout << "copy\n"; }
	Object(Object&& obj)      { std::cout << "move\n"; }
};

// 핵심
// T&  : lvalue 만 받을수 있다.
// T&& : lvalue, rvalue 를 모두 받을수 있다.

// std::move : lvalue, rvalue 를 모두 받아서, rvalue 캐스팅

template<typename T>
std::remove_reference_t<T>&& mymove(T&& obj)
{
	// 아래 캐스팅은
	// 인자로 rvalue 보낼때 : static_cast<Object&&>
	// 인자로 lvalue 보낼때 : static_cast<Object&>
	// return static_cast<T&&>(obj);

	// 문제 원인 : T 가 & 를 가지고 있을수도 있다는 것!!!!
	// 해결책    : "T가 가진레퍼런스를 제거한타입"&& 으로 캐스팅
	return static_cast<std::remove_reference_t<T>&&>(obj);
}

int main()
{
	Object o1;
	Object o2 = std::move(o1);
				// static_cast<Object&&>(o1)
	Object o3 = std::move(Object{});

	Object o4 = mymove(o2);	// T = Object&,  T&& = Object&
	Object o5 = mymove(Object{});
}

// type trait 기술

// 질의(is_xxx) : 아주 널리 사용되고, 일반 개발자도 알아야 합니다.
// 변형 타입얻기 : 일반개발자 보다는 라이브러리 설계자들이 많이 사용 - std::move 만들기등