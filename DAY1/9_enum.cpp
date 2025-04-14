// 9_enum - 32 page

// C/C++98 enum의 문제점
enum COLOR { red = 1, green, blue};

int main()
{
	// 문제점 #1. int 에 담을수 있다.
	COLOR c1 = COLOR::red;
	int c2 = COLOR::red; // 아주 나쁜 코드
						// 앞으로 c2 는 색상용도로 사용하겠다는 것인데..

//	c1 = 100; // error. 100 은 COLOR 이 아니다!!
	c2 = 100; // c3 를 사용한다는 것은 c2 로 실수.!
			  // 하지만 에러가 아니다!!  위험!
			  // 즉, 색상 변수를 COLOR 이 아닌 int 로 사용한것이 문제


	// 문제점 #2. COLOR 라는 이름 생략 가능. unscoped 가능.
//	int c3 = COLOR::red; // 이렇게 사용하는 것이 원칙 이지만
	int c3 = red;		 // COLOR 가 없어도 된다.

	int red = 100;
	int n = red; // ok. 지역변수 red(100) ..
				 // 위험하고,, 나쁜 코드
}





