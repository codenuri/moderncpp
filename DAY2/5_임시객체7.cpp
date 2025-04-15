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

	Counter() = default;

	~Counter() { std::cout << cnt << " �� ���� ��ü �ı�\n"; }

	Counter(const Counter& other) : cnt(other.cnt)
	{
		std::cout << cnt << " �� ���� ��ü�� �����ؼ� ��ü ����\n";
	}

};

int main()
{
	Counter c;

	// �Ʒ� ó�� ��� �Լ��� �������� ȣ���ϴ� ����
	// => method chaining �̶�� �ϰ� ���� ���� ���� �����մϴ�.
	std::cout << "------------------------------------\n";
	c.increment().increment().increment();
	std::cout << "------------------------------------\n";

	std::cout << c.cnt << std::endl;
}