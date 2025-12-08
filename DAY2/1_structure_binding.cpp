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

	// 구조체 각 필드에서 값을 꺼내는 방법

	// #1. C++17 이전
	int x = p3d.x;
	int y = p3d.y;
	int z = p3d.z;

	// #2. C++17 이후
	auto [a1, a2, a3] = p3d;  // 이 한줄이 위 3줄과 동일

//	auto [a1, a2] = p3d;		// error. 갯수가 동일해야 합니다
//	int  [a1, a2, a3] = p3d;	// error. int 안됨. auto 만 가능. 

	// 파이썬이나 C# 은 관심 없음을 표기할때 _ 사용
	auto [b1, _, b3] = p3d; // ok
							// int _ = p3d.y  는 ok
	auto [c1, _, c3] = p3d; // error
							// int _ = p3d.y  는 error
							// 이미 선언된 변수 _ 와 동일이름
							// 단, C++26 부터는 가능.
	// C++26 의 재미있는 문법
	// 이름이 _ 인 변수는 여러번 만들수 있다.
	//int _ = 10;
	//int _ = 20;

	// 배열도 가능합니다.
	int arr[3] = { 1,2,3 };

	auto [d1, d2, d3] = arr; // ok



	//-------------------------
	std::map<std::string, std::string> m;

	m["mon"] = "월요일";

	
	std::pair<std::string, std::string> p;
	p.first = "tue";
	p.second = "화요일";
	m.insert(p);

}

