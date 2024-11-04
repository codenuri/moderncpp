int main()
{
	int n = 10;

	// 다음중 에러는 ?
	const int c1 = 10; // ok
	const int c2 = n;  // ok

	constexpr int c3 = 10; // ok
	constexpr int c4 = n;  // error

}