// 18_if_init    49 page

int foo() { return 100; }

int main()
{
	// #1. C/C++ 에서 아주 많이 사용하는 전형적인 코드
	int ret = foo();

	if (ret == 0)
	{
	}

	// #2. 위 #1 은 C++17 부터 아래 처럼 사용가능합니다.
	// legacy if :  if ( 조건식 )
	// 새로운 if :  if ( 초기화구문; 조건식 )
	if (int ret1 = foo(); ret1 == 0)
	{

	}	//<== ret1 파괴!! 다음 문장부터는 다시 ret1 선언 가능


	// switch 도 가능합니다.
	switch (int n = foo(); n)
	{
	case 1: break;
	case 2: break;

	}

}