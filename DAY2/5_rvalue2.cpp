// 핵심 : rvalue, lvalue 의 개념은 
//       변수(객체)에 부여되는 개념이 아닌
//       표현식(expression) 에 부여 되는 개념
// 
// statement  : 세미콜론으로 끝나는 한줄의 문장. 실행단위
// expression : 한개의 값을 계산해 내는 코드 집합
// => 표현식이 만든 값은 2개의 속성이 있습니다.
// => 1. type
// => 2. value category( lvalue, rvalue, xvalue, glvalue, prvalue)
// 
// rvalue
// => 표현식의 결과로 임시로 만들어진 값
// => "리터럴, 임시객체도 이 카테고리로 분류"
int main()
{
	int n = 2;

	n * 2 + 3;	// expression "n"  의 값     : 2(int, lvalue)
				// expression "n*2"  의 값   : 4(int, rvalue)
				// expression "n*2+3"  의 값 : 7(int, rvalue)

	int& r1 = n * 2;		// error
	const int& r2 = n * 2;	// ok. 
}
