// 5_����ǥ����5
#include <iostream>
#include <vector>
#include <algorithm>

// ����ǥ���İ� Ÿ��

int main()
{
	// #1. ��� ���� ǥ������ �ٸ� Ÿ�� �Դϴ�.
	//     ������ �����ص� ��� ���� ǥ������ �ٸ� Ÿ���Դϴ�.

	auto f1 = [](int a, int b) { return a + b; };
				// class xxx{};   xxx{};

	auto f2 = [](int a, int b) { return a + b; };
				// class yyy{};    yyy{};

	// #2. �Ʒ� �ڵ�� Ȯ�� �����մϴ�.
	std::cout << typeid(f1).name() << std::endl;
	std::cout << typeid(f2).name() << std::endl;


	// #3. ����ǥ�������� �ʱ�ȭ�� ������ �ٸ� ���� ǥ����
	//     ������ �����ϴ�.
	// => ������ Ÿ���� �ٸ��ϴ� (��� �󼭰� �ƴմϴ�.)
	// 

	auto f3 = [](int a, int b) { return a + b; };

	f3 = [](int a, int b) { return a + b; }; // error
}





