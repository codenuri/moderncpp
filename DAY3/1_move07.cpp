#include <iostream>
#include <vector>

// noexcept 이야기 - 103 page

class Object
{
public:
	Object() = default;

	Object(const Object&) 
	{	
		std::cout << "copy" << std::endl;	
	}
	
	// move 생성자를 만들때는
	// #1. 예외가 발생하지 않게 만드세요
	//     (대부분 포인터 복사과정 이므로 대부분 예외 없습니다.)
	// #2. 그리고 예외가 없음을 알리기 위해서 "noexcept" 붙이세요

	Object(Object&&) noexcept
	{
		std::cout << "move" << std::endl;
	}
};

int main()
{
	Object o1;
	Object o2 = o1;				// 항상 복사 생성자
	Object o3 = std::move(o1);	// 항상 move 생성자
	Object o4 = std::move_if_noexcept(o2);
						// move 생성자가 예외가 없다면 move생성자 사용
						// 예외 가능성이 있다면 복사 생성자 사용
						// (noexcept 가 붙어 있는가?)

	// std::vector 가 버퍼의 요소 복사시에
	// => "std::move_if_noexcept" 사용

	std::vector<Object> v(5);

	std::cout << "----------------" << std::endl;

	v.resize(10); // 이순간의 원리를 생각해봅시다.

	std::cout << "----------------" << std::endl;
}

