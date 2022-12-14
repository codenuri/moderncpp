// 17_static_if - 51 page

template<typename T> void foo(T a)
{
	// if : 실행시간 조건문
	//      컴파일때 조건식이 false 가 되어도
	//		if 문의 문장은 "템플릿 인스턴스화에 포함" 됩니다.
	//if (false)
	//	*a = 10;

	// if constexpr : 컴파일 시간 조건문 ( C++17)
	//				  조건식이 false 라면
	//				  if 문의 문장은 "템플릿 => C++ 함수"를 만들때
	//				  제외 됩니다.
	if constexpr (false)
		*a = 10;
}

int main()
{
	foo(0); 
}

void goo(int n)
{
//	if constexpr (n > 0) // error. 조건식은 만드시 컴파일 할때
//	{					// 알아야 합니다.
//	}
	int n = 0;
	if constexpr (sizeof(int*) >= 8)
	{
		x = 21;
		std::cout << "64bit" << std::endl;
	}
	else
	{
		x = 2;
		std::cout << "not 64bit" << std::endl;
	}
}
