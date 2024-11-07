#include <iostream>
#include <type_traits>

struct Object
{
	Object() = default;
	Object(const Object&) { std::cout << "copy\n"; }
	Object(Object&&) noexcept { std::cout << "move\n"; }
};

// std::move 구현
/*
template<typename T>
T&& xmove(T& obj)
{
	return static_cast<T&&>(obj);
}
*/

// 템플릿에서 인자가 T&, T&& 를 잘 구분 하세요
// T&  : lvalue 만 받겠다는 것
// T&& : lvalue, rvalue 모두 받겠다는 것

template<typename T>
constexpr std::remove_reference_t<T>&& xmove(T&& obj) noexcept
{
	// T&& : forwaring reference
	// 인자로 lvalue(o2) 가 오면 T = Object&, T&& = Object& 
	// 따라서, 아래 캐스팅은 lvalue 캐스팅입니다.
	//return static_cast<T&&>(obj);
	
	// 위 캐스팅은
	// 인자로 rvalue 가 오면(lvalue로 변경되었던것을)다시 rvalue 로
	// 인자로 lvalue 가 오면(필요없지만 )           다시 lvalue 로
	// 즉, std::forward<T>(obj) 의 구현 입니다.


	// 그런데, move 는 "항상 rvalue 캐스팅"이 목표 입니다.

	return static_cast<std::remove_reference_t<T> &&>(obj);
	
}


int main()
{
	Object o1;

	Object o2 = std::move(o1);	// move


	Object o3 = xmove(o2);		// move

	Object o4 = xmove( Object{} ); // 안되야 할까요 ?
								   // 되야 할까요 ?
}
