#include <iostream>

// �Լ� ��ü�� "����" �� �ƴ϶� "����"�� �ֽ��ϴ�.
// => "��� ����Ÿ"�� �ִٴ� �ǹ�.
// => ������, ��� �Լ�� Ȱ�� �����մϴ�.

class URandom
{
public:	
	int operator()()
	{
		return rand() % 10;
	}
};

URandom urand;	// �Լ��� �ƴ� ��ü �Դϴ�.
				// () �����ڰ� �����ǵǾ �Լ� ó�� ��밡��





int main()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << urand() << std::endl;
	}
}