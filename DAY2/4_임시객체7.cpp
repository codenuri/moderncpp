#include <string>

std::string foo()
{
	std::string s("abcd");
	return s;
}
int main()
{
	// 아래 코드는 안전한가요 ?
	// => 안전합니다. for 문 종료시 까지 temporary 파괴안됨
	for (auto e : std::string("abcd") )
	{
		// ... 
	}
	// 아래 코드는 안전한가요 ?
	for (auto e : foo() )
	{
		// ... 
	}
}