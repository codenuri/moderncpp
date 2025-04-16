// 91 page
int main()
{
	int n = 10;


	int *p = &n;
	int* *pp = &p;	// 이중 포인터
					// 포인터의 포인터를 만들수 있습니다.

	int& r = n;
	int& &rr = r;	// error
					// 레퍼런스의 레퍼런스는 만들수 없습니다.

	// 하지만, 별명이나 타입 추론의 과정에서 나오는
	// 레퍼런스의 레퍼런스는 에러가 아닙니다.
	// => 아래 규칙대로 해석됩니다. 

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

foo<int&>(n); // 위 코드에서 r의 타입은 ?



