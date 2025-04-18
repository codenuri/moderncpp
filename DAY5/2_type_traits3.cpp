#include <iostream>
#include <type_traits>

// ���� ���𹮿��� ���� �̸��� ���� �ϸ� "Ÿ��" �� ���� �˴ϴ�.
/*
int    n;	// �����̸� : n		Ÿ�� : int
double d;	// �����̸� : d      Ÿ�� : double
void foo(int); // �Լ��̸� : foo	  Ÿ�� :void(int)
int x[3];	// ���� �̸� : x		Ÿ�� : int[3]
		
int[3]; // int     3�� ũ�� �迭
T[3];   // ����Ÿ�� 3�� ũ�� �迭
T[N];   // ����Ÿ�� ��� ũ�� �迭

//T[];// ũ�⸦ �˼� ���� �迭(unknown size array) 
	  // C���� Ư���� ��� �Լ����ڵ�� ��� ( C �Ŵ��� ����)
*/



template<typename T> struct is_array
{
	static constexpr bool value = false;
};

template<typename T, int N> struct is_array< T[N] >
{
	static constexpr bool value = true;
};


template<typename T> void foo(T& a)
{
	// is_array ����� ������
	if ( is_array<T>::value ) 
		std::cout << "�迭" << std::endl;
	else
		std::cout << "�迭 �ƴ�" << std::endl;
}
int main()
{
	int arr[3] = { 1,2,3 };
	foo(arr);
}