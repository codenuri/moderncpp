#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}

	Object(const Object&) { std::cout << "copy" << std::endl; }

	Object(Object&&) noexcept { std::cout << "move" << std::endl;}
};

// std::move 를 만들어 봅시다.
/*
template<typename T>
T&& mymove(T& obj)
{
	return static_cast<T&&>(obj);
}
*/

// 함수 템플릿 만들때(분석할때) 아래 2개 잘 구별하세요
// T&  : lvalue 만 받겠다는것
// T&& : lvalue, rvalue 를 모두 받겠다는 것

// std::move : lvalue 와 rvalue 를 모두 받아서 rvalue 캐스팅

template<typename T>
constexpr std::remove_reference_t<T>&& mymove(T&& obj) noexcept
{
	// T&& 인 함수에
	// lvalue 를 전달하면 T = Object&
	// rvalue 를 전달하면 T = Object

	// 따라서 mymove(o2) 하면 T = Object& 이므로 
	// 아래 캐스팅은 
	// static_cast<Object& &&>(obj) 입니다
	// static_cast<Object&>(obj)  <= 결국 이렇게 됩니다.
//	return static_cast<T&&>(obj); // 결국 lvalue 를 전달시 
									// lvalue 로 캐스팅한것!

	// 해결책  : T 가 가진 모든 레퍼런스를 제거하고 && 붙이면 됩니다.
	return static_cast<std::remove_reference_t<T> &&>(obj);
}


int main()
{
	Object o1;
	Object o2 = std::move(o1); // 이동
	Object o3 = mymove(o2); 
	Object o4 = mymove(Object{}); // 필요없지만
								  // 되야 합니다.
}
