// typename
struct Test
{
	static int data;
	typedef int DWORD; // using DWORD = int;
};
int Test::data = 0;
int p1 = 0;

template<typename T> void foo(T a)
{
	// �Ʒ� �ڵ忡�� * �� �ǹ̸� ������ ������
	Test::data  * p1;	// 0 * 0    ���⼭ * �� ���ϱ��� �ǹ�
	Test::DWORD * p2;	// int* p2  ���⼭ * �� ������ ������

	// "Ŭ�����̸�::�̸�" ���� "�̸�" ��
	// 1. ���ϼ��� �ְ� ( static ��� ����Ÿ, enum �����)
	// 2. Ÿ�� �ϼ��� �ֽ��ϴ�. ( typedef, using)
	// => ������ Ÿ�� ������ ���� * ���� ������ �ǹ̰� �޶� ���ϴ�.
	
}
int main()
{
}




