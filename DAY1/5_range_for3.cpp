#include <iostream>
#include <vector>

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















