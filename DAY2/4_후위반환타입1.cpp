// 1_������ȯŸ��1.cpp - ���� 73 page

// �������� �Լ� ���
int square1(int a)
{
	return a * a;
}

// C++11 ���� ������ ���� ��ȯ Ÿ��(suffix return type)
auto square2(int a) -> int
{
	return a * a;
}

int main()
{
	square1(3);
}