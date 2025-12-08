#include <iostream>

// C/C++98 스타일 enum 의 내부 요소에 대한 저장 타입 : int. 변경 못함.
// enum DAYOFWEEK { SUN = 0, MON = 1, TUE = 2 };

// C++11 enum class : 기본은 int. 변경 가능
// enum class DAYOFWEEK { SUN = 0, MON = 1, TUE = 2 };
enum class DAYOFWEEK : char { SUN = 0, MON = 1, TUE = 2 }; // 요소 타입 int

int main()
{
	DAYOFWEEK d = DAYOFWEEK::SUN;

	// enum 의 각 요소(variant) 의 타입과 크기 
	std::cout << sizeof(DAYOFWEEK::SUN) << std::endl;
}




