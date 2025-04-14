// 7 page
#include <cassert>

// assert : ����ð� ���� ��ȿ�� Ȯ��.
//			�����ϸ� ����ð� ���� �߻�

// static_assert : ������ �ð� ǥ������ ��ȿ�� Ȯ��
//				   �����ϸ� ������ ����!!
// => static_assert �ȿ� ���̴� ���ǽ��� �ݵ�� ������ �Ҷ�
//	  ���� �����ؾ� �մϴ�
//    ���� ����Ҽ� �����ϴ�.
static_assert(sizeof(int*) >= 8, "error, use 64 bit");
//static_assert(age > 0 , "error, use 64 bit"); // �� ǥ���� �ȵ�
						// "���� age" �� ��� �Ҽ� ����

void foo(int age)
{
	// �Լ� ���ڴ� ����ϱ� ����
	// ��ȿ���� Ȯ���ϴ� ���� �����ϴ�.
//	assert(age > 0);

	int* p = new int[age];

	delete[] p;
}

int main()
{
//	foo(-10);
	foo(10);
}