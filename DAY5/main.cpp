#include "add.h"

int main()
{
	add(1, 2);

	foo();

	printf("main.  add 주소 : %p\n", &add);
	printf("main.  x 주소 : %p\n", &x);
}

// 인라인 함수의 의미
// 1. 호출시 인라인 치환해 달라.
// 
// 2. multiple definition 을 허용해 달라.
//    여러소스에 같은 이름이 함수가 있어도 된다.
//    실행파일에는 한개만 남게 된다.
//    => 그래서 헤더에 구현을 넣을수 있다.
//    => ODR 예외 (one definition rule )
