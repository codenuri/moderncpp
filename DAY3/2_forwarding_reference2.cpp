// 사전지식
// reference collapsing - 91 page

int main()
{
	int n = 10;


	int *p = &n;
	int* *pp = &p; // ok. 포인터의 포인터는 가능합니다.

	int& r = n;
	int& &rr = r;	// error. reference 의 reference 를
					//        "직접 코드로 작성" 할수 없다.

	// 그런데, 타입추론이나, alias 사용시 발생하는 
	// reference 의 reference 는 에러가 아니다. 
	// "reference collapsing" 규칙 사용
	using LREF = int&; 
	using RREF = int&&;

	// reference collapsing
	LREF& r3 = n ;	// int&  &		=> int&
	RREF& r4 = n ;	// int&& &		=> int&
	LREF&& r5 = n;	// int&  &&		=> int&
	RREF&& r6 = 3;	// int&& &&		=> int&&
}

template<typename T> void foo(T a)
{
	T& r = a;	// int& & r = a
				// int& r = a;
}
foo<int&>(n); // T= int&




