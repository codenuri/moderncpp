#include <iostream>
#include <vector>

// 파이썬, C#, Java 등 거의 모든 언어의 range-for 원리는
// => 반복자를 꺼내는 것 입니다.
// => 그래서, "iterable 한 타입" 만 range-for 에 넣을수 있다 라고 합니다.

struct Point3D
{
	int x = 1, y = 2, z = 3;

	// Point3D 타입의 객체를 range-for 에 넣으려면
	// begin/end 멤버함수가 있으면 됩니다.
	int* begin() { return &x; }
	int* end() { return &z + 1; }
};

int main()
{
	Point3D p;
	p.x = 10;
	p.y = 20;
	p.z = 30;

	for (int n : p)  // 될까요 ? 되게하려면 필요한 것은 ?
		std::cout << n << std::endl; 

}















