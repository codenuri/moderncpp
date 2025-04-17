// 143 
#include <functional>
#include <vector>

void foo(int(*f)(int, int)) {} 

int main()
{
	// #1. ����ǥ������ ��� ���

	auto f1			   = [](int a, int b) { return a + b; };  

	int(*f2)(int, int) = [](int a, int b) { return a + b; };

	std::function<int(int, int)> f3 = [](int a, int b) { return a + b; };


	// #2. �ζ��� ġȯ ����
	int ret1 = f1(1, 2);			// �� �ڵ�� �����Ϸ��� ����
//  int ret1 = f1.operator()(1,2)	// �̷��� ����˴ϴ�. ��, �Լ��̸����� ȣ��
								    // ���� �ζ��� ġȯ�˴ϴ�.

	int ret2 = f2(1, 2); // �ζ��� ġȯ �ȵ�
	int ret3 = f3(1, 2); // �ζ��� ġȯ �ȵ�.

	// => f1 ���� �ٸ� ���� ǥ���� ������ ����
	// => f2, f3 �� �ٸ� ���� ǥ���� ������ ����
	//----------------------------------------------------
	
	// �Լ� �������� ���
	// => ĸ���� ���� ǥ������ �Լ� �����ͷ� ����ɼ� �����ϴ�.(������ ����)
	// => C������ ȣȯ���� �ʿ��Ҷ� ����ϼ���
	foo( [](int a, int b) { return a + b; } );


	// #3. ������ ���� ǥ������ �����̳ʿ� �����ϰ� �ʹ�.

	std::vector<auto> v1; // ?

	std::vector<int(*)(int, int)> v2; // ?

	std::vector<std::function<int(int, int)> v3; // ?
}