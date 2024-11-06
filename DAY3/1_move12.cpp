// 105 page.. 상수 객체와 move
#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}

	// 복사생성자 : lvalue, rvalue, const lvalue, const rvalue 를
	//				모두 받을수 있다.
	Object(const Object&) { std::cout << "copy" << std::endl; }
	Object(Object&&) noexcept  {std::cout << "move" << std::endl;	}
};
int main()
{
	const Object o1;
	Object o2 = std::move(o1);	
				// static_cast< o1의타입&& >(o1)
				// static_cast< const Object&& >(o1)
				// 이므로 "Object(const Object&)" 호출

	// #1. 상수객체는 move 될수 없습니다.
	// #2. std::move(상수객체) 는 복사 생성자 호출.
}



