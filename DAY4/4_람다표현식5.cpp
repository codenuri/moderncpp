// 143 
#include <functional>

int main()
{
	// ����ǥ������ ��� ���

	auto f1			   = [](int a, int b) { return a + b; };

	int(*f1)(int, int) = [](int a, int b) { return a + b; };

	std::function<int(int, int)> f3 = [](int a, int b) { return a + b; };
}