#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}

	// 복사 생성자
	Object(const Object&) {	std::cout << "copy" << std::endl;	}
	
	// 이동 생성자 
	// 이동 생성자 구현시
	// 1. 되도록 예외가 없도록 만드세요(대부분 예외 없이 구현가능, 포인터복사만하므로)
	// 2. 그리고, 예외가 없음을 컴파일러에게 알려 주세요(noexcept)
	Object(Object&&) noexcept
	{
		std::cout << "move" << std::endl;
	}
};

int main()
{
	Object o1;
	Object o2 = o1; // 항상 복사 생성자 사용
	Object o3 = std::move(o1); // 항상 이동 생성자 사용
	Object o4 = std::move_if_noexcept(o2); // 이동 생성자가 예외가 없으면 사용
										   // 예외가능성이 있으면 복사 생성자 사용
										   // vector 가 내부적으로 버퍼 복사시
											// std::move() 가 아니라
											// std::move_if_noexcept() 사용



	std::vector<Object> v(5);

	std::cout << "----------------" << std::endl;

	v.resize(10); // 이순간의 원리를 생각해봅시다.

	std::cout << "----------------" << std::endl;
}

