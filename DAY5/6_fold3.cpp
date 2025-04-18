#include <vector>
#include <iostream>

// 복습하실때 구글에서 "C++ fold expression example" 해보세요
// 많은 예제를 볼수 있습니다.

template<typename ... Types>
void insert_vector(std::vector<int>& v, Types ... args)
{
	// args 의 모든 요소를 v 에 넣어 보세요
	( v.push_back(args), ...  );
//    (pack           op ...)	(E1 op(... op(EN - 1 op EN)))
//    v.push_back(1), ( v.push_back(2), ( v.push_back(3) .. 
}

int main()
{
	std::vector<int> v;

	insert_vector(v, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

	for (auto e : v)
		std::cout << e << ", ";
}