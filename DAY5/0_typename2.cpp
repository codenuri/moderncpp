struct Test
{
	static int data;
	typedef int DWORD; 
};
int Test::data = 0;
int p1 = 0;

template<typename T> void foo(T a)
{
	// �����̸�(dependent name)
	// => ���ø� ���� T�� �����ؼ� ������ �̸�
	// => �����Ϸ��� "�����̸�"�� ������ ������ �ؼ��Ѵ�.

	T::data  * p1;	
//	T::DWORD * p2;	

	// typename : dependent name �� Ÿ������ �ؼ��� �޶��
	//			  �����Ϸ����� �˷� �ִ°�
	//			  C++98 ���� ���� �ִ� ����
	typename T::DWORD* p2;



}
int main()
{
}




