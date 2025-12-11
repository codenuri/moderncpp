#include <iostream>
#include <algorithm>

// lambda expression 장점 #1.

bool is_even(int n) { return n % 2 == 0; }

int main()
{
	int x[5] = { 2,4,6,3,8 };

	// 주어진 구간에서 처음 나오는 짝수를 찾고 싶다
	int* p1 = std::find_if(x, x + 5, is_even);

	// 주어진 구간에서 처음 나오는 k의 배수를 찾고 싶다 ??
	int k = 3;
	int* p2 = std::find_if(x, x + 5, is_even);


}