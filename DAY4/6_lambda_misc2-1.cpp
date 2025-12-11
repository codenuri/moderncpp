// C++14 부터 람다표현식 인자로 auto 사용가능합니다.

// 일반 함수 인자도 auto 될까요 ?

void foo(auto n)
{
}

int main()
{
	foo(3);
	foo(3.4);
}