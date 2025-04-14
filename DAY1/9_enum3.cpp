#include <iostream>
#include <type_traits>

// SUN, MON, TUE 는 내부적으로 int 사용(즉, 32비트 정수)
// enum class DAYOFWEEK { SUN = 0, MON = 1, TUE = 2 };


// 아래 처럼하면 각 값을 char 로 해달라.
enum class DAYOFWEEK : char { SUN = 0, MON = 1, TUE = 2 };

int main()
{
	using T = std::underlying_type<DAYOFWEEK>::type;	
		
	// 현재 T 는 char 타입

	std::cout << typeid(T).name() << std::endl;
}




