#include <iostream>
#include <bitset>

class URandom
{
	std::bitset<10> bs; // 10 비트 관리
	bool recycle;
public:
	URandom(bool b = false) : recycle(b)
	{
//		bs.set(4); // 4번째 비트만 1
		bs.set();  // 모든 비트를 1
	}
	int operator()()
	{
		if (bs.none()) // 모든 비트가 0 이면
		{
			if (recycle == true)
				bs.set(); // 다시 모든 비트를 1로
			else
				return -1;
		}

		int k = -1;
		while ( !bs.test( k = rand() % 10 ) );
		bs.reset(k);
		return k;
	}
};

//URandom urand;	
URandom urand(true);

int main()
{
	for (int i = 0; i < 15; i++)
	{
		std::cout << urand() << std::endl;
	}
}
