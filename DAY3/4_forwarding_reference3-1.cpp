// �Լ� ���ڷ�
// int&  : int Ÿ���� lvalue �� ������ �ִ�.
// int&& : int Ÿ���� rvalue �� ������ �ִ�.
// T&    : ���� Ÿ���� lvalue �� ������ �ִ�. 
// T&&   :

template<typename T> void f4(T&& a)
{
}
int main()
{
	int n = 3;

	// #1. ����ڰ� Ÿ���� ��������� �����ϴ� ���
	f4<int>(n);		// T =       T& = 			  f4(? a)
	f4<int&>(n);	// T =       T& = 			  f4(? a)
	f4<int&&>(n);	// T =       T& = 			  f4(? a)


}


