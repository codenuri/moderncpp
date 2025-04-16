// 91 page
int main()
{
	int n = 10;


	int *p = &n;
	int* *pp = &p;	// ���� ������
					// �������� �����͸� ����� �ֽ��ϴ�.

	int& r = n;
	int& &rr = r;	// error
					// ���۷����� ���۷����� ����� �����ϴ�.

	// ������, �����̳� Ÿ�� �߷��� �������� ������
	// ���۷����� ���۷����� ������ �ƴմϴ�.
	// => �Ʒ� ��Ģ��� �ؼ��˴ϴ�. 

	using LREF = int&; 
	using RREF = int&&;

	// reference collapsing
	LREF& r3 = n;		// int&  &	=> int&
	RREF& r4 = n;		// int&& &	=> int&
	LREF&& r5 = n;		// int&  && => int&
	RREF&& r6 = 3;		// int&& && => int&&
}


template<typename T> void foo(T a)
{
	T& r = a;   // int& & r => int& r
}

foo<int&>(n); // �� �ڵ忡�� r�� Ÿ���� ?



