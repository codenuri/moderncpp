#include <iostream>

class Object
{
public:
	Object() = default;
	Object(const Object& obj) { std::cout << "copy\n"; }
	Object(Object&& obj)      { std::cout << "move\n"; }
};

template<typename T>
T&& mymove(T& obj)
{
	return static_cast<T&&>(obj);
}

int main()
{
	Object o1;

	Object o2 = std::move(o1);
				// static_cast<Object&&>(o1)

	Object o3 = mymove(o2);	// 만들어 봅시다.
}