#include <iostream>
#include <string>

// max 를 만들어 봅시다.
// => C++ 표준의 max 가 아래와 동일한 모양입니다.
template<typename T>
const T& Max(const T& a, const T& b)
{
	return a < b ? b : a;
}

int main()
{
	std::string s1 = "abc";
	std::string s2 = "efg";

	std::string s3 = Max(s1, s2); // ok. 단, s3는 s2의 복사본
	const std::string& s4 = Max(s1, s2); // ok. s4는 s2의 별명

	// 
	const std::string& s5 = Max(std::string("ab"), std::string("ef"));

	// s5를 사용해도 안전할까요 ?
}
