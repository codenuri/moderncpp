#include <iostream>
#include <vector>

struct Point3D
{
	int x, y, z;

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















