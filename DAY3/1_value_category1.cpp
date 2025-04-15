// rvalue - 87 page
int x = 0;
int  foo() { return x;}
int& goo() { return x;}



// lvalue : 등호의 왼쪽에 올수 있는 표현식(오른쪽도 가능)
//			이름을 가진다.
//			여러문장에서 사용가능.
//			주소연산자로 주소를 구할수 있다.
//			참조를 반환하는 함수
// 
// rvalue : 등호의 왼쪽에 올수 없는 표현식(오른쪽만 가능)
//			이름이 없다.
//			단일식에서만 사용가능
//			주소를 구할수 없다.
//			값을 반환하는 함수, literal, 임시객체	
// 	
int main()
{
	int v1 = 0, v2 = 0;
	
	v1 = 10;	// ok.    v1 : lvalue ( left value )
	10 = v1;	// error  10 : rvalue ( right value )
	v2 = v1;

	int* p1 = &v1;
	int* p2 = &10; 

	foo() = 10;	// error.  "0 = 10"
	goo() = 10; // ok	   "x별명 = 10"


	const int c = 0;

	c = 20;  // error..   c 는 lvalue ? rvalue ?
			// 이름이 있고, 주소도 구할수 있다.
			// "immutable" lvalue 이다.

	// 모든 rvalue 는 "상수" 이다 ?? O/X 
	Point{ 0,0 }.x = 10; // error. 이지만 임시객체가 상수는 아니다
						// 상수라서 에러가 아니라
						// rvalue 라서 왼쪽에 올수 없는것. 

	Point{ 0,0 }.set(1, 1); // 멤버 함수를 통해서는 변경가능하다.
}








