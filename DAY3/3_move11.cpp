// 105 page.. 상수 객체와 move
#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}
	Object(const Object&) { std::cout << "copy" << std::endl; }
	Object(Object&&) noexcept  {std::cout << "move" << std::endl;	}
};
int main()
{
	Object o1;
	Object o2 = std::move(o1);	
}



