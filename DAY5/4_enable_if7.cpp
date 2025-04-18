#include <iostream>
#include <type_traits>

// C++20 은 기존의 타입을 조사하는 "type traits" 기술을 발전시킨
// concept 문법을 만들었습니다.
template<typename T>
concept pointer = std::is_pointer_v<T>;

template<typename T>
concept not_pointer = !std::is_pointer_v<T>;

//-------------------------------------------
// 아래 코드가 enable_if6 과 동일한 의미
/*
template<pointer T> 
void printv(const T& v)
{
	std::cout << "포인터 " << v << " : " << *v << std::endl;
}

template<not_pointer T>
void printv(const T& v)
{
	std::cout << "포인터 아님 " << v << std::endl;
}
*/
//-----------------
void printv(pointer auto  v)
{
	std::cout << "포인터 " << v << " : " << *v << std::endl;
}

void printv(not_pointer auto  v)
{
	std::cout << "포인터 아님 " << v << std::endl;
}


int main()
{
	int n = 10;
	double d = 3.4;

	printv(n);
	printv(d);
	printv(&n);
}

