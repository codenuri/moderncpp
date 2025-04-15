// 5_�ӽð�ü7.cpp �߰���
// => git �� �ڵ� �ֽ��ϴ�. ������ ������

#include <iostream>

class Counter
{
public:
	int cnt{ 0 };

	Counter increment()
	{
		++cnt;

		return *this;
	}
};

int main()
{
	Counter c;

	// �Ʒ� ó�� ��� �Լ��� �������� ȣ���ϴ� ����
	// => method chaining �̶�� �ϰ� ���� ���� ���� �����մϴ�.
	c.increment().increment().increment();

	std::cout << c.cnt << std::endl;
}