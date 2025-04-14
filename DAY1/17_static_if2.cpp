// 17_static_if - 51 page

// 아래 코드는 에러가 있을까요 ?
template<typename T> void foo(T a)
{
	// if : 실행시간 제어문
	//      아래 처럼 false 로 결정되어도 실행은 안되지만
	//		"템플릿 => 실제 함수생성" 시에는 포함됩니다.
	//		int 타입을 *a = 10 할수 없으므로 컴파일 에러
//	if (false)
//		*a = 10;

	// 컴파일 시간 if 문
	// => 조건이 false 라면 실제 함수에 포함시키지 말라.
	if  constexpr (false)
		*a = 10;


}
int main()
{
	foo(0); 
}

