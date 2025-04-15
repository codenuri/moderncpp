// 20_Ÿ���߷�5

template<typename T> void foo(T a) {}

int main()
{
	// #1. ���ø��� ȣ��� ������ ���ڷ� Ÿ�� �߷�
	foo(10);		// �ᱹ �� �ڵ��
//  T    a = 10;	// �� �ڵ� �Դϴ�.
	auto a = 10;	// �ᱹ auto �� ������ ����Դϴ�.
					// �׷��� template �߷а� auto �߷��� ���� ������ ��Ģ���

	//----------------------------------------------
	int  n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	// auto �߷��� ���ø� �߷а� �����մϴ�.
	// �Ʒ� �� ������ Ÿ���� ������ ������
	// T a1 = n �� �����̹Ƿ� ���ø����� ��� "��Ģ #1"���� �ϸ� �˴ϴ�.
	auto a1 = n;  // a1 : int
	auto a2 = r;  // a2 : int
	auto a3 = c;  // a3 : int
	auto a4 = cr; // a4 : int

	// T& a5 = n; �̹Ƿ� ���ø����� ��� "��Ģ #2" ����
	// => �캯�� reference �Ӽ��� ����, const, volatile �� ����
	auto& a5 = n;  // auto : int   a5 : int&
	auto& a6 = r;  // auto : int   a6 : int&
	auto& a7 = c;  // auto : const int   a7 : const int&
	auto& a8 = cr; // auto : const int   a8 : const int&

	// �ᱹ template �� ������ ��Ģ �����ϸ� �˴ϴ�.
	// template : T Ÿ���� �����ϱ� ����.
	// auto : auto �� �߷е� Ÿ���� �����ϱ� ��ƴ�.

	// �����ϰ������ "���Ƿ� ����" �� ������ �ϼ���
	// => ���� �޼��� �ʿ� Ÿ���� ��Ÿ���� �˴ϴ�.
	// => ��Ȯ���� �������� �ֽ��ϴ�.
	*a7 = 10;

	
}


