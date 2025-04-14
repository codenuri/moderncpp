// github.com/codenuri/moderncpp ���� DAY.zip �����ø� �˴ϴ�.
// 
// 19_structure_binding - 52 page
#include <map>
#include <string>

struct Point3D
{
	int x = 0, y = 0, z = 0;
};
int main()
{
	Point3D p3d;

	// ��� ����� ������ �ʹ�.
	// C++17 ������ ����ϴ� ���
	int x = p3d.x;
	int y = p3d.y;
	int z = p3d.z;

	// ���̽����� "deconstruction" ��� ���(C#, java) � ����
//	(x, y, z) = p3d;

	// C++17 ����
	// => structure binding �̶�� �Ҹ��� ���� �Դϴ�.
	// => public ����� ��츸 ����
	auto [a1, a2, a3] = p3d; // auto a1 = p3d.x;
							 // auto a2 = p3d.y;
							 // auto a3 = p3d.z;

	// auto �� ���� �մϴ�.
//	int[b1, b2, b3] = p3d; // error

	// ������ �����ؾ� �մϴ�
//	auto [c1, c2] = p3d; // error


	// �迭�� �����մϴ�.
	int arr[3] = { 1,2,3 };
	auto [d1, d2, d3] = arr;



	//-------------------------
	std::map<std::string, std::string> m;

	m["mon"] = "������";

	// map�� pair�� �����մϴ�.
	std::pair<std::string, std::string> p;
	p.first = "tue";
	p.second = "ȭ����";
	m.insert(p);

}


// 1. �⼮�� ������ �ּ���

// 2. github.com/codenuri/moderncpp ���� 
// 
// DAY2.zip �����ø� �˴ϴ�.

