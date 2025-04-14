// github.com/codenuri/moderncpp 에서 DAY.zip 받으시면 됩니다.
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

	// 모든 멤버를 꺼내고 싶다.
	// C++17 이전에 사용하던 기술
	int x = p3d.x;
	int y = p3d.y;
	int z = p3d.z;

	// 파이썬언어라면 "deconstruction" 기술 사용(C#, java) 등도 제공
//	(x, y, z) = p3d;

	// C++17 이후
	// => structure binding 이라고 불리는 문법 입니다.
	// => public 멤버인 경우만 가능
	auto [a1, a2, a3] = p3d; // auto a1 = p3d.x;
							 // auto a2 = p3d.y;
							 // auto a3 = p3d.z;

	// auto 만 가능 합니다.
//	int[b1, b2, b3] = p3d; // error

	// 갯수가 동일해야 합니다
//	auto [c1, c2] = p3d; // error


	// 배열도 가능합니다.
	int arr[3] = { 1,2,3 };
	auto [d1, d2, d3] = arr;



	//-------------------------
	std::map<std::string, std::string> m;

	m["mon"] = "월요일";

	// map은 pair를 보관합니다.
	std::pair<std::string, std::string> p;
	p.first = "tue";
	p.second = "화요일";
	m.insert(p);

}


// 1. 출석부 서명해 주세요

// 2. github.com/codenuri/moderncpp 에서 
// 
// DAY2.zip 받으시면 됩니다.

