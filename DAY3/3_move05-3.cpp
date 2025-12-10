#include <iostream>
#include <string>

int main()
{
	int n1 = 10;
	int n2 = std::move(n1);


	int* p1 = new int;
	int* p2 = std::move(p1);

	std::string s1 = "to be or not to be";
	std::string s2 = std::move(s1);
}