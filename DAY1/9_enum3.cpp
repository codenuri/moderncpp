#include <iostream>

enum DAYOFWEEK { SUN = 0, MON = 1, TUE = 2 };
//enum class DAYOFWEEK { SUN = 0, MON = 1, TUE = 2 };

int main()
{
	// enum 의 각 요소(variant) 의 타입과 크기 
	std::cout << sizeof(DAYOFWEEK::SUN) << std::endl;
}




