//8_nullptr3
#include <iostream>

int main()
{
	// literal �� Ÿ��
	// => C/C++ ���� ��� ���ͷ��� Ÿ���� �ֽ��ϴ�.
	3;			// int
	3.4;		// double
	"hello";	// const char[6]
	false;		// bool,     false �� Ű���� �̰�, ���ͷ�(��)�Դϴ�.
	nullptr;	// std::nullptr_t Ÿ��,   Ű�����̰� ���ͷ� �Դϴ�.


	std::nullptr_t arg = nullptr;

	// std::nullptr_t Ÿ���� ��� ������ �����ͷ� �Ͻ��� ����ȯ �ȴ�.
	// ��� ������ �ֽ��ϴ�.

	int* p1 = arg;
	char* p2 = arg;

	// ���� : C# ���� null �� �ִµ�,,
	// => null �� Ÿ���� ����. ��� ���ǵǾ� �ֽ��ϴ�.
	// => ��� ���� Ÿ���� ������ null �� Ÿ���� ���ٴ� "������ ����"
}



