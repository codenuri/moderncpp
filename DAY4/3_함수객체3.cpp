#include <iostream>
#include <vector>
#include <algorithm>

// �Լ���ü�� ���� 2. Closure

bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };


	// �־��� �������� "3�� ���"�� ã�� �ʹ�. 
	// find_if : 3��° ���ڷ� "����(���ڰ� �Ѱ���)�Լ�" �� ����
	auto p1 = std::find_if(v.begin(), v.end(), foo);


	int k = 0;
	std::cin >> k;

	// �־��� �������� "����ڰ� �Է��� k�� ���"�� ã�� �ʹ�. 
	auto p2 = std::find_if(v.begin(), v.end(), ?);
}



