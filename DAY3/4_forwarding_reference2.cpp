// 91 page

// fowarding reference 을 이해하기 위한 사전 지식

int main()
{
	int n = 10;


	int *p = &n;
	int* *pp = &p;	// ok. 포인터의 포인터를 만들수 있습니다.

	// 레퍼런스 : 기존변수의 별명(alias)을 만드는 것
	int& r = n;
	int& &rr = r;	// error. 별명의 별명을 만들수 없다.

	// 규칙 : reference 의 reference 를 코드로 직접 작성할수없다.
	
	// 단, C++11 부터 아래의 경우는 reference 의 reference 허용
	// 1. using 이나 typedef
	// 2. auto, decltype, template   등의 타입 추론에서

	using LREF = int&; 
	using RREF = int&&;

	// reference collapsing
	// => reference 의 reference 를 해석하는 규칙
	// => & 는 항상 && 보다 강하다. 항상 & 선택
	// => lvalue 는 지속되는 수명을 가진다. 
	// => lvalue 를 rvalue reference로 별명을 만들게 되면 move 발생
	//    예상치 못하게 자원손실

	LREF& r3 = n ;	// int&  &		=> int&
	RREF& r4 = n ;	// int&& &		=> int&
	LREF&& r5 = n;	// int&  &&		=> int&
	RREF&& r6 = 3;	// int&& &&		=> int&&
}

template<typename T> void foo(T a)
{
	T& r = a; // int& & => int&
			  // int& r = a;
}
foo<int&>(n);





