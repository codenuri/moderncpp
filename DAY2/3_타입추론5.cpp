#include <iostream>

// 정리!!

// 규칙 #1. 인자가 값 타입일때
// => 인자가 가진 "const, volatile, reference" 를 제거한후 T 의 타입 결정
template<typename T> void foo(T a)
{
	
}
// 규칙 #2. 인자가 참조 타입일때
// => 인자의 "reference" 만 제거하고 타입 결정
// => const, volatile 은 유지

template<typename T> void goo(T& a)
{
}

// 규칙 3. 인자가 T&& 일때 
// => lvalue, rvalue 를 알아야 합니다.
// => 내일 자세히 
template<typename T> void goo(T&& a)
{
}



int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	foo(n);  // T : int
	foo(c);  // T : int
	foo(r);  // T : int 
	foo(cr); // T : int

	goo(n);  // T : int          a : int&
	goo(c);  // T : const int    a : const int&
	goo(r);  // T : int          a : int&
	goo(cr); // T : const int    a : const int&
}


// ��Ģ 3. ���ڰ� rvalue reference �϶�
// => perfect forwarding ���ǿ��� ����
template<typename T> void goo(T&& a)
{
}
