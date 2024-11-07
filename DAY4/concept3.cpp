#include <iostream>
#include <vector>
#include <algorithm>
#include <type_traits>  
#include <concepts> 

// C++98 시절에는 아래 2개를 구별할 방법이 없었습니다.
// C++20 부터는 템플릿 인자가 제약조건을 만족할때만 사용하게 하면됩니다.
template<typename IT, typename V>
void find(IT first, IT last, const V& value)
{
	std::cout << "값 검색\n";
}

template<typename IT, typename F> 
	requires std::predicate<F, typename IT::value_type>

void find(IT first, IT last, F f)
{
	std::cout << "조건 검색\n";
}

int main()
{
	std::vector<int> v = { 1,2,3 };

//	std::find   (v.begin(), v.end(), 3);
//	std::find_if(v.begin(), v.end(), [](int n) {return n % 2 == 0; });

	xfind(v.begin(), v.end(), 3);
	xfind(v.begin(), v.end(), [](int n) {return n % 2 == 0; });

}
