// 11 page
// C 스타일 코드 - typedef 
//typedef int DWORD;
//typedef void(*F)();  // 함수 포인터 타입

// C++11 using 
// => 아래 2줄이 위에 2줄과 완벽히 동일합니다.
using DWORD = int;
using F = void(*)();

int main()
{
	DWORD n; // int n
	F     f; // void(*f)()
}
