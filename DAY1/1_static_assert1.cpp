// 7 page
#include <cassert>

// assert : 실행시간 값의 유효성 확인.
//			실패하면 실행시간 오류 발생

// static_assert : 컴파일 시간 표현식의 유효성 확인
//				   실패하면 컴파일 에러!!
// => static_assert 안에 놓이는 조건식은 반드시 컴파일 할때
//	  조사 가능해야 합니다
//    변수 사용할수 없습니다.
static_assert(sizeof(int*) >= 8, "error, use 64 bit");
//static_assert(age > 0 , "error, use 64 bit"); // 이 표현은 안됨
						// "변수 age" 는 사용 할수 없음

void foo(int age)
{
	// 함수 인자는 사용하기 전에
	// 유효성을 확인하는 것이 좋습니다.
//	assert(age > 0);

	int* p = new int[age];

	delete[] p;
}

int main()
{
//	foo(-10);
	foo(10);
}