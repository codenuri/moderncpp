#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}
	Object(const Object&) { std::cout << "copy" << std::endl; }
//	Object(Object&&)      { std::cout << "move" << std::endl; }
};
int main()
{
	// #1. move 생성자를 만들지 않은 클래스에 대해서 std::move() 사용했다면 ?
	// => 
	Object o1;
	Object o2 = std::move(o1);
				// static_cast<Object&&>(o1) 의 의미일뿐!!!
				// 따라서 이 코드는
				// 1. move 생성자가 있다면 사용하고
				// 2. 없다면 복사 생성자를 사용한다.
				// => 결국, move 생성자가 없는 타입에 대해서도 std::move() 사용가능
				// => 단, move 효과는 없다.



	// #2. primitive type 에 대해서 std::move 를 사용했다면 ?
	// =>
	int n1 = 10;
	int n2 = std::move(n1);
			// static_cast<int&&>(n1) 이므로 아무 효과는 없습니다


	int* p1 = new int;
	int* p2 = std::move(p1);
			// 역시 아무 효과 없습니다.
			// p1 이 0 이 되는것 아닙니다.



	// #3. STL 은 대부분 move 생성자를 지원합니다.
	std::vector<int> v1 = { 1,2,3,4 };
	std::vector<int> v2 = std::move(v1);

	std::cout << v1.size() << std::endl; // 0
}

