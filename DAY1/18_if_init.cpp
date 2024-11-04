// 18_if_init    50 page

int foo() { return 100; }

int main()
{
	int ret = foo();
	if (ret == 0)
	{
	}

	// 위코드는 C++17 부터 아래 처럼해도 됩니다.
	// 새로운 if 문 : if (초기화코드;조건식)
	if (int ret2 = foo(); ret2 == 0)
	{

	} // <== ret2 파괴

	// switch 도 가능
	switch (int n = foo(); n)
	{

	}

	// 초기화 구문을 가진 if 문 
	// => init if 라고 합니다.
}
