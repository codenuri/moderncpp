#include <iostream>
#include <vector>
#include <list>
/*
void print_first_element(std::vector<int>& v)
{
	int n = v.front();

	std::cout << n << std::endl;
}
*/
/*
template<typename T>
void print_first_element(std::vector<T>& v)
{
	T n = v.front();

	std::cout << n << std::endl;
}
*/

template<typename T>
void print_first_element(T& v)
{
	// T : std::list<double>
	// 
	// T::value_type => std::list<double>::value_type => double

	typename T::value_type n = v.front();

	std::cout << n << std::endl;
}

int main()
{
//	std::vector<int> v = { 1,2,3,4 };
//	std::vector<double> v = { 1,2,3,4 };
	std::list<double> v = { 1,2,3,4 };

	print_first_element(v);
}

// 템플릿으로 만들어진 컨테이너를 사용할때는
// 요소의 타입을 알고 싶을때가 있습니다.
// 위 "print_first_element" 처럼

// 그래서 STL 은 모두 아래 처럼되어 있습니다.
template<typename T> class list
{
public:
	using value_type = T; // <== 핵심 개념

};

std::list<int> s = { 1,2,3 };
std::list<int>::value_type n = s.front(); // int n = s.front()

// cppreference.com 에서 std::list 검색

// STL은
// "멤버 함수", "멤버 변수" 외에
// "멤버 타입" 이라는 개념이 있습니다.
/*
template<typename T>
class List
{
	// 멤버 타입
	using value_type = T;
	using iterator = _list_iterator;
	using size_type = std::size_t;

	// 멤버 데이타

	// 멤버 함수

};
*/