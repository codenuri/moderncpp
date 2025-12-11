#include <functional>

int main()
{
	std::function<int(int, int)> f;

	{
		int n = 0;

		f = [&n](int a) { return a + n; };

	} //<= n ÆÄ±«µÊ.

	f(10); // ¹ö±×.. dangling reference ¹ß»ı
	
}