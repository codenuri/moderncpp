#include <iostream>

// �� ������ "specialization" ���� ����!!

template<typename T, typename U> struct Object
{
	static void foo() { std::cout << "T, U" << std::endl; }
};

template<typename T, typename U> struct Object<T*, U*>
{
	static void foo() { std::cout << "T*, U*" << std::endl; }
};

template<typename T, typename U> struct Object<T*, U>
{
	static void foo() { std::cout << "T*, U" << std::endl; }
};

// �ٽ� 
// => primary template �� ���ڰ� 2�� ��
// => �κ� Ư��ȭ �Ҷ� ������ ������ �޶� ���� �ֽ��ϴ�
// => ������ "�κ� Ư��ȭ ǥ��("Object<T, T>") ���� 2���� �ؾ� �մϴ�.

template<typename T> struct Object<T, T>
{
	static void foo() { std::cout << "T, T" << std::endl; }
};

// �Ʒ��� ����
// "partial specialization" �� �ƴ϶� "specialization" �Դϴ�.
// template ���ڰ� ����� �մϴ�.
template<> struct Object<int, short>
{
	static void foo() { std::cout << "int, short" << std::endl; }
};


template<typename T, typename U, typename V> struct Object<T, Object<U, V> >
{
	static void foo() { std::cout << "T, Object<U, V>" << std::endl; }
};

int main()
{
	// �Ʒ� ó�� ������ ����� ������.
	Object<int,  double >::foo();// T, U
	Object<int*, double*>::foo();// T*, U*
	Object<int*, double> ::foo();// T*, U
	Object<int,  int>::foo();    // T, T
	Object<int, short>::foo();   // int, short

	// �Ʒ� ó�� ������ �غ�����
	Object<double, Object<short, char>>::foo();
							// T, Object<U, V>  ������ �غ�����
}

