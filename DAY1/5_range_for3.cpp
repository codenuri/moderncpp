#include <iostream>
#include <vector>

struct Point3D
{
	int x, y, z;
};

int main()
{
	Point3D p;
	p.x = 10;
	p.y = 20;
	p.z = 30;

	for (int n : p) // 될까요 ?? 왜 안될까요 ? 되게 하려면
		std::cout << n << std::endl; 

}















