// 6_forwarding_reference1 - ���� ���� �߿�!!
void f1(int&  r) {}
void f2(int&& r) {}

int n = 3;
f1(n); // ok
f1(3); // error. rvalue �� ������ ����.

f2(n); // error
f2(3); // ok
//------------------------------------------------
// �Լ� ���ڷ�
// int&  : int Ÿ���� lvalue �� ������ �ִ�.
// int&& : int Ÿ���� rvalue �� ������ �ִ�.

// T& : ���� Ÿ���� ? 

template<typename T> void f3(T& a)
{
}

int main()
{
	int n = 3;

	// #1. ����ڰ� Ÿ���� ��������� �����ϴ� ���
	f3<int>(? );	// T = ?      T& = ?     f3( ? a)
	f3<int&>(? );	// T = ?      T& = ?     f3( ? a)
	f3<int&&>(? );	// T = ?      T& = ?     f3( ? a)
}


