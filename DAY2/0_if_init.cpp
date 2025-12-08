// 0_if_init    50 page

int foo() { return 100; }

int main()
{
	int ret = foo();

	if (ret == 0)
	{
	}

	// 위 코드는 C++17 부터 아래 처럼 사용가능합니다.
	// if ( 초기화구문; 조건문 )
	if (int ret2 = foo(); ret2 == 0)
	{

	} // <== ret2 파괴

	// switch 도 가능합니다
	switch (int n = foo(); n)
	{
	case 0: break;
	case 1: break;
	}

	// while 도 될까요 ?
	// => 없습니다. 기존 for 문으로 충분합니다.
	/*
	while (int idx = 0; idx < 10)
	{
		++idx;
	}
	*/
	// C++17 부터 
	// => if, switch 에 초기화 구문을 추가할수 있게 되었습니다
	// => 생각보다 편리합니다. 자주 사용하세요.. 
	/*
	if (Rect* r = dynamic_cast<Rect*>(s); r != nullptr)
	{

	}
	else  if (Circle* c = dynamic_cast<Circle*>(s); c != nullptr)
	{
	}
	*/
}



