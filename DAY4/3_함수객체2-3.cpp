#include <iostream>
#include <bitset>

class URandom
{
	std::bitset<10> bs; // 10 ��Ʈ ����
	bool recycle;
public:
	URandom(bool b = false) : recycle(b)
	{
//		bs.set(4); // 4��° ��Ʈ�� 1
		bs.set();  // ��� ��Ʈ�� 1
	}
	int operator()()
	{
		return rand() % 10;
	}
};



URandom urand;	





int main()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << urand() << std::endl;
	}
}
