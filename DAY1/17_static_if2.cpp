// 17_static_if - 51 page

// 아래 코드는 에러일까요 ? 아닐까요 ?
template<typename T> void foo(T a)
{
	// if : 실행시간 제어문
	//		컴파일 시간에 조건식이 false 라도.
	//		"템플릿 인스턴스화에는 포함된다."
	if (false)
		*a = 10;
}
int main()
{
	foo(0); 
}

