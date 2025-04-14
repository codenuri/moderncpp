
// constexpr  : ������ �ð� ����� ����� Ű����
// const      : immutable �� ����� Ű����. 

int main()
{
	int n = 3;

	// �Ʒ� c1, c2�� �����Ҽ� ���ٴ� ��
	const int c1 = n; // ok
	const int c2 = 3; // ok

	// �Ʒ� c3, c4 �� �ݵ�� �������Ҷ� �˾ƾ� �ϰ�
	// �����Ҽ��� ���ٴ°�
	constexpr int c3 = n; // error
	constexpr int c4 = 3; // ok


	// ���� ������ ����
	// "const int c3 = ���ͷ�" �� ������ �ð� ����� 

	int arr1[c1];
	int arr2[c2];
	int arr3[c4];
}
