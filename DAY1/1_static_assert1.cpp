#include <iostream>

// static_assert : 7 page

// static_assert(조건, 메세지)
// => 조건을 만족하지 않으면 컴파일을 멈추고, 메세지를 출력해 달라

// 주의 : "조건"은 반드시 컴파일 시간에 확인 가능해야 합니다.
//        변수 사용 못함. 

// 함수 안에 있어도 되고, 함수 밖에 있어도 됩니다.

// C assert : 실행시간 조사, 
//            기계어 코드 있음. 하지만 release 에서는 "해당 코드가 제거"
//			  => 대부분 조건부 컴파일을 위해서 매크로로 구현

// static_assert : 컴파일 시간 조사(static)
//			  기계어 코드 없음
//		      단지, 컴파일러에게 요청한것

static_assert(sizeof(int*) == 8, "error not 64bit");

int main()
{
	// 64bit 환경에서만 동작가능한 코드
}

// 참고 C assert
/*
#ifdef _DEBUG
#define assert(x)  if ( x != false) { .....; abort(); };

#else 
#define assert(x)
#endif
*/