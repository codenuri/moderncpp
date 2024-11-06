#include <iostream>
#include <vector>
#include <algorithm>

bool foo(int n) { return n % 3 == 0; }


struct IsDivide
{
	int value;
	IsDivide(int v) : value(v) {}

	bool operator()(int n) { return n % value == 0; }
};

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };
	int k = 3;

	IsDivide f(k);  // 
	bool b = f(10); // 

//	auto p2 = std::find_if(v.begin(), v.end(), ? );

}



