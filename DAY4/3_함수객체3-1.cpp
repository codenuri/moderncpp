#include <iostream>
#include <vector>
#include <algorithm>

bool foo(int n) { return n % 3 == 0; }


struct IsDivide
{
	int value;
	IsDivide(int n) : value(n) {}

	bool operator()(int n)  { return n % value == 0; }
};

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };

	int k = 3;

	IsDivide f(k);	// f �� ���������� k ���� ĸ��(����) �մϴ�.
					// f �� �����Լ� ó�� ��� �����մϴ�.

	bool ret = f(10); // "10 % k(3) == 0" �� �����ϴ� �Լ�


	auto p2 = std::find_if(v.begin(), v.end(), f );

	std::cout << *p2 << std::endl;// 6
}



