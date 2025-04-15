int x = 10;
int& foo() { return x;  }

int main()
{
	int x[3] = { 1,2,3 };

	// auto �� decltype �� �и��� �߷� ��Ģ �ٸ��ϴ�.
//	decltype(x[0]) d;	// int& d
	auto a = x[0];		// int a = x[0]


	auto ret1 = foo();	
//  int  ret1 = foo(); // auto �� �캯�� reference �� �����ϰ� ����

	// decltype(�Լ�ȣ���) : �Լ��� ������ ���� ��ȯ Ÿ������
	decltype(foo()) ret2 = foo();
//  int&            ret2 = foo();

	// decltype(auto)
	// => C++14 ����
	// => decltype ��Ģ�� ����ϴµ� �߷��� �캯����
	// => (auto) ��ġ�� �캯�� ������� �ǹ�
	decltype(auto) ret3 = foo(); 
//  decltype(foo()) ret3 = foo() �� ����
}

