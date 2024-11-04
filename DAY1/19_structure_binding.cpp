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

	// 모든 멤버를 꺼내고 싶다.. util C++14
//	int x = p3d.x;
//	int y = p3d.y;
//	int z = p3d.z;
	
	// C++17 부터 아래 코드가능
	auto [x, y, x] = p3d;	// 위 3줄과 동일한 코드
							// auto x = p3d.0번째 멤버
							// auto y = p3d.1번째 멤버
							// auto z = p3d.2번째 멤버




	//-------------------------
	std::map<std::string, std::string> m;

	m["mon"] = "월요일";

	// map은 pair를 보관합니다.
	std::pair<std::string, std::string> p;
	p.first = "tue";
	p.second = "화요일";
	m.insert(p);

}

