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

	// 주의 사항
//	int [x, y, x] = p3d; // error. auto 만가능

//	auto [x, y] = p3d;    // error. 갯수가 다름.


	auto [a1, a2, _ ] = p3d;  // C# : _ 는 관심 없다는 의미. 무시
							  // C++ : _ 는 변수이름.
							  // auto _ = p3d.z

//	auto [b1, b2, _] = p3d; // error
							// auto _ = p3d.z 때문에 _이름이 2번선언
							// 단, C++26 부터 는 에러아님
							// => 변수이름이 _인 지역변수는 여러개 선언가능

//	int _ = 10;
//	int _ = 20; // ok

	//	구조체뿐 아니라 배열도 가능
	int arr[3] = { 1,2,3 };

	auto [c1, c2, c3] = arr; // ok


	//-------------------------
	std::map<std::string, std::string> m;

	m["mon"] = "월요일";
	m["tue"] = "화요일";

	for (auto& e : m)
	{
		// map 은 pair 를 보관하므로
		// e의 타입은 pair 입니다.

		std::string key = e.first;
		std::string value = e.second;
	}
	// 위 코드를 C++17 로 다시 만들면
	for (auto& [key, value] : m) // auto& [key, value] = m의요소인 pair
	{							 // auto& key = pair.first
								//  auto& value = pair.second
	}


}

