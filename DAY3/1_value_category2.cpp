// 핵심 : rvalue, lvalue 의 개념은 
//       변수(객체)에 부여되는 개념이 아닌
//       표현식(expression) 에 부여 되는 개념
// 
// statememtn(문장)   : 세미콜론으로 끝나는 한줄의 코드
//						프로그램의 실행 단위.
//						모든 프로그램은 main 함수의 1번째 "문장" 부터 차례대로 실행된다.
// 
// expression(표현식) : 한개의 값을 나타내는 코드 집합
// result : expression 이 만든 값
// result 는 2개의 속성이 있습니다.
// => type
// => value category : 등호의 왼쪽에 올수 있는가(lvalue, rvalue )

int main()
{
	int n = 2;

					//					 result    type   
	n * 2 + 3 - 2;	// expression "n" :		2(n)	int		lvalue
					// expression "n*2" :	4		int		rvalue
					// expression "n*2+3" : 7		int		rvalue
					// expression "n*2+3-2" : 5		int		rvalue

	n = 2;			// ok.  n 이라는 표현식은 lvalue expressin
	n * 2 = 10;		// error. n * 2 라는 표현식은 rvalue expression

	n = 3;
	++n = 10;		// ++n 이라는 표현식은
					// result : "n(4)"	
					// type : int,   
					// value category : lvalue

	n = 3;
	n++; // n 을 증가하고 이전값인 3반환
		 // "n++" 최종결과는 증가되기 이전값인 3
		// type : int
		// value category : rvalue



}