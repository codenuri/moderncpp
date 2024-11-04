#include <iostream>
#include <type_traits>

// 요소 타입 지정 가능
//enum class DAYOFWEEK { SUN = 0, MON = 1, TUE = 2 }; // int
enum class DAYOFWEEK : char { SUN = 0, MON = 1, TUE = 2 }; // char

int main()
{
	using T = std::underlying_type_t<DAYOFWEEK>;

	std::cout << typeid(T).name() << std::endl; // char

}




