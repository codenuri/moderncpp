#include <iostream>
#include "stopwatch.h" // �� ��� ���弼��
						// git �� �ҽ� �ֽ��ϴ�. ������ ��������

int sum(int first, int last)
{
	int s = 0;

	while (first != last)
	{
		s = s + first;
		++first;
	}
	return s;
}

template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg)
{
	stop_watch sw(true);	
		// => �����ڿ��� �ð� ���
		// => �Ҹ��ڿ��� ����ð� ���
		// => "true" �ǹ̴� �Ҹ��ڿ��� ����� �޶�� ��.

	return f(std::forward<T>(arg)...);
}

int main()
{
	int ret = chronometry(sum, 1, 1000000); // 0 6��

	std::cout << "��� : " << ret << std::endl;
}
