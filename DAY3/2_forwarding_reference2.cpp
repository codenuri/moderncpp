// 사전지식
// reference collapsing - 91 page

int main()
{
	int n = 10;


	int *p = &n;
	int* *pp = &p;

	int& r = n;
	int& &rr = r;


	using LREF = int&; 
	using RREF = int&&;

	// reference collapsing
	LREF& r3 = ? ;
	RREF& r4 = ? ;
	LREF&& r5 = ? ;
	RREF&& r6 = ?;
}

template<typename T> void foo(T a)
{
	T& r = a;
}





