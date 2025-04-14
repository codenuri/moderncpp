#include <iostream>
#include <vector>

struct Point3D
{
	int x = 1, y = 2, z = 3;

	// Point3D Ÿ���� ��ü�� range-for �� ��������
	// begin/end ����Լ��� ������ �˴ϴ�.
	int* begin() { return &x; }
	int* end() { return &z + 1; }
};

int main()
{
	Point3D p;
	p.x = 10;
	p.y = 20;
	p.z = 30;

	for (int n : p)  // �ɱ�� ? �ǰ��Ϸ��� �ʿ��� ���� ?
		std::cout << n << std::endl; 

}















