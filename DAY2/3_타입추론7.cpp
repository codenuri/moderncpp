// �ٽ� : auto(template) �� �迭 �̾߱�

template<typename T> void f1(T a,  T b)  {}
template<typename T> void f2(T& a, T& b) {}

int main()
{
	int x[3] = { 1,2,3 };

	// �Ʒ� �ڵ忡�� auto �� a1, a2 �� Ÿ���� ������ ������

	auto  a1 = x;
			// 1. int a1[3] = x; �� �����ߴٸ� ������ ����
			// 2. int* a1 = x;   �� �����ߴٸ� ok
			// ���� �̰��
			// auto : int*    a1 : int*


	auto& a2 = x;			
			// int(&a2)[3] = x �� �����ص� ���� �ƴմϴ�.
			// ���� �̰�� auto ��
			// auto : int[3]	a2 : int(&)[3]  �Դϴ�.


	// ��� auto ��  �迭�� �ʱ�ȭ �Ҷ�
	// �� Ÿ���̸� : auto �� �����Ͱ� �˴ϴ�.
	// ���� Ÿ���̸� : auto �� �迭 �Դϴ�, 






	// ������ ������ ?
//	f1("apple", "orange");
//	f2("apple", "orange");
}