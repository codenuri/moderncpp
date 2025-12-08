#include <iostream>
#include <vector>
// 아래 코드는 Point3D 의 모든 요소가
// 동일타입의 연속된 메모리 라는 조건을 만족할때만 사용가능.
struct Point3D
{
	int x, y, z;

	// 어떤 타입을 range-for 에 넣으려면
	// begin()/end() 가 멤버 함수 또는 일반함수로 제공하면 됩니다.
	int* begin() { return &x; }			// 1번째 요소의 주소(반복자는 결국 포인터와 유사)
	int* end()   { return &z + 1; }		// 마지막 요소의 다음 주소.
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















