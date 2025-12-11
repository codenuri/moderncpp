
int& foo(int& r) { return r; }


template<typename F, typename T>
//auto chronometry(F f, T&& arg)	// return 문장의 결과가 int& 인 경우 int 로 결정, 즉, 참조 제거
//auto chronometry(F f, T&& arg) -> decltype(f(std::forward<T>(arg))) // ok
decltype(auto) chronometry(F f, T&& arg)  // ok.  위와 동일
{
	return f(std::forward<T>(arg));
}

int main()
{
	int n = 3;

	chronometry(foo, n); // foo(n)
}