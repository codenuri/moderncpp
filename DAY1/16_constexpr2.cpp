
// constexpr  : ������ �ð� ����� ����� Ű����
// const      : immutable �� ����� Ű����. 

int main()
{
	int n = 3;

	// �Ʒ� c1, c2�� �����Ҽ� ���ٴ� ��
	const int c1 = n; // ok runtime constant 
	const int c2 = 3; // ok compile time constant

	// �Ʒ� c3, c4 �� �ݵ�� �������Ҷ� �˾ƾ� �ϰ�
	// �����Ҽ��� ���ٴ°�
	constexpr int c3 = n; // error
	constexpr int c4 = 3; // ok


	// ���� ������ ����
	// "const int c3 = ���ͷ�" �� ������ �ð� ����� ��밡���ѵ�
	// �� ?? constexpr �� �ʿ� �մϱ� ?
	// => constexpr function ��������..
	
	int arr1[c1];	// error. 
	int arr2[c2];	// ok
	int arr3[c4];	// ok
}
