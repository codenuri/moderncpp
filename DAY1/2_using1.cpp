// using - 11 page

// C 스타일 코드 - typedef 
typedef int DWORD;
typedef void(*F)(); 

// C++11 부터는 using 사용하는 것을 권장
// => 아래 2줄은 위와 완전히 동일합니다.
using DWORD = int;
using F = void(*)();

int main() 
{
	DWORD n; // int n
	F     f; // void(*f)() 
}