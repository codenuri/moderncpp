#include <iostream>
#include <type_traits>

// SUN, MON, TUE �� ���������� int ���(��, 32��Ʈ ����)
// enum class DAYOFWEEK { SUN = 0, MON = 1, TUE = 2 };


// �Ʒ� ó���ϸ� �� ���� char �� �ش޶�.
enum class DAYOFWEEK : char { SUN = 0, MON = 1, TUE = 2 };

int main()
{
	using T = std::underlying_type<DAYOFWEEK>::type;	
		
	// ���� T �� char Ÿ��

	std::cout << typeid(T).name() << std::endl;
}




