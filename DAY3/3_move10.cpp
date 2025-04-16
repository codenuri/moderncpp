#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}

	Object(const Object&) {	std::cout << "copy" << std::endl;	}
	
	// 이동생성자(또는 이동대입연산자)를 직접 만들때는
	// => 되도록 예외가 발생하지 않게 만들고
	// => 예외가 없음을 알리기 위해 noexcept 를 표기하세요

	Object(Object&&) noexcept 
	{
		std::cout << "move" << std::endl;
	}
};

int main()
{
	Object o1;
	Object o2 = o1; // 항상 복사 생성자 호출
	Object o3 = std::move(o1); // 항상 이동 생성자 호출

	Object o4 = std::move_if_noexcept(o1);	// 핵심
					// 이동생성자가 noexcept 인경우 이동생성자 사용
					// 아닌 경우 복사 생성자 사용
					// std::vector 가 내부적으로 이 함수로 버퍼 복사
		



	std::vector<Object> v(5);

	std::cout << "----------------" << std::endl;

	v.resize(10); // 이순간의 원리를 생각해봅시다.

	std::cout << "----------------" << std::endl;
}

