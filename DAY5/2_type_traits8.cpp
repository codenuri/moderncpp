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
template<typename T>
T&& mymove(T& obj)
{
	return static_cast<T&&>(obj);
}

int main()
{
	Object o1;
	Object o2 = std::move(o1); // 이동
	Object o3 = mymove(o2); 
}
