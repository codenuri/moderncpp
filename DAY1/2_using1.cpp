// using - 10 page
// 
// C 언어 스타일 - typedef 
// typedef int DWORD;
// typedef void(*F)(); 

// C++11 using 
// => 아래 2줄은 위 2줄과 완전히 동일합니다.
using DWORD = int;
using F = void(*)();


int main() 
{
	DWORD n; // int n
	F     f; // void(*f)()
}