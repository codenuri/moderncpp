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
		if (bs.none()) // ��� ��Ʈ�� 0 �̸�
		{
			if (recycle == true)
				bs.set(); // �ٽ� ��� ��Ʈ�� 1��
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
