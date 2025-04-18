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
T&& mymove(T&& obj)
{
	return static_cast<T&&>(obj);
}


int main()
{
	Object o1;
	Object o2 = std::move(o1); // 이동
	Object o3 = mymove(o2); 
	Object o4 = mymove(Object{}); // 필요없지만
								  // 되야 합니다.
}
