// �Լ� ���ڷ�
// int&  : int Ÿ���� lvalue �� ������ �ִ�.
// int&& : int Ÿ���� rvalue �� ������ �ִ�.
// T&    : ���� Ÿ���� lvalue �� ������ �ִ�. 

// T&&   : ���� Ÿ���� lvalue �� rvalue �� ��� ������ �ִ�.
//			=> ��� �޴� �ٴ� ���� "�ش� �Լ��� ����" �Ҽ� �ִٴ� �ǹ�
// 
// ���ڷ� lvalue(n) �� ������ : T = int&,  T&& = int&,   f4(int& ) �Լ�����
// ���ڷ� rvalue(3) �� ������ : T = int ,  T&& = int&&,  f4(int&& )�Լ�����

// => ������ �Լ��� "call by value" �� �ƴ� "call by reference"


// int&  : lvalue reference
// int&& : rvalue reference
// T&    : lvalue reference 
// T&&   : "rvalue reference" �ƴմϴ�. lvalue, rvalue ��� ������ 
//									   �ֽ��ϴ�.

// C++11 ��â�⿡ T&& �� ���� �̸��� �������ϴ�
// �׷���, "effective-modern c++" å���� �Ʒ� �̸��� �����մϴ�.
// => "universal reference"

// ������, ���� ǥ������ȸ������
// => "forwarding reference" ��� �̸��� ����ϱ�� ����. 
// => ������ �ַ� "perfect forwarding" �� ���Ǳ� ������!!


template<typename T> void f4(T&& a)
{
}
int main()
{
	int n = 3;

	f4(n);	// T = int&,   T&& = int& &&     f4(int& a)
	f4(3);	// T = int     T&& = int&&       f4(int&&)
}

