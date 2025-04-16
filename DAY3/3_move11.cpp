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
	const Object o1;

	// 상수 객체는 move 될수 없다. 
	// 아래 코드는 복사 생성자 호출
	Object o2 = std::move(o1);	
				// static_cast<o1타입&&>(o1)
				// static_cast<const Object&&>(o1)
				// => Object&& 에 전달할수 없지만
				// => const Object& 에 전달할수 있다. 

	// 참고 : rust 는 상수도 move 됩니다.
	//		  원리는 학습해 보세요. 
}



