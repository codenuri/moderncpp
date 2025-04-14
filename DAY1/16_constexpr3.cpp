// C++ ���� constexpr �� 3���� �뵵�� ���˴ϴ�.
// 1. constexpr ��� - C++11 - ��������
// 2. constexpr �Լ� - C++11 - ���� ����
// 3. constexpr if   - C++17


// constexpr �Լ�
// => �Լ� �տ� "constexpr" ���ΰ�
// 1. ���� ���� ������ �ð��� �˼� �ְ�
// 2. �Լ��� ����� ������ �ð��� �˾ƾ� �Ѵٸ�
// => �Լ� ȣ���� ������ �Ҷ� �����ϰڴٴ� ��

constexpr int Factorial(int n)
{
	return n == 1 ? 1 : n * Factorial(n - 1);
}

int main()
{
	int n = 5;

	int arr1[Factorial(5)]; // ok. ������ �ϸ� int arr1[120] �� �˴ϴ�.

	int arr2[Factorial(n)]; // error. ���ڰ��� ������ �Ҷ� �˼� ����.
						
	int s2 = Factorial(n); // ok. ����ð��� �Լ� ȣ��

	// 
	int ret1 = Factorial(5); // ok. ������ �ð� ? ����ð� ?
							// => �����Ϸ��� ����, ������ ���� �ٸ�

	const int ret2 = Factorial(5); // ok. ������ �ð� ? ����ð� ?
							// => �����Ϸ��� ����, ������ ���� �ٸ�

	constexpr int ret3 = Factorial(5); // ok. ������ �ð� ? ����ð� ?
							// => �ݵ�� ������ �Ҷ� ������ �޶�� ��
							// 
}
