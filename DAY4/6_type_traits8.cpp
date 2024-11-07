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
T&& xmove(T& obj)
{
	return static_cast<T&&>(obj);
}


int main()
{
	Object o1;

	Object o2 = std::move(o1);	// move


	Object o3 = xmove(o2);		// move

	Object o4 = xmove( Object{} ); // 안되야 할까요 ?
								   // 되야 할까요 ?
}
