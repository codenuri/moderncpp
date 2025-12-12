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
T&& mymove(T&& obj)
{
	return static_cast<T&&>(obj);
}

int main()
{
	Object o1;

	Object o2 = std::move(o1);
				// static_cast<Object&&>(o1)
	Object o3 = std::move(Object{});

	Object o4 = mymove(o2);	
	Object o5 = mymove(Object{});
}