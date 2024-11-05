#include <iostream>
#include <string>

// max 를 만들어 봅시다.
int max(int a, int b)
{
	return a < b ? b : a;
}

int main()
{
	std::string s1 = "abc";
	std::string s2 = "efg";

	std::string s3 = max(s1, s2);
}
