// 5_����ǥ����1 - 139
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };
	
	// sort �ϰ� �ʹٸ�

	// #1. ����å ������ ���� ���� ����
	std::sort(v.begin(), v.end()); 


	// #2. �� ��å ���� - �Ϲ��Լ�
	// => �� ��å�� �ζ��� ġȯ �ȵ�
//	std::sort(v.begin(), v.end(), cmp1);


	// #3. �� ��å ���� - �Լ� ��ü 
	// => C++ 98 ǥ�ؿ� �̹� �پ��� �Լ� ��ü �ֽ��ϴ�.
	// => <functional> ���
	std::less<int> f1;
	std::greater<int> f2;

	std::sort(v.begin(), v.end(), f1);
	std::sort(v.begin(), v.end(), std::less<int>{}); // �ӽð�ü���·�
	std::sort(v.begin(), v.end(), std::less{}); // C++17 ���� Ÿ�Ի�������

}





